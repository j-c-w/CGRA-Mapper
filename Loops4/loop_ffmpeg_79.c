// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacenc_tns.c

#include <stdint.h>
#include <stdio.h>






int
fn (int swb_size, int w2, int i, const float *scaled)
{
  float maxval = 0.0f;
  for (i = 0; i < swb_size; i++)
    {
      maxval =
	((maxval) >
	 (scaled[w2 * 128 + i]) ? (maxval) : (scaled[w2 * 128 + i]));
    }
}
