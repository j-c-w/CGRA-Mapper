// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/sipr16k.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, const float qu[2], float isp_q[16], float *lsf_history,
    float *isp_new, int ma_pred, const float mean_lsf_16k[16])
{
  for (i = 0; i < 16; i++)
    {
      isp_new[i] =
	(1 - qu[ma_pred]) * isp_q[i] + qu[ma_pred] * lsf_history[i] +
	mean_lsf_16k[i];
    }
}
