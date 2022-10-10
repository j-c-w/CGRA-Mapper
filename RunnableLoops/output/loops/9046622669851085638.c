#include <stdint.h>
#include <stdio.h>






int
fn (int chrDstH, int *lumFilterPos, int *chrFilterPos, int dstH,
    int *out_chr_size, int chrSubSample, int lumFilterSize, int lumY,
    int *out_lum_size, int chrFilterSize)
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
