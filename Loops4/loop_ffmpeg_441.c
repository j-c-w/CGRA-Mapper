// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_dctdnoiz.c

#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, int src_stridea, int i, int dst_strideb, float *dst,
    int src_strideb, int dst_stridea)
{
  for (i = 0; i < 8; i++)
    {
      const float x00 = src[0 * src_stridea] + src[7 * src_stridea];
      const float x01 = src[1 * src_stridea] + src[6 * src_stridea];
      const float x02 = src[2 * src_stridea] + src[5 * src_stridea];
      const float x03 = src[3 * src_stridea] + src[4 * src_stridea];
      const float x04 = src[0 * src_stridea] - src[7 * src_stridea];
      const float x05 = src[1 * src_stridea] - src[6 * src_stridea];
      const float x06 = src[2 * src_stridea] - src[5 * src_stridea];
      const float x07 = src[3 * src_stridea] - src[4 * src_stridea];
      const float x08 = x00 + x03;
      const float x09 = x01 + x02;
      const float x0a = x00 - x03;
      const float x0b = x01 - x02;
      const float x0c = 1.38703984532215f * x04 + 0.275899379282943f * x07;
      const float x0d = 1.17587560241936f * x05 + 0.785694958387102f * x06;
      const float x0e = -0.785694958387102f * x05 + 1.17587560241936f * x06;
      const float x0f = 0.275899379282943f * x04 - 1.38703984532215f * x07;
      const float x10 = 0.353553390593274f * (x0c - x0d);
      const float x11 = 0.353553390593274f * (x0e - x0f);
      dst[0 * dst_stridea] = 0.353553390593274f * (x08 + x09);
      dst[1 * dst_stridea] = 0.353553390593274f * (x0c + x0d);
      dst[2 * dst_stridea] =
	0.461939766255643f * x0a + 0.191341716182545f * x0b;
      dst[3 * dst_stridea] = 0.707106781186547f * (x10 - x11);
      dst[4 * dst_stridea] = 0.353553390593274f * (x08 - x09);
      dst[5 * dst_stridea] = 0.707106781186547f * (x10 + x11);
      dst[6 * dst_stridea] =
	0.191341716182545f * x0a - 0.461939766255643f * x0b;
      dst[7 * dst_stridea] = 0.353553390593274f * (x0e + x0f);
      dst += dst_strideb;
      src += src_strideb;
}}
