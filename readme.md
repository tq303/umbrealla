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

  - [0] umbrella
  - [1] animation
  - [2] speed
  - [3] red
  - [4] green
  - [5] blue
