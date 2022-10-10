#include <stdint.h>
#include <stdio.h>






int
fn (int x, int by, int new_channels, float *output, const float *input,
    int x_linesize, int bx, int ch, int by_linesize)
{
  for (ch = 0; ch < new_channels; ++ch)
    {
      output[by * by_linesize + x * x_linesize + bx * new_channels + ch] =
	input[ch];
    }
}
