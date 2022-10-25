// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegaudiodsp_float.c

#include <stdint.h>
#include <stdio.h>






int
fn (float t3, float *in, float *tmp1, float *in1, float tmp[18], float t2,
    float t0, int j, float t1)
{
  for (j = 0; j < 2; j++)
    {
      tmp1 = tmp + j;
      in1 = in + j;
      t2 = in1[2 * 4] + in1[2 * 8] - in1[2 * 2];
      t3 = in1[2 * 0] + ((in1[2 * 6]) * (1.0f / (1 << (1))));
      t1 = in1[2 * 0] - in1[2 * 6];
      tmp1[6] = t1 - ((t2) * (1.0f / (1 << (1))));
      tmp1[16] = t1 + t2;
      t0 =
	((2) * (((float) (0.93969262078590838405 / 2))) *
	 (in1[2 * 2] + in1[2 * 4]));
      t1 =
	((1) * (-2 * ((float) (0.17364817766693034885 / 2))) *
	 (in1[2 * 4] - in1[2 * 8]));
      t2 =
	((2) * (-((float) (0.76604444311897803520 / 2))) *
	 (in1[2 * 2] + in1[2 * 8]));
      tmp1[10] = t3 - t0 - t2;
      tmp1[2] = t3 + t0 + t1;
      tmp1[14] = t3 + t2 - t1;
      tmp1[4] =
	((2) * (-((float) (0.86602540378443864676 / 2))) *
	 (in1[2 * 5] + in1[2 * 7] - in1[2 * 1]));
      t2 =
	((2) * (((float) (0.98480775301220805936 / 2))) *
	 (in1[2 * 1] + in1[2 * 5]));
      t3 =
	((1) * (-2 * ((float) (0.34202014332566873304 / 2))) *
	 (in1[2 * 5] - in1[2 * 7]));
      t0 = ((2) * (((float) (0.86602540378443864676 / 2))) * (in1[2 * 3]));
      t1 =
	((2) * (-((float) (0.64278760968653932632 / 2))) *
	 (in1[2 * 1] + in1[2 * 7]));
      tmp1[0] = t2 + t3 + t0;
      tmp1[12] = t2 + t1 - t0;
      tmp1[8] = t3 - t1 - t0;
}}
