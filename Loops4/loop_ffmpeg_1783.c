// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/opus_pvq.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t N, int i, const uint32_t * const ff_celt_pvq_u_row[15],
    const int *y, int idx)
{
  int sum = 0;
  for (i = N - 1; i >= 0; i--)
    {
      const uint32_t i_s =
	(ff_celt_pvq_u_row
	 [((N - i) >
	   (sum + ((y[i]) >= 0 ? (y[i]) : (-(y[i]))) + 1) ? (sum +
							     ((y[i]) >=
							      0 ? (y[i])
							      : (-(y[i]))) +
							     1) : (N -
								   i))][((N -
									  i) >
									 (sum
									  +
									  ((y
									    [i])
									   >=
									   0
									   ?
									   (y
									    [i])
									   :
									   (-
									    (y
									     [i])))
									  +
									  1)
									 ? (N
									    -
									    i)
									 :
									 (sum
									  +
									  ((y
									    [i])
									   >=
									   0
									   ?
									   (y
									    [i])
									   :
									   (-
									    (y
									     [i])))
									  +
									  1))]);
      idx +=
	(ff_celt_pvq_u_row[((N - i) > (sum) ? (sum) : (N - i))]
	 [((N - i) > (sum) ? (N - i) : (sum))]) + (y[i] < 0) * i_s;
      sum += ((y[i]) >= 0 ? (y[i]) : (-(y[i])));
}}
