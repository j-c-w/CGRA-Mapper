// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavutil/tx_int32.c

#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexInt32
{
  int32_t re, im;
} AVComplexInt32;
typedef AVComplexInt32 TXComplex;
typedef int32_t TXSample;

int
fn (TXComplex * data, const int len2, const int len4, const TXSample * tsin,
    const TXSample * fact, const TXSample * tcos, TXComplex t[3])
{
  for (int i = 1; i < len4; i++)
    {
      t[0].re =
	(((((int64_t) (fact[4])) *
	   (int64_t) ((data[i].re + data[len2 - i].re))) + 0x40000000) >> 31);
      t[0].im =
	(((((int64_t) (fact[5])) *
	   (int64_t) ((data[i].im - data[len2 - i].im))) + 0x40000000) >> 31);
      t[1].re =
	(((((int64_t) (fact[6])) *
	   (int64_t) ((data[i].im + data[len2 - i].im))) + 0x40000000) >> 31);
      t[1].im =
	(((((int64_t) (fact[7])) *
	   (int64_t) ((data[i].re - data[len2 - i].re))) + 0x40000000) >> 31);
      do
	{
	  int64_t accu;
	  (accu) = (int64_t) (tcos[i]) * (t[1].re);
	  (accu) -= (int64_t) (tsin[i]) * (t[1].im);
	  (t[2].re) = (int) (((accu) + 0x40000000) >> 31);
	  (accu) = (int64_t) (tsin[i]) * (t[1].re);
	  (accu) += (int64_t) (tcos[i]) * (t[1].im);
	  (t[2].im) = (int) (((accu) + 0x40000000) >> 31);
	}
      while (0);
      data[i].re = t[0].re + t[2].re;
      data[i].im = t[2].im - t[0].im;
      data[len2 - i].re = t[0].re - t[2].re;
      data[len2 - i].im = t[2].im + t[0].im;
    }
}
