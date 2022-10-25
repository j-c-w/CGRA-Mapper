// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/convolutional_layer.c

#include <stdint.h>
#include <stdio.h>






int
fn (float mean, int i, int size, float *weights, int f, float *binary)
{
  for (i = 0; i < size; ++i)
    {
      binary[f * size + i] = (weights[f * size + i] > 0) ? mean : -mean;
    }
}
