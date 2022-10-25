// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dcadsp.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (float C4, float (*output)[4], float **input, float C3, int i,
    ptrdiff_t len, float SW0, float SW1, float SW3, float SW2, ptrdiff_t ofs,
    float C1, float C2)
{
  for (i = 0; i < len; i++)
    {
      float *src = input[i] + ofs;
      float a = src[-4] * SW0 - src[-1] * SW3;
      float b = src[-3] * SW1 - src[-2] * SW2;
      float c = src[2] * SW1 + src[1] * SW2;
      float d = src[3] * SW0 + src[0] * SW3;
      output[i][0] = C1 * b - C2 * c + C4 * a - C3 * d;
      output[i][1] = C1 * d - C2 * a - C4 * b - C3 * c;
      output[i][2] = C3 * b + C2 * d - C4 * c + C1 * a;
      output[i][3] = C3 * a - C2 * b + C4 * d - C1 * c;
}}
