// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegaudiodec_float.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *ptr, int n, int i, const float csa_table[8][4])
{
  for (i = n; i > 0; i--)
    {
      do
	{
	  float tmp0 = ptr[-1 - 0];
	  float tmp1 = ptr[0];
	  ptr[-1 - 0] = tmp0 * csa_table[0][0] - tmp1 * csa_table[0][1];
	  ptr[0] = tmp0 * csa_table[0][1] + tmp1 * csa_table[0][0];
	}
      while (0);
      do
	{
	  float tmp0 = ptr[-1 - 1];
	  float tmp1 = ptr[1];
	  ptr[-1 - 1] = tmp0 * csa_table[1][0] - tmp1 * csa_table[1][1];
	  ptr[1] = tmp0 * csa_table[1][1] + tmp1 * csa_table[1][0];
	}
      while (0);
      do
	{
	  float tmp0 = ptr[-1 - 2];
	  float tmp1 = ptr[2];
	  ptr[-1 - 2] = tmp0 * csa_table[2][0] - tmp1 * csa_table[2][1];
	  ptr[2] = tmp0 * csa_table[2][1] + tmp1 * csa_table[2][0];
	}
      while (0);
      do
	{
	  float tmp0 = ptr[-1 - 3];
	  float tmp1 = ptr[3];
	  ptr[-1 - 3] = tmp0 * csa_table[3][0] - tmp1 * csa_table[3][1];
	  ptr[3] = tmp0 * csa_table[3][1] + tmp1 * csa_table[3][0];
	}
      while (0);
      do
	{
	  float tmp0 = ptr[-1 - 4];
	  float tmp1 = ptr[4];
	  ptr[-1 - 4] = tmp0 * csa_table[4][0] - tmp1 * csa_table[4][1];
	  ptr[4] = tmp0 * csa_table[4][1] + tmp1 * csa_table[4][0];
	}
      while (0);
      do
	{
	  float tmp0 = ptr[-1 - 5];
	  float tmp1 = ptr[5];
	  ptr[-1 - 5] = tmp0 * csa_table[5][0] - tmp1 * csa_table[5][1];
	  ptr[5] = tmp0 * csa_table[5][1] + tmp1 * csa_table[5][0];
	}
      while (0);
      do
	{
	  float tmp0 = ptr[-1 - 6];
	  float tmp1 = ptr[6];
	  ptr[-1 - 6] = tmp0 * csa_table[6][0] - tmp1 * csa_table[6][1];
	  ptr[6] = tmp0 * csa_table[6][1] + tmp1 * csa_table[6][0];
	}
      while (0);
      do
	{
	  float tmp0 = ptr[-1 - 7];
	  float tmp1 = ptr[7];
	  ptr[-1 - 7] = tmp0 * csa_table[7][0] - tmp1 * csa_table[7][1];
	  ptr[7] = tmp0 * csa_table[7][1] + tmp1 * csa_table[7][0];
	}
      while (0);
      ptr += 18;
    }
}
