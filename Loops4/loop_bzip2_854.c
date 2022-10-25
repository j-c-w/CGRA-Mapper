// Source is: /home/alex/.local/share/compy-Learn/1.0/bzip2/content/huffman.c

#include <stdint.h>
#include <stdio.h>




typedef int Int32;

int
fn (Int32 maxLen, Int32 * limit, Int32 * base, Int32 minLen, Int32 i,
    Int32 vec)
{
  for (i = minLen; i <= maxLen; i++)
    {
      vec += (base[i + 1] - base[i]);
      limit[i] = vec - 1;
      vec <<= 1;
    }
}
