# Direction Detection

Have a two element array. Do full scan with Kinnect and ascertain the close z position. From this position store the x position in the first array element, delay the scan and do the same again except store within the second array element position. From these two number you will be able to detect which direction the closest target was moving and can then animate the umbrellas accordingly.

# Serial Utilization

Send arrays each separated by the categories relevant character e.g. `u,s,c,x` the `.` character indicates end of array, `,` indicates variable end and `;` indicates end of transmission. This means that the protocol can be expanded in the future.The arrays will be split into the following.

- umbrella
- animation
- speed
- colour
    - RGB
- direction `d`
    - type
- utility `x`
    - kill (flag to indicate animations should stop)
    - loop count
- offset `0`
    - 1 x `el[0]` x `el[2]` etc

### Example

`1.5.100.255,255,255`
