// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegaudiodec_common.c

#include <stdint.h>
#include <stdio.h>






int
fn (const int ff_mpa_quant_bits[17], int16_t * const ff_division_tabs[4],
    const int ff_mpa_quant_steps[17])
{
  int i = 0;
  for (int j = 0; j < (1 << (-ff_mpa_quant_bits[i] + 1)); j++)
    {
      int val1, val2, val3, steps;
      int val = j;
      steps = ff_mpa_quant_steps[i];
      val1 = val % steps;
      val /= steps;
      val2 = val % steps;
      val3 = val / steps;
      ff_division_tabs[i][j] = val1 + (val2 << 4) + (val3 << 8);
}}
