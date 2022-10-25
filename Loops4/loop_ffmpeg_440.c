// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_dctdnoiz.c

#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, int src_stridea, int i, int dst_strideb, float *dst,
    int src_strideb, int add, int dst_stridea)
{
  for (i = 0; i < 8; i++)
    {
      const float x00 = 1.4142135623731f * src[0 * src_stridea];
      const float x01 =
	1.38703984532215f * src[1 * src_stridea] +
	0.275899379282943f * src[7 * src_stridea];
      const float x02 =
	1.30656296487638f * src[2 * src_stridea] +
	0.541196100146197f * src[6 * src_stridea];
      const float x03 =
	1.17587560241936f * src[3 * src_stridea] +
	0.785694958387102f * src[5 * src_stridea];
      const float x04 = 1.4142135623731f * src[4 * src_stridea];
      const float x05 =
	-0.785694958387102f * src[3 * src_stridea] +
	1.17587560241936f * src[5 * src_stridea];
      const float x06 =
	0.541196100146197f * src[2 * src_stridea] -
	1.30656296487638f * src[6 * src_stridea];
      const float x07 =
	-0.275899379282943f * src[1 * src_stridea] +
	1.38703984532215f * src[7 * src_stridea];
      const float x09 = x00 + x04;
      const float x0a = x01 + x03;
      const float x0b = 1.4142135623731f * x02;
      const float x0c = x00 - x04;
      const float x0d = x01 - x03;
      const float x0e = 0.353553390593274f * (x09 - x0b);
      const float x0f = 0.353553390593274f * (x0c + x0d);
      const float x10 = 0.353553390593274f * (x0c - x0d);
      const float x11 = 1.4142135623731f * x06;
      const float x12 = x05 + x07;
      const float x13 = x05 - x07;
      const float x14 = 0.353553390593274f * (x11 + x12);
      const float x15 = 0.353553390593274f * (x11 - x12);
      const float x16 = 0.5f * x13;
      dst[0 * dst_stridea] =
	(add ? dst[0 * dst_stridea] : 0) + 0.25f * (x09 + x0b) +
	0.353553390593274f * x0a;
      dst[1 * dst_stridea] =
	(add ? dst[1 * dst_stridea] : 0) + 0.707106781186547f * (x0f + x15);
      dst[2 * dst_stridea] =
	(add ? dst[2 * dst_stridea] : 0) + 0.707106781186547f * (x0f - x15);
      dst[3 * dst_stridea] =
	(add ? dst[3 * dst_stridea] : 0) + 0.707106781186547f * (x0e + x16);
      dst[4 * dst_stridea] =
	(add ? dst[4 * dst_stridea] : 0) + 0.707106781186547f * (x0e - x16);
      dst[5 * dst_stridea] =
	(add ? dst[5 * dst_stridea] : 0) + 0.707106781186547f * (x10 - x14);
      dst[6 * dst_stridea] =
	(add ? dst[6 * dst_stridea] : 0) + 0.707106781186547f * (x10 + x14);
      dst[7 * dst_stridea] =
	(add ? dst[7 * dst_stridea] : 0) + 0.25f * (x09 + x0b) -
	0.353553390593274f * x0a;
      dst += dst_strideb;
      src += src_strideb;
}}
