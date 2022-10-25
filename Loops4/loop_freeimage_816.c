// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/utils/huffman_encode_utils.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t code, int i, uint32_t next_code[16], int depth_count[16])
{
  for (i = 1; i <= 15; ++i)
    {
      code = (code + depth_count[i - 1]) << 1;
      next_code[i] = code;
    }
}
