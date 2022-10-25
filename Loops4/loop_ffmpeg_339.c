// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/bink.c

#include <stdint.h>
#include <stdio.h>






int
fn (int mode_list[128], int coef_list[128], int i, int ccoef, int list_end)
{
  for (i = 0; i < 3; i++)
    {
      ccoef += 4;
      coef_list[list_end] = ccoef;
      mode_list[list_end++] = 2;
    }
}
