// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/convolutional_layer.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, int n, float *binary, float *input)
{
  for (i = 0; i < n; ++i)
    {
      binary[i] = (input[i] > 0) ? 1 : -1;
    }
}
