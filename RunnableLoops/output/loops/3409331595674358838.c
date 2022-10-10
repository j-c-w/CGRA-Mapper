#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, const uint8_t * ptr8, char *keyword)
{
  for (i = 0; i < 8 && ptr8[i] != ' '; i++)
    {
      keyword[i] = ptr8[i];
    }
}
