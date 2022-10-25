// Source is: /home/alex/.local/share/compy-Learn/1.0/bzip2/content/blocksort.c

#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned char UChar;
typedef unsigned short UInt16;
typedef unsigned int UInt32;

int
fn (UInt16 s, UInt32 * ftab, UInt32 * ptr, Int32 i, Int32 j, UChar * block)
{
  for (; i >= 3; i -= 4)
    {
      s = (s >> 8) | (block[i] << 8);
      j = ftab[s] - 1;
      ftab[s] = j;
      ptr[j] = i;
      s = (s >> 8) | (block[i - 1] << 8);
      j = ftab[s] - 1;
      ftab[s] = j;
      ptr[j] = i - 1;
      s = (s >> 8) | (block[i - 2] << 8);
      j = ftab[s] - 1;
      ftab[s] = j;
      ptr[j] = i - 2;
      s = (s >> 8) | (block[i - 3] << 8);
      j = ftab[s] - 1;
      ftab[s] = j;
      ptr[j] = i - 3;
    }
}
