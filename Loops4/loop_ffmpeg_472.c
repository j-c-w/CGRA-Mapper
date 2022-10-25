// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264_metadata_bsf.c

#include <stdint.h>
#include <stdio.h>






int
fn (double scale_y, int i, double scale_x, double dmatrix[9])
{
  for (i = 0; i < 9; i += 3)
    {
      dmatrix[i] /= scale_x;
      dmatrix[i + 1] /= scale_y;
    }
}
