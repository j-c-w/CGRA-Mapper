#include <stdint.h>
#include <stdio.h>






int
fn (int i, int w2, int swb_size, const float *scaled)
{
  float maxval = 0.0f;
  for (i = 0; i < swb_size; i++)
    {
      maxval =
	((maxval) >
	 (scaled[w2 * 128 + i]) ? (maxval) : (scaled[w2 * 128 + i]));
    }
}
