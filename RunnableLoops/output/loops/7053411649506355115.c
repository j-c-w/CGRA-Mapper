#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int index, uint8_t * line, int w)
{
  for (index = w - 3; index > 0; index--)
    {
      line[index] =
	(line[index / 3] + line[(index + 1) / 3] + line[(index + 2) / 3] +
	 1) / 3;
    }
}
