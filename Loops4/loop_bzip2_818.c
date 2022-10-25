// Source is: /home/alex/.local/share/compy-Learn/1.0/bzip2/content/huffman.c

#include <stdint.h>
#include <stdio.h>




typedef int Int32;

int
fn (Int32 i, Int32 j, Int32 weight[516], Int32 alphaSize)
{
  for (i = 1; i <= alphaSize; i++)
    {
      j = weight[i] >> 8;
      j = 1 + (j / 2);
      weight[i] = j << 8;
    }
}
