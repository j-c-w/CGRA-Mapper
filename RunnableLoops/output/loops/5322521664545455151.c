#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int HEAD, int i, uint8_t * buf, int L)
{
  for (i = 0; i < HEAD; i++)
    {
      L += buf[i];
      buf[i] = L;
    }
}
