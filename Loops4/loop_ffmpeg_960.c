// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavutil/tx_float.c

#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexFloat
{
  float re, im;
} AVComplexFloat;
typedef AVComplexFloat TXComplex;
typedef float TXSample;

int
fn (TXComplex * data, const int len2, const int len4, const TXSample * tsin,
    const TXSample * fact, const TXSample * tcos, TXComplex t[3])
{
  for (int i = 1; i < len4; i++)
    {
      t[0].re = ((fact[4]) * ((data[i].re + data[len2 - i].re)));
      t[0].im = ((fact[5]) * ((data[i].im - data[len2 - i].im)));
      t[1].re = ((fact[6]) * ((data[i].im + data[len2 - i].im)));
      t[1].im = ((fact[7]) * ((data[i].re - data[len2 - i].re)));
      do
	{
	  (t[2].re) = (t[1].re) * (tcos[i]) - (t[1].im) * (tsin[i]);
	  (t[2].im) = (t[1].re) * (tsin[i]) + (t[1].im) * (tcos[i]);
	}
      while (0);
      data[i].re = t[0].re + t[2].re;
      data[i].im = t[2].im - t[0].im;
      data[len2 - i].re = t[0].re - t[2].re;
      data[len2 - i].im = t[2].im + t[0].im;
    }
}
