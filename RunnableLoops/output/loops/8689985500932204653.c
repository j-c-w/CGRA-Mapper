#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned char *encoded, uint8_t * v_out, uint8_t * y_out,
    unsigned int width, uint8_t * u_out, int col)
{
  for (col = 0; col < width; col++)
    {
      y_out[col] = *encoded++;
      u_out[col] = *encoded++ + 128;
      v_out[col] = *encoded++ + 128;
    }
}
