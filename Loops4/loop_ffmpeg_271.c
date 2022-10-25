// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/utils.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t ** outFilter, int dstW, int *outFilterSize, int i)
{
  for (i = 0; i < *outFilterSize; i++)
    {
      int k = (dstW - 1) * (*outFilterSize) + i;
      (*outFilter)[k + 1 * (*outFilterSize)] =
	(*outFilter)[k + 2 * (*outFilterSize)] =
	(*outFilter)[k + 3 * (*outFilterSize)] = (*outFilter)[k];
}}
