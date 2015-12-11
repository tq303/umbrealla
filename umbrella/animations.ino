void animateDown () {
  for(uint16_t i=0; i < 30; i++) {
    strip.styleAll(i, strip.Colour(255,255,255));
    strip.showAll();
    delay(30);
  }

  for(uint16_t i=0; i < 30; i++) {
    strip.styleAll(i, strip.Colour(0,0,0));
    strip.showAll();
    delay(30);
  }

  delay(200);
}

void animatePulsate (int speed) {

    for (uint8_t j = 0; j < 100; j++) {
      for (int p = 0; p < 30; p++) {
        strip.styleAll(p, strip.Colour(j, j, j));
      }
      strip.showAll();
      delay(speed);
    }

    for (uint8_t j = 100; j > 0; j--) {
      for (int p = 0; p < 30; p++) {
        strip.styleAll(p, strip.Colour(j, j, j));
      }
      strip.showAll();
      delay(speed);
    }

}

uint8_t currentProxPos = 0;
bool isAsc = true;

void animatePulsateProximity () {

  long duration;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(5);
  digitalWrite(12, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(13, INPUT);
  duration = pulseIn(13, HIGH);

  if (currentProxPos < 100 && isAsc) {
    currentProxPos++;
    if (currentProxPos == 100) {
      isAsc = false;
    }
  } else {
    currentProxPos--;
    if (currentProxPos == 0) {
      isAsc = true;
    }
  }

  for (int p = 0; p < 30; p++) {
    strip.styleAll(p, strip.Colour(currentProxPos, currentProxPos, currentProxPos));
  }
  strip.showAll();
  delayMicroseconds(duration);

  Serial.println(duration);
}

void animateRotate () {

  delay(1000);

  for (int i = 0; i < 8; i++) {
    for (int p = 0; p < 30; p++) {
      strip.style(i, p, strip.Colour(1, 187, 200));
    }
    strip.show(i);
    delay(100);
  }

  for (int i = 0; i < 8; i++) {
    for (int p = 0; p < 30; p++) {
      strip.style(i, p, strip.Colour(0,0,0));
    }
    strip.show(i);
    delay(100);
  }

}
