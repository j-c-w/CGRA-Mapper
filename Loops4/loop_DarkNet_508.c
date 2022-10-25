// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/utils.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *avg, int n, int i, int els)
{
  for (i = 0; i < els; ++i)
    {
      avg[i] /= n;
    }
}
