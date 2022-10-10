#include <stdint.h>
#include <stdio.h>




typedef float FFTSample;

int
fn (int n, int k, int n4, FFTSample * output, int n2)
{
  for (k = 0; k < n4; k++)
    {
      output[k] = -output[n2 - k - 1];
      output[n - k - 1] = output[n2 + k];
    }
}
