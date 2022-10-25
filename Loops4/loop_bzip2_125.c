// Source is: /home/alex/.local/share/compy-Learn/1.0/bzip2/content/blocksort.c

#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned char UChar;
typedef unsigned int UInt32;
typedef unsigned short UInt16;

int
fn (UInt16 * quadrant, UInt32 * ftab, Int32 i, Int32 j, UChar * block)
{
  for (; i >= 0; i--)
    {
      quadrant[i] = 0;
      j = (j >> 8) | (((UInt16) block[i]) << 8);
      ftab[j]++;
    }
}
