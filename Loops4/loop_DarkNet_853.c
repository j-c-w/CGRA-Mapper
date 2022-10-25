// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/utils.c

#include <stdint.h>
#include <stdio.h>






int
fn (int *inds, int i, int max, int min)
{
  for (i = min; i < max; ++i)
    {
      inds[i] = i;
    }
}
