// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ac3.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int v, const uint8_t ac3_log_add_tab[260], int16_t * psd, int band_end,
    int bin)
{
  for (; bin < band_end; bin++)
    {
      int max = ((v) > (psd[bin]) ? (v) : (psd[bin]));
      int adr =
	((max - ((v + psd[bin] + 1) >> 1)) >
	 (255) ? (255) : (max - ((v + psd[bin] + 1) >> 1)));
      v = max + ac3_log_add_tab[adr];
}}
