// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_arnndn.c

#include <stdint.h>
#include <stdio.h>






int
fn (float mem1, float num4, float mem4, float num2, float mem2, float mem0,
    float num0, float num3, const float *x, float mem3, float *y, int N,
    float num1)
{
  for (int i = 0; i < N; i++)
    {
      float sum = x[i];
      sum += (num0 * mem0);
      sum += (num1 * mem1);
      sum += (num2 * mem2);
      sum += (num3 * mem3);
      sum += (num4 * mem4);
      mem4 = mem3;
      mem3 = mem2;
      mem2 = mem1;
      mem1 = mem0;
      mem0 = x[i];
      y[i] = sum;
}}
