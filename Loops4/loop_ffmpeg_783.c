// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_superequalizer.c

#include <stdint.h>
#include <stdio.h>




typedef struct EqParameter
{
  float lower, upper, gain;
} EqParameter;

int
fn (float *bc, int i, float fs, EqParameter * param, const float bands[17])
{
  for (i = 0; i <= 17; i++)
    {
      param[i].lower = i == 0 ? 0 : bands[i - 1];
      param[i].upper = i == 17 ? fs : bands[i];
      param[i].gain = bc[i];
    }
}
