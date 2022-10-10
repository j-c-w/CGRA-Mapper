#include <stdint.h>
#include <stdio.h>






int
fn (int taps, float *ns_errors, const float *ns_coeffs, int j, int pos,
    double d)
{
  for (j = 0; j < taps - 2; j += 4)
    {
      d -=
	ns_coeffs[j] * ns_errors[pos + j] + ns_coeffs[j + 1] * ns_errors[pos +
									 j +
									 1] +
	ns_coeffs[j + 2] * ns_errors[pos + j + 2] + ns_coeffs[j +
							      3] *
	ns_errors[pos + j + 3];
    }
}
