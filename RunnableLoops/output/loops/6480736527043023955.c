#include <stdint.h>
#include <stdio.h>






int
fn (float out3, float out2, float out1, float out0, int i, float old_out1,
    int filter_length, float val, float *out, const float *filter_coeffs,
    float old_out2, float old_out0, float old_out3)
{
  for (i = 5; i < filter_length; i += 2)
    {
      old_out3 = out[-i];
      val = filter_coeffs[i - 1];
      out0 -= val * old_out3;
      out1 -= val * old_out0;
      out2 -= val * old_out1;
      out3 -= val * old_out2;
      old_out2 = out[-i - 1];
      val = filter_coeffs[i];
      out0 -= val * old_out2;
      out1 -= val * old_out3;
      out2 -= val * old_out0;
      out3 -= val * old_out1;
      do
	{
	  float SWAP_tmp = old_out2;
	  old_out2 = old_out0;
	  old_out0 = SWAP_tmp;
	}
      while (0);
      old_out1 = old_out3;
    }
}
