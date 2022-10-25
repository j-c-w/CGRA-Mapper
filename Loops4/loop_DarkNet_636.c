// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/utils.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float sigma, float *a, int n, float mu)
{
  for (i = 0; i < n; ++i)
    {
      a[i] = (a[i] - mu) / sigma;
    }
}
