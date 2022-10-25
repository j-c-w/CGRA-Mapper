// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/utils/huffman_encode_utils.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int i, uint32_t count, uint32_t * const counts, uint32_t k,
    uint32_t stride)
{
  for (k = 0; k < stride; ++k)
    {
      counts[i - k - 1] = count;
    }
}
