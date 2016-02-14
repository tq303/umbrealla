# Umbrella

An interactive animated LED umbrella.

# Dependencies
Requires Adafruit NeoPixel library.

## nRF24L01
#### Pin layout

|Signal|PIN|Colour|Arduino Pin|
|------|---|------|-----------|
|GND   |1  |white |GND        |
|VCC   |2  |red   |3.3v       |
|CE    |3  |green |9          |
|CSN   |4  |blue  |10         |
|SCK   |5  |grey  |13         |
|MOSI  |6  |yellow|11         |
|MISO  |7  |purple|12         |

# Serial Utilization

passes a uniform array with each index containing the following items.

| Variable             | Position |
|----------------------|----------|
|FORMAT_UMBRELLA_POS   | 0        |
|FORMAT_ANIMATION_POS  | 1        |
|FORMAT_SPEED_POS      | 2        |
|FORMAT_RED_POS        | 3        |
|FORMAT_BLUE_POS       | 4        |
|FORMAT_GREEN_POS      | 5        |
