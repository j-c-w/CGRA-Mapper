#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *samples, int j, const float *filter_coeffs, float *memory)
{
  for (j = 10 - 1; j > 0; j--)
    {
      samples[i] -= filter_coeffs[j] * memory[j];
      memory[j] = memory[j - 1];
    }
}
