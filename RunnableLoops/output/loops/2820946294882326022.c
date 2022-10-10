#include <stdint.h>
#include <stdio.h>






int
fn (int i, const float *data, float c, float *work, float g)
{
  for (i = 0; i < 40; i++)
    {
      g += work[i] * work[i];
      c += data[i] * work[i];
    }
}
