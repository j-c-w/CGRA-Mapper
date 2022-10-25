// Source is: /home/alex/.local/share/compy-Learn/1.0/bzip2/content/blocksort.c

#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned char UChar;
typedef unsigned int UInt32;

int
fn (Int32 ftabCopy[256], UInt32 * fmap, Int32 i, Int32 j, UChar * eclass8,
    Int32 nblock)
{
  for (i = 0; i < nblock; i++)
    {
      while (ftabCopy[j] == 0)
	j++;
      ftabCopy[j]--;
      eclass8[fmap[i]] = (UChar) j;
    }
}
