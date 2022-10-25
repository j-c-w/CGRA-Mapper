// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_waveform.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * c2_data, const uint8_t * c1_data,
    const int d0_signed_linesize, int x, const int c0_shift_w,
    const int slicew_start, const int d1_signed_linesize, uint8_t * const d1,
    const uint8_t * c0_data, const int slicew_end, const int c2_shift_w,
    const int d2_signed_linesize, const int c1_shift_w, uint8_t * const d2,
    uint8_t * const d0)
{
  for (x = slicew_start; x < slicew_end; x++)
    {
      const int c0 = c0_data[x >> c0_shift_w];
      const int c1 = c1_data[x >> c1_shift_w];
      const int c2 = c2_data[x >> c2_shift_w];
      *(d0 + d0_signed_linesize * c0 + x) = c0;
      *(d1 + d1_signed_linesize * c0 + x) = c1;
      *(d2 + d2_signed_linesize * c0 + x) = c2;
}}
