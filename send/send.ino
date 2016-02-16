/*
 * Transmitter
 */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 10

const uint64_t pipe = 0xE8E8F0F0E1LL;

RF24 radio(CE_PIN, CSN_PIN);
int sendArray[2];

void setup()
{
  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(pipe);
}


void loop()
{

  sendArray[0] = 0;
  sendArray[1] = 1024;

  radio.write( sendArray, sizeof(sendArray) );

}
