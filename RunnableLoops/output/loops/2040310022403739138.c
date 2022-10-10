#include <stdint.h>
#include <stdio.h>




struct
{
  double Time[47];
  double Csum[47];
  double Ww[47];
  double Wt[47];
  double Ticks;
  double Fr[9];
  double Terr1[47];
  double Sumw[7];
  double Start;
  double Skale[47];
  double Bias[47];
  double Ws[95];
  double Total[47];
  double Flopn[47];
  long Iq[7];
  long Npf;
  long Npfs1[47];
} space0_;
struct
{
  long Mk;
  long Ik;
  long Im;
  long Ml;
  long Il;
  long Mruns;
  long Nruns;
  long Jr;
  long Npfs[47][3][8];
} alpha_;

int
fn (double som, long k)
{
  for (k = 0; k < alpha_.Mk; k++)
    {
      som += space0_.Flopn[k] * space0_.Total[k];
    }
}
