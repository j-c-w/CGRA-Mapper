// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_arnndn.c

#include <stdint.h>
#include <stdio.h>






int
fn (float ac[5])
{
  for (int i = 1; i <= 4; i++)
    {
      ac[i] -= ac[i] * (.008f * i) * (.008f * i);
}}
