// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/convolutional_layer.c

#include <stdint.h>
#include <stdio.h>






int
fn (float mean, int i, float *input, int size, int n, int s, float *binary)
{
  for (i = 0; i < n; ++i)
    {
      binary[i * size + s] = (input[i * size + s] > 0) ? mean : -mean;
    }
}
