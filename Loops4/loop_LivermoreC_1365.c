// Source is: /home/alex/.local/share/compy-Learn/1.0/LivermoreC/content/file.c

#include <stdint.h>
#include <stdio.h>




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
  double Tic;
  double Times[47][3][8];
  double See[3][8][3][5];
  double Terrs[47][3][8];
  double Csums[47][3][8];
  double Fopn[47][3][8];
  double Dos[47][3][8];
} beta_;

int
fn (long k)
{
  for (k = 0; k < alpha_.Mk; k++)
    {
      beta_.Times[k][alpha_.Il - 1][alpha_.Jr - 1] = space0_.Time[k];
      beta_.Fopn[k][alpha_.Il - 1][alpha_.Jr - 1] = space0_.Flopn[k];
      beta_.Terrs[k][alpha_.Il - 1][alpha_.Jr - 1] = space0_.Terr1[k];
      alpha_.Npfs[k][alpha_.Il - 1][alpha_.Jr - 1] = space0_.Npfs1[k];
      beta_.Csums[k][alpha_.Il - 1][alpha_.Jr - 1] = space0_.Csum[k];
      beta_.Dos[k][alpha_.Il - 1][alpha_.Jr - 1] = space0_.Total[k];
    }
}
