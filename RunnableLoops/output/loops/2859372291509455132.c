#include <stdint.h>
#include <stdio.h>






int
fn (int j, float sum, float *memory, const float *coef)
{
  for (j = 10 - 1; j > 0; j--)
    {
      sum += coef[j] * memory[j];
      memory[j] = memory[j - 1];
    }
}
