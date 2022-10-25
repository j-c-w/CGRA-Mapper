// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/imc.c

#include <stdint.h>
#include <stdio.h>






int
fn (double freq, int j, double freqmid[32])
{
  for (j = 31; j > 0 && freq <= freqmid[j]; j--);
}
