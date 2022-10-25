// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/enc/predictor_enc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const int kPredLowEffort, int i, const int tiles_per_col,
    const int tiles_per_row, uint32_t * const image)
{
  for (i = 0; i < tiles_per_row * tiles_per_col; ++i)
    {
      image[i] = 0xff000000 | (kPredLowEffort << 8);
    }
}
