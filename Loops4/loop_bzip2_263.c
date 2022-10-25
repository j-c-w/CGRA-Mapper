// Source is: /home/alex/.local/share/compy-Learn/1.0/bzip2/content/blocksort.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned short UInt16;
typedef int Int32;
typedef unsigned char UChar;

int
fn (UChar * block, UInt16 * quadrant, Int32 i, Int32 nblock)
{
  for (i = 0; i < (2 + 12 + 18 + 2); i++)
    {
      block[nblock + i] = block[i];
      quadrant[nblock + i] = 0;
    }
}
