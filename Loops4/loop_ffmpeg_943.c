// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavutil/tx_float.c

#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexFloat
{
  float re, im;
} AVComplexFloat;
typedef float TXSample;
typedef AVComplexFloat TXComplex;

int
fn (TXSample t3, const TXSample * wim, TXComplex * z, TXSample t6,
    TXSample t4, TXSample t5, const TXSample * cos, TXSample t1, int o3,
    TXSample r1, int o1, TXSample t2, int len, TXSample i0, int o2,
    TXSample r0, TXSample i1)
{
  for (int i = 0; i < len; i += 4)
    {
      do
	{
	  do
	    {
	      (t1) = (z[o2 + 0].re) * (cos[0]) - (z[o2 + 0].im) * (-wim[7]);
	      (t2) = (z[o2 + 0].re) * (-wim[7]) + (z[o2 + 0].im) * (cos[0]);
	    }
	  while (0);
	  do
	    {
	      (t5) = (z[o3 + 0].re) * (cos[0]) - (z[o3 + 0].im) * (wim[7]);
	      (t6) = (z[o3 + 0].re) * (wim[7]) + (z[o3 + 0].im) * (cos[0]);
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
	      (t1) = (z[o2 + 2].re) * (cos[2]) - (z[o2 + 2].im) * (-wim[5]);
	      (t2) = (z[o2 + 2].re) * (-wim[5]) + (z[o2 + 2].im) * (cos[2]);
	    }
	  while (0);
	  do
	    {
	      (t5) = (z[o3 + 2].re) * (cos[2]) - (z[o3 + 2].im) * (wim[5]);
	      (t6) = (z[o3 + 2].re) * (wim[5]) + (z[o3 + 2].im) * (cos[2]);
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
	      (t1) = (z[o2 + 4].re) * (cos[4]) - (z[o2 + 4].im) * (-wim[3]);
	      (t2) = (z[o2 + 4].re) * (-wim[3]) + (z[o2 + 4].im) * (cos[4]);
	    }
	  while (0);
	  do
	    {
	      (t5) = (z[o3 + 4].re) * (cos[4]) - (z[o3 + 4].im) * (wim[3]);
	      (t6) = (z[o3 + 4].re) * (wim[3]) + (z[o3 + 4].im) * (cos[4]);
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
	      (t1) = (z[o2 + 6].re) * (cos[6]) - (z[o2 + 6].im) * (-wim[1]);
	      (t2) = (z[o2 + 6].re) * (-wim[1]) + (z[o2 + 6].im) * (cos[6]);
	    }
	  while (0);
	  do
	    {
	      (t5) = (z[o3 + 6].re) * (cos[6]) - (z[o3 + 6].im) * (wim[1]);
	      (t6) = (z[o3 + 6].re) * (wim[1]) + (z[o3 + 6].im) * (cos[6]);
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
	      (t1) = (z[o2 + 1].re) * (cos[1]) - (z[o2 + 1].im) * (-wim[6]);
	      (t2) = (z[o2 + 1].re) * (-wim[6]) + (z[o2 + 1].im) * (cos[1]);
	    }
	  while (0);
	  do
	    {
	      (t5) = (z[o3 + 1].re) * (cos[1]) - (z[o3 + 1].im) * (wim[6]);
	      (t6) = (z[o3 + 1].re) * (wim[6]) + (z[o3 + 1].im) * (cos[1]);
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
	      (t1) = (z[o2 + 3].re) * (cos[3]) - (z[o2 + 3].im) * (-wim[4]);
	      (t2) = (z[o2 + 3].re) * (-wim[4]) + (z[o2 + 3].im) * (cos[3]);
	    }
	  while (0);
	  do
	    {
	      (t5) = (z[o3 + 3].re) * (cos[3]) - (z[o3 + 3].im) * (wim[4]);
	      (t6) = (z[o3 + 3].re) * (wim[4]) + (z[o3 + 3].im) * (cos[3]);
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
	      (t1) = (z[o2 + 5].re) * (cos[5]) - (z[o2 + 5].im) * (-wim[2]);
	      (t2) = (z[o2 + 5].re) * (-wim[2]) + (z[o2 + 5].im) * (cos[5]);
	    }
	  while (0);
	  do
	    {
	      (t5) = (z[o3 + 5].re) * (cos[5]) - (z[o3 + 5].im) * (wim[2]);
	      (t6) = (z[o3 + 5].re) * (wim[2]) + (z[o3 + 5].im) * (cos[5]);
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
	      (t1) = (z[o2 + 7].re) * (cos[7]) - (z[o2 + 7].im) * (-wim[0]);
	      (t2) = (z[o2 + 7].re) * (-wim[0]) + (z[o2 + 7].im) * (cos[7]);
	    }
	  while (0);
	  do
	    {
	      (t5) = (z[o3 + 7].re) * (cos[7]) - (z[o3 + 7].im) * (wim[0]);
	      (t6) = (z[o3 + 7].re) * (wim[0]) + (z[o3 + 7].im) * (cos[7]);
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
