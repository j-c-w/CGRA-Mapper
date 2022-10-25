// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g723_1dec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int64_t int64_t;

int
fn (int in_shift, int i, int filter_signal[250], int m, int n, int16_t * buf,
    int16_t filter_coef[2][10], int64_t filter)
{
  for (n = 1; n <= 10; n++)
    {
      filter -=
	(filter_coef[0])[n - 1] * (buf + i)[m - n] - (filter_coef[1])[n -
								      1] *
	((filter_signal + i)[m - n] >> in_shift);
    }
}
