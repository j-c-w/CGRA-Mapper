// Source is: /home/alex/.local/share/compy-Learn/1.0/bzip2/content/blocksort.c

#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned int UInt32;

int
fn (Int32 i, Int32 nblock, UInt32 * bhtab)
{
  for (i = 0; i < 32; i++)
    {
      bhtab[(nblock + 2 * i) >> 5] |= ((UInt32) 1 << ((nblock + 2 * i) & 31));
      bhtab[(nblock + 2 * i + 1) >> 5] &=
	~((UInt32) 1 << ((nblock + 2 * i + 1) & 31));
    }
}
