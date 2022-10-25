// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/truemotion2.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, int *U, int *V, unsigned int *Uo, unsigned int *Vo)
{
  for (i = 0; i < 2; i++)
    {
      U[i] = Uo[i];
      V[i] = Vo[i];
    }
}
