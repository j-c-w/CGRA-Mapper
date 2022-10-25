// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_arnndn.c

#include <stdint.h>
#include <stdio.h>






int
fn (float lpc[4])
{
  float tmp = 1.0f;
  for (int i = 0; i < 4; i++)
    {
      tmp = .9f * tmp;
      lpc[i] = (lpc[i] * tmp);
}}
