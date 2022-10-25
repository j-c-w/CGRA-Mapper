// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vp3dsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (int *bounding_values, int filter_limit, int value, int x)
{
  for (x = value = filter_limit; x < 128 && value; x++, value--)
    {
      bounding_values[x] = value;
      bounding_values[-x] = -value;
    }
}
