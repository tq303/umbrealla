# Direction Detection

Have a two element array. Do full scan with Kinnect and ascertain the close z position. From this position store the x position in the first array element, delay the scan and do the same again except store within the second array element position. From these two number you will be able to detect which direction the closest target was moving and can then animate the umbrellas accordingly.

# Serial Utilization

Send 4 arrays each separated by `/n` character. This means that the protocol can be expanded in the future.The arrays will be split into the following.

- umbrellas
    - 0 means off
- speed
    - 1 x `el[0]` x `el[2]` etc
- colour
    - RGB
- utility
    - kill (flag to indicate animations should stop)
    - loop count
    - direction `0,1,2` `left,center,right`
