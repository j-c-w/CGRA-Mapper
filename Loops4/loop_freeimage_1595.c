// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/enc/picture_psnr_enc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long unsigned int size_t;

int
fn (size_t src_stride, int y, const uint8_t * ref, size_t x_step,
    size_t ref_stride, int x, int width, uint8_t * tmp2, const uint8_t * src,
    uint8_t * tmp1)
{
  for (x = 0; x < width; ++x)
    {
      tmp1[x + y * width] = src[x * x_step + y * src_stride];
      tmp2[x + y * width] = ref[x * x_step + y * ref_stride];
    }
}
