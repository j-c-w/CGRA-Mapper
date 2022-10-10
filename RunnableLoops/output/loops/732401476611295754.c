#include <stdint.h>
#include <stdio.h>






int
fn (const int m_max, int B, int A, int m, float *out, float *in)
{
  for (m = 0; m + 1 < m_max; m += 2)
    {
      out[2 * m] += in[m] * A;
      out[2 * m + 2] += in[m + 1] * B;
    }
}
