// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/cook.c

#include <stdint.h>
#include <stdio.h>






int
fn (int vlc, int i, int *subband_coef_index, const int invradix_tab[7],
    const int kmax_tab[7], int tmp, int j, int vd, int category)
{
  for (j = vd - 1; j >= 0; j--)
    {
      tmp = (vlc * invradix_tab[category]) / 0x100000;
      subband_coef_index[vd * i + j] = vlc - tmp * (kmax_tab[category] + 1);
      vlc = tmp;
    }
}
