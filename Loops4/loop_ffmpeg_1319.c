// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/evrcdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *samples, const float *filter_coeffs, int i, float *memory, int j)
{
  for (j = 10 - 1; j > 0; j--)
    {
      samples[i] -= filter_coeffs[j] * memory[j];
      memory[j] = memory[j - 1];
    }
}
