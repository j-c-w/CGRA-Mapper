#include <stdint.h>
#include <stdio.h>






int
fn (float p, float w, float *lsp, int j, float q)
{
  for (j = 1; j < 10; j += 2)
    {
      q *= w - lsp[j - 1];
      p *= w - lsp[j];
    }
}
