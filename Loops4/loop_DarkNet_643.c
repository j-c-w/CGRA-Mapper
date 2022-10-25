// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/utils.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *a, int n, float sum, int i)
{
  for (i = 0; i < n; ++i)
    {
      sum += a[i] * a[i];
    }
}
