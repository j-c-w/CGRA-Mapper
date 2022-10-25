// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/convolutional_layer.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *biases, int j, int i, int size, float *output, int b, int n)
{
  for (j = 0; j < size; ++j)
    {
      output[(b * n + i) * size + j] += biases[i];
    }
}
