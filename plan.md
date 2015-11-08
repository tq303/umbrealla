umbrella class
  # default pin start 1
  # default quantity is 8
  # default led count 30
  constructor
    quantity
    pin start
    led count

set
  # used to customize each strip
  int strip
  int pin

style
  # changes a strips led configuration
  # on change the strips number is stored for final loop update of that strip
  int strip
  int led
  int colour

styleAll
  # changes style of all strips by looping above {style} function
  int led
  int colour

show
  # runs Neo_Pixel.show function
  int strip

showAll
  # loops above function {show}

begin
  # runs Neo_Pixel.begin function
  int strip

beginAll
    # loops above function {begin}
