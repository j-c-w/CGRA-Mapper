// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/ZLib/crc32.c

#include <stdint.h>
#include <stdio.h>






int
fn (int n, unsigned long odd[32], unsigned long row)
{
  for (n = 1; n < 32; n++)
    {
      odd[n] = row;
      row <<= 1;
    }
}
