// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegaudiodec_common.c

#include <stdint.h>
#include <stdio.h>






int
fn (uint16_t ff_band_index_long[9][23],
    const uint8_t ff_band_size_long[9][22])
{
  int k = 0;
  int i = 0;
  for (int j = 0; j < 22; j++)
    {
      ff_band_index_long[i][j] = k;
      k += ff_band_size_long[i][j] >> 1;
}}
