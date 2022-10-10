#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, char *value, const uint8_t * ptr8)
{
  for (; i < 80 && ptr8[i] != '\''; i++)
    {
      *value++ = ptr8[i];
    }
}
