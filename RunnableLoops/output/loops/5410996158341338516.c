#include <stdint.h>
#include <stdio.h>






int
fn (int j, int order, float *lsp, float two_cos_w)
{
  float q = 0.5f;
  float p = 0.5f;
  for (j = 0; j + 1 < order; j += 2)
    {
      q *= lsp[j] - two_cos_w;
      p *= lsp[j + 1] - two_cos_w;
    }
}
