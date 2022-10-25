// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/dnn/dnn_backend_native_layer_depth2space.c

#include <stdint.h>
#include <stdio.h>






int
fn (const float *input, int x, int ch, int by_linesize, int new_channels,
    int x_linesize, float *output, int bx, int by)
{
  for (ch = 0; ch < new_channels; ++ch)
    {
      output[by * by_linesize + x * x_linesize + bx * new_channels + ch] =
	input[ch];
    }
}
