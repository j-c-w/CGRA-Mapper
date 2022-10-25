// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswresample/dither.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *ns_errors, double d, int taps, int pos, const float *ns_coeffs,
    int j)
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
