// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_dctdnoiz.c

#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, int src_stridea, int i, int dst_strideb, float *dst,
    int src_strideb, int add, int dst_stridea)
{
  for (i = 0; i < 16; i++)
    {
      const float x00 = 1.4142135623731f * src[0 * src_stridea];
      const float x01 =
	1.40740373752638f * src[1 * src_stridea] +
	0.138617169199091f * src[15 * src_stridea];
      const float x02 =
	1.38703984532215f * src[2 * src_stridea] +
	0.275899379282943f * src[14 * src_stridea];
      const float x03 =
	1.35331800117435f * src[3 * src_stridea] +
	0.410524527522357f * src[13 * src_stridea];
      const float x04 =
	1.30656296487638f * src[4 * src_stridea] +
	0.541196100146197f * src[12 * src_stridea];
      const float x05 =
	1.24722501298667f * src[5 * src_stridea] +
	0.666655658477747f * src[11 * src_stridea];
      const float x06 =
	1.17587560241936f * src[6 * src_stridea] +
	0.785694958387102f * src[10 * src_stridea];
      const float x07 =
	1.09320186700176f * src[7 * src_stridea] +
	0.897167586342636f * src[9 * src_stridea];
      const float x08 = 1.4142135623731f * src[8 * src_stridea];
      const float x09 =
	-0.897167586342636f * src[7 * src_stridea] +
	1.09320186700176f * src[9 * src_stridea];
      const float x0a =
	0.785694958387102f * src[6 * src_stridea] -
	1.17587560241936f * src[10 * src_stridea];
      const float x0b =
	-0.666655658477747f * src[5 * src_stridea] +
	1.24722501298667f * src[11 * src_stridea];
      const float x0c =
	0.541196100146197f * src[4 * src_stridea] -
	1.30656296487638f * src[12 * src_stridea];
      const float x0d =
	-0.410524527522357f * src[3 * src_stridea] +
	1.35331800117435f * src[13 * src_stridea];
      const float x0e =
	0.275899379282943f * src[2 * src_stridea] -
	1.38703984532215f * src[14 * src_stridea];
      const float x0f =
	-0.138617169199091f * src[1 * src_stridea] +
	1.40740373752638f * src[15 * src_stridea];
      const float x12 = x00 + x08;
      const float x13 = x01 + x07;
      const float x14 = x02 + x06;
      const float x15 = x03 + x05;
      const float x16 = 1.4142135623731f * x04;
      const float x17 = x00 - x08;
      const float x18 = x01 - x07;
      const float x19 = x02 - x06;
      const float x1a = x03 - x05;
      const float x1d = x12 + x16;
      const float x1e = x13 + x15;
      const float x1f = 1.4142135623731f * x14;
      const float x20 = x12 - x16;
      const float x21 = x13 - x15;
      const float x22 = 0.25f * (x1d - x1f);
      const float x23 = 0.25f * (x20 + x21);
      const float x24 = 0.25f * (x20 - x21);
      const float x25 = 1.4142135623731f * x17;
      const float x26 = 1.30656296487638f * x18 + 0.541196100146197f * x1a;
      const float x27 = 1.4142135623731f * x19;
      const float x28 = -0.541196100146197f * x18 + 1.30656296487638f * x1a;
      const float x29 = 0.176776695296637f * (x25 + x27) + 0.25f * x26;
      const float x2a = 0.25f * (x25 - x27);
      const float x2b = 0.176776695296637f * (x25 + x27) - 0.25f * x26;
      const float x2c = 0.353553390593274f * x28;
      const float x1b = 0.707106781186547f * (x2a - x2c);
      const float x1c = 0.707106781186547f * (x2a + x2c);
      const float x2d = 1.4142135623731f * x0c;
      const float x2e = x0b + x0d;
      const float x2f = x0a + x0e;
      const float x30 = x09 + x0f;
      const float x31 = x09 - x0f;
      const float x32 = x0a - x0e;
      const float x33 = x0b - x0d;
      const float x37 = 1.4142135623731f * x2d;
      const float x38 = 1.30656296487638f * x2e + 0.541196100146197f * x30;
      const float x39 = 1.4142135623731f * x2f;
      const float x3a = -0.541196100146197f * x2e + 1.30656296487638f * x30;
      const float x3b = 0.176776695296637f * (x37 + x39) + 0.25f * x38;
      const float x3c = 0.25f * (x37 - x39);
      const float x3d = 0.176776695296637f * (x37 + x39) - 0.25f * x38;
      const float x3e = 0.353553390593274f * x3a;
      const float x34 = 0.707106781186547f * (x3c - x3e);
      const float x35 = 0.707106781186547f * (x3c + x3e);
      const float x3f = 1.4142135623731f * x32;
      const float x40 = x31 + x33;
      const float x41 = x31 - x33;
      const float x42 = 0.25f * (x3f + x40);
      const float x43 = 0.25f * (x3f - x40);
      const float x44 = 0.353553390593274f * x41;
      dst[0 * dst_stridea] =
	(add ? dst[0 * dst_stridea] : 0) + 0.176776695296637f * (x1d + x1f) +
	0.25f * x1e;
      dst[1 * dst_stridea] =
	(add ? dst[1 * dst_stridea] : 0) + 0.707106781186547f * (x29 + x3d);
      dst[2 * dst_stridea] =
	(add ? dst[2 * dst_stridea] : 0) + 0.707106781186547f * (x29 - x3d);
      dst[3 * dst_stridea] =
	(add ? dst[3 * dst_stridea] : 0) + 0.707106781186547f * (x23 - x43);
      dst[4 * dst_stridea] =
	(add ? dst[4 * dst_stridea] : 0) + 0.707106781186547f * (x23 + x43);
      dst[5 * dst_stridea] =
	(add ? dst[5 * dst_stridea] : 0) + 0.707106781186547f * (x1b - x35);
      dst[6 * dst_stridea] =
	(add ? dst[6 * dst_stridea] : 0) + 0.707106781186547f * (x1b + x35);
      dst[7 * dst_stridea] =
	(add ? dst[7 * dst_stridea] : 0) + 0.707106781186547f * (x22 + x44);
      dst[8 * dst_stridea] =
	(add ? dst[8 * dst_stridea] : 0) + 0.707106781186547f * (x22 - x44);
      dst[9 * dst_stridea] =
	(add ? dst[9 * dst_stridea] : 0) + 0.707106781186547f * (x1c + x34);
      dst[10 * dst_stridea] =
	(add ? dst[10 * dst_stridea] : 0) + 0.707106781186547f * (x1c - x34);
      dst[11 * dst_stridea] =
	(add ? dst[11 * dst_stridea] : 0) + 0.707106781186547f * (x24 + x42);
      dst[12 * dst_stridea] =
	(add ? dst[12 * dst_stridea] : 0) + 0.707106781186547f * (x24 - x42);
      dst[13 * dst_stridea] =
	(add ? dst[13 * dst_stridea] : 0) + 0.707106781186547f * (x2b - x3b);
      dst[14 * dst_stridea] =
	(add ? dst[14 * dst_stridea] : 0) + 0.707106781186547f * (x2b + x3b);
      dst[15 * dst_stridea] =
	(add ? dst[15 * dst_stridea] : 0) + 0.176776695296637f * (x1d + x1f) -
	0.25f * x1e;
      dst += dst_strideb;
      src += src_strideb;
}}
