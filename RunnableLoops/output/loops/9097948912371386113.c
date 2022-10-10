#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int i, uint16_t frame_size, uint8_t buf3[4096], const uint8_t * buf2)
{
  for (i = 8; i < frame_size; i += 2)
    {
      buf3[i] = buf2[i + 1];
      buf3[i + 1] = buf2[i];
    }
}
