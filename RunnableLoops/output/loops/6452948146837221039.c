#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int code, int i, char *to)
{
  for (i = 2; i >= 0; i--)
    {
      to[i] = 0x60 + (code & 0x1f);
      code >>= 5;
    }
}
