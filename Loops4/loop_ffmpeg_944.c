// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavutil/tx_int32.c

#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexInt32
{
  int32_t re, im;
} AVComplexInt32;
typedef int32_t TXSample;
typedef AVComplexInt32 TXComplex;

int
fn (TXSample t3, const TXSample * wim, TXComplex * z, TXSample t6,
    TXSample t4, TXSample t5, const TXSample * cos, TXSample r1, int o3,
    int o1, TXSample t1, TXSample t2, int len, TXSample i0, int o2,
    TXSample r0, TXSample i1)
{
  for (int i = 0; i < len; i += 4)
    {
      do
	{
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[0]) * (z[o2 + 0].re);
	      (accu) -= (int64_t) (-wim[7]) * (z[o2 + 0].im);
	      (t1) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (-wim[7]) * (z[o2 + 0].re);
	      (accu) += (int64_t) (cos[0]) * (z[o2 + 0].im);
	      (t2) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[0]) * (z[o3 + 0].re);
	      (accu) -= (int64_t) (wim[7]) * (z[o3 + 0].im);
	      (t5) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (wim[7]) * (z[o3 + 0].re);
	      (accu) += (int64_t) (cos[0]) * (z[o3 + 0].im);
	      (t6) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      r0 = z[0].re;
	      i0 = z[0].im;
	      r1 = z[o1 + 0].re;
	      i1 = z[o1 + 0].im;
	      do
		{
		  t3 = (t5) - (t1);
		  t5 = (t5) + (t1);
		}
	      while (0);
	      do
		{
		  z[o2 + 0].re = (r0) - (t5);
		  z[0].re = (r0) + (t5);
		}
	      while (0);
	      do
		{
		  z[o3 + 0].im = (i1) - (t3);
		  z[o1 + 0].im = (i1) + (t3);
		}
	      while (0);
	      do
		{
		  t4 = (t2) - (t6);
		  t6 = (t2) + (t6);
		}
	      while (0);
	      do
		{
		  z[o3 + 0].re = (r1) - (t4);
		  z[o1 + 0].re = (r1) + (t4);
		}
	      while (0);
	      do
		{
		  z[o2 + 0].im = (i0) - (t6);
		  z[0].im = (i0) + (t6);
		}
	      while (0);
	    }
	  while (0);
	}
      while (0);
      do
	{
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[2]) * (z[o2 + 2].re);
	      (accu) -= (int64_t) (-wim[5]) * (z[o2 + 2].im);
	      (t1) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (-wim[5]) * (z[o2 + 2].re);
	      (accu) += (int64_t) (cos[2]) * (z[o2 + 2].im);
	      (t2) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[2]) * (z[o3 + 2].re);
	      (accu) -= (int64_t) (wim[5]) * (z[o3 + 2].im);
	      (t5) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (wim[5]) * (z[o3 + 2].re);
	      (accu) += (int64_t) (cos[2]) * (z[o3 + 2].im);
	      (t6) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      r0 = z[2].re;
	      i0 = z[2].im;
	      r1 = z[o1 + 2].re;
	      i1 = z[o1 + 2].im;
	      do
		{
		  t3 = (t5) - (t1);
		  t5 = (t5) + (t1);
		}
	      while (0);
	      do
		{
		  z[o2 + 2].re = (r0) - (t5);
		  z[2].re = (r0) + (t5);
		}
	      while (0);
	      do
		{
		  z[o3 + 2].im = (i1) - (t3);
		  z[o1 + 2].im = (i1) + (t3);
		}
	      while (0);
	      do
		{
		  t4 = (t2) - (t6);
		  t6 = (t2) + (t6);
		}
	      while (0);
	      do
		{
		  z[o3 + 2].re = (r1) - (t4);
		  z[o1 + 2].re = (r1) + (t4);
		}
	      while (0);
	      do
		{
		  z[o2 + 2].im = (i0) - (t6);
		  z[2].im = (i0) + (t6);
		}
	      while (0);
	    }
	  while (0);
	}
      while (0);
      do
	{
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[4]) * (z[o2 + 4].re);
	      (accu) -= (int64_t) (-wim[3]) * (z[o2 + 4].im);
	      (t1) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (-wim[3]) * (z[o2 + 4].re);
	      (accu) += (int64_t) (cos[4]) * (z[o2 + 4].im);
	      (t2) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[4]) * (z[o3 + 4].re);
	      (accu) -= (int64_t) (wim[3]) * (z[o3 + 4].im);
	      (t5) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (wim[3]) * (z[o3 + 4].re);
	      (accu) += (int64_t) (cos[4]) * (z[o3 + 4].im);
	      (t6) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      r0 = z[4].re;
	      i0 = z[4].im;
	      r1 = z[o1 + 4].re;
	      i1 = z[o1 + 4].im;
	      do
		{
		  t3 = (t5) - (t1);
		  t5 = (t5) + (t1);
		}
	      while (0);
	      do
		{
		  z[o2 + 4].re = (r0) - (t5);
		  z[4].re = (r0) + (t5);
		}
	      while (0);
	      do
		{
		  z[o3 + 4].im = (i1) - (t3);
		  z[o1 + 4].im = (i1) + (t3);
		}
	      while (0);
	      do
		{
		  t4 = (t2) - (t6);
		  t6 = (t2) + (t6);
		}
	      while (0);
	      do
		{
		  z[o3 + 4].re = (r1) - (t4);
		  z[o1 + 4].re = (r1) + (t4);
		}
	      while (0);
	      do
		{
		  z[o2 + 4].im = (i0) - (t6);
		  z[4].im = (i0) + (t6);
		}
	      while (0);
	    }
	  while (0);
	}
      while (0);
      do
	{
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[6]) * (z[o2 + 6].re);
	      (accu) -= (int64_t) (-wim[1]) * (z[o2 + 6].im);
	      (t1) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (-wim[1]) * (z[o2 + 6].re);
	      (accu) += (int64_t) (cos[6]) * (z[o2 + 6].im);
	      (t2) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[6]) * (z[o3 + 6].re);
	      (accu) -= (int64_t) (wim[1]) * (z[o3 + 6].im);
	      (t5) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (wim[1]) * (z[o3 + 6].re);
	      (accu) += (int64_t) (cos[6]) * (z[o3 + 6].im);
	      (t6) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      r0 = z[6].re;
	      i0 = z[6].im;
	      r1 = z[o1 + 6].re;
	      i1 = z[o1 + 6].im;
	      do
		{
		  t3 = (t5) - (t1);
		  t5 = (t5) + (t1);
		}
	      while (0);
	      do
		{
		  z[o2 + 6].re = (r0) - (t5);
		  z[6].re = (r0) + (t5);
		}
	      while (0);
	      do
		{
		  z[o3 + 6].im = (i1) - (t3);
		  z[o1 + 6].im = (i1) + (t3);
		}
	      while (0);
	      do
		{
		  t4 = (t2) - (t6);
		  t6 = (t2) + (t6);
		}
	      while (0);
	      do
		{
		  z[o3 + 6].re = (r1) - (t4);
		  z[o1 + 6].re = (r1) + (t4);
		}
	      while (0);
	      do
		{
		  z[o2 + 6].im = (i0) - (t6);
		  z[6].im = (i0) + (t6);
		}
	      while (0);
	    }
	  while (0);
	}
      while (0);
      do
	{
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[1]) * (z[o2 + 1].re);
	      (accu) -= (int64_t) (-wim[6]) * (z[o2 + 1].im);
	      (t1) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (-wim[6]) * (z[o2 + 1].re);
	      (accu) += (int64_t) (cos[1]) * (z[o2 + 1].im);
	      (t2) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[1]) * (z[o3 + 1].re);
	      (accu) -= (int64_t) (wim[6]) * (z[o3 + 1].im);
	      (t5) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (wim[6]) * (z[o3 + 1].re);
	      (accu) += (int64_t) (cos[1]) * (z[o3 + 1].im);
	      (t6) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      r0 = z[1].re;
	      i0 = z[1].im;
	      r1 = z[o1 + 1].re;
	      i1 = z[o1 + 1].im;
	      do
		{
		  t3 = (t5) - (t1);
		  t5 = (t5) + (t1);
		}
	      while (0);
	      do
		{
		  z[o2 + 1].re = (r0) - (t5);
		  z[1].re = (r0) + (t5);
		}
	      while (0);
	      do
		{
		  z[o3 + 1].im = (i1) - (t3);
		  z[o1 + 1].im = (i1) + (t3);
		}
	      while (0);
	      do
		{
		  t4 = (t2) - (t6);
		  t6 = (t2) + (t6);
		}
	      while (0);
	      do
		{
		  z[o3 + 1].re = (r1) - (t4);
		  z[o1 + 1].re = (r1) + (t4);
		}
	      while (0);
	      do
		{
		  z[o2 + 1].im = (i0) - (t6);
		  z[1].im = (i0) + (t6);
		}
	      while (0);
	    }
	  while (0);
	}
      while (0);
      do
	{
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[3]) * (z[o2 + 3].re);
	      (accu) -= (int64_t) (-wim[4]) * (z[o2 + 3].im);
	      (t1) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (-wim[4]) * (z[o2 + 3].re);
	      (accu) += (int64_t) (cos[3]) * (z[o2 + 3].im);
	      (t2) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[3]) * (z[o3 + 3].re);
	      (accu) -= (int64_t) (wim[4]) * (z[o3 + 3].im);
	      (t5) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (wim[4]) * (z[o3 + 3].re);
	      (accu) += (int64_t) (cos[3]) * (z[o3 + 3].im);
	      (t6) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      r0 = z[3].re;
	      i0 = z[3].im;
	      r1 = z[o1 + 3].re;
	      i1 = z[o1 + 3].im;
	      do
		{
		  t3 = (t5) - (t1);
		  t5 = (t5) + (t1);
		}
	      while (0);
	      do
		{
		  z[o2 + 3].re = (r0) - (t5);
		  z[3].re = (r0) + (t5);
		}
	      while (0);
	      do
		{
		  z[o3 + 3].im = (i1) - (t3);
		  z[o1 + 3].im = (i1) + (t3);
		}
	      while (0);
	      do
		{
		  t4 = (t2) - (t6);
		  t6 = (t2) + (t6);
		}
	      while (0);
	      do
		{
		  z[o3 + 3].re = (r1) - (t4);
		  z[o1 + 3].re = (r1) + (t4);
		}
	      while (0);
	      do
		{
		  z[o2 + 3].im = (i0) - (t6);
		  z[3].im = (i0) + (t6);
		}
	      while (0);
	    }
	  while (0);
	}
      while (0);
      do
	{
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[5]) * (z[o2 + 5].re);
	      (accu) -= (int64_t) (-wim[2]) * (z[o2 + 5].im);
	      (t1) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (-wim[2]) * (z[o2 + 5].re);
	      (accu) += (int64_t) (cos[5]) * (z[o2 + 5].im);
	      (t2) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[5]) * (z[o3 + 5].re);
	      (accu) -= (int64_t) (wim[2]) * (z[o3 + 5].im);
	      (t5) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (wim[2]) * (z[o3 + 5].re);
	      (accu) += (int64_t) (cos[5]) * (z[o3 + 5].im);
	      (t6) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      r0 = z[5].re;
	      i0 = z[5].im;
	      r1 = z[o1 + 5].re;
	      i1 = z[o1 + 5].im;
	      do
		{
		  t3 = (t5) - (t1);
		  t5 = (t5) + (t1);
		}
	      while (0);
	      do
		{
		  z[o2 + 5].re = (r0) - (t5);
		  z[5].re = (r0) + (t5);
		}
	      while (0);
	      do
		{
		  z[o3 + 5].im = (i1) - (t3);
		  z[o1 + 5].im = (i1) + (t3);
		}
	      while (0);
	      do
		{
		  t4 = (t2) - (t6);
		  t6 = (t2) + (t6);
		}
	      while (0);
	      do
		{
		  z[o3 + 5].re = (r1) - (t4);
		  z[o1 + 5].re = (r1) + (t4);
		}
	      while (0);
	      do
		{
		  z[o2 + 5].im = (i0) - (t6);
		  z[5].im = (i0) + (t6);
		}
	      while (0);
	    }
	  while (0);
	}
      while (0);
      do
	{
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[7]) * (z[o2 + 7].re);
	      (accu) -= (int64_t) (-wim[0]) * (z[o2 + 7].im);
	      (t1) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (-wim[0]) * (z[o2 + 7].re);
	      (accu) += (int64_t) (cos[7]) * (z[o2 + 7].im);
	      (t2) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      int64_t accu;
	      (accu) = (int64_t) (cos[7]) * (z[o3 + 7].re);
	      (accu) -= (int64_t) (wim[0]) * (z[o3 + 7].im);
	      (t5) = (int) (((accu) + 0x40000000) >> 31);
	      (accu) = (int64_t) (wim[0]) * (z[o3 + 7].re);
	      (accu) += (int64_t) (cos[7]) * (z[o3 + 7].im);
	      (t6) = (int) (((accu) + 0x40000000) >> 31);
	    }
	  while (0);
	  do
	    {
	      r0 = z[7].re;
	      i0 = z[7].im;
	      r1 = z[o1 + 7].re;
	      i1 = z[o1 + 7].im;
	      do
		{
		  t3 = (t5) - (t1);
		  t5 = (t5) + (t1);
		}
	      while (0);
	      do
		{
		  z[o2 + 7].re = (r0) - (t5);
		  z[7].re = (r0) + (t5);
		}
	      while (0);
	      do
		{
		  z[o3 + 7].im = (i1) - (t3);
		  z[o1 + 7].im = (i1) + (t3);
		}
	      while (0);
	      do
		{
		  t4 = (t2) - (t6);
		  t6 = (t2) + (t6);
		}
	      while (0);
	      do
		{
		  z[o3 + 7].re = (r1) - (t4);
		  z[o1 + 7].re = (r1) + (t4);
		}
	      while (0);
	      do
		{
		  z[o2 + 7].im = (i0) - (t6);
		  z[7].im = (i0) + (t6);
		}
	      while (0);
	    }
	  while (0);
	}
      while (0);
      z += 2 * 4;
      cos += 2 * 4;
      wim -= 2 * 4;
    }
}
