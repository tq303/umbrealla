### Plan

Outstanding things to do.

- Kinect application
    - Create grid detection application.
    - ~~Integrate new Format module into openframeworks.~~
    - ~~Properly send radio array to arduino~~.
    - ~~Transmit array from arduino to umbrella~~.


- Umbrella application
    - ~~Receive array from transmitter~~.
    - Translate to animation / speed / colour.


- Umbrellas
    - Finish soldering.
    - Replace damaged strips.
    - Fit to umbrellas.

### Transmitter

As the computer needs to control all interactions with the umbrella and keep everything in sync, it now feels logically to send all animation data from the computer to the umbrella using a simple `24fps` animation buffer.

This buffer will be an array of `char` numbers that can be encoded and decoded and relate to each individual LED and provides it's colour.

For example

|LED1|LED2 |LED3|LED4 |
|----|-----|----|-----|
| 0  |255  | 0  |255  |
|off |white|off |white|

This will provide greater control and complete abstraction from the arduinos that can just simply listen for animation instructions.

`30 * 8 * 7 = 1680`

##### 1680 bytes per frame
Of data will need to be transmitted at `24fps` requiring a total speed of `40.32kb/s` transmission speed.
