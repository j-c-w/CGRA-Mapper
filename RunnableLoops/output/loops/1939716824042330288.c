#include <stdint.h>
#include <stdio.h>






int
fn (int i, int j, const float *psy_fir_coeffs, const float *firbuf,
    float sum2, float sum1)
{
  for (j = 0; j < ((21 - 1) / 2) - 1; j += 2)
    {
      sum1 += psy_fir_coeffs[j] * (firbuf[i + j] + firbuf[i + 21 - j]);
      sum2 +=
	psy_fir_coeffs[j + 1] * (firbuf[i + j + 1] + firbuf[i + 21 - j - 1]);
    }
}
