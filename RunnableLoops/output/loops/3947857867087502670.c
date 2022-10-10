#include <stdint.h>
#include <stdio.h>






int
fn (double *buffer2, const double *lp, const double *hp, int buff_idx,
    int filter_length, int buffer_length, double *buffer, int shift)
{
  double sum = 0.0;
  for (int j = 0; j < (filter_length - shift + 1) / 2; j++)
    {
      const int idx = ((-j + buff_idx - 1) & ((buffer_length) - 1));
      sum +=
	buffer[idx] * lp[j * 2 + shift] + buffer2[idx] * hp[j * 2 + shift];
}}
