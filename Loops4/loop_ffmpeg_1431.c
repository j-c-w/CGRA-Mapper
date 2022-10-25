// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/slice.c

#include <stdint.h>
#include <stdio.h>






int
fn (int lumY, int *out_chr_size, int *out_lum_size, int chrSubSample,
    int chrDstH, int *chrFilterPos, int *lumFilterPos, int dstH,
    int lumFilterSize, int chrFilterSize)
{
  for (lumY = 0; lumY < dstH; lumY++)
    {
      int chrY = (int64_t) lumY * chrDstH / dstH;
      int nextSlice =
	((lumFilterPos[lumY] + lumFilterSize - 1) >
	 (((chrFilterPos[chrY] + chrFilterSize -
	    1) << chrSubSample)) ? (lumFilterPos[lumY] + lumFilterSize -
				    1)
	 : (((chrFilterPos[chrY] + chrFilterSize - 1) << chrSubSample)));
      nextSlice >>= chrSubSample;
      nextSlice <<= chrSubSample;
      (*out_lum_size) =
	(((*out_lum_size)) >
	 (nextSlice - lumFilterPos[lumY]) ? ((*out_lum_size)) : (nextSlice -
								 lumFilterPos
								 [lumY]));
      (*out_chr_size) =
	(((*out_chr_size)) >
	 ((nextSlice >> chrSubSample) -
	  chrFilterPos[chrY]) ? ((*out_chr_size)) : ((nextSlice >>
						      chrSubSample) -
						     chrFilterPos[chrY]));
}}
