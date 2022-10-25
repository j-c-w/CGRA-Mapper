// Source is: /home/alex/.local/share/compy-Learn/1.0/LivermoreC/content/file.c

#include <stdint.h>
#include <stdio.h>




struct
{
  double P[512][4];
  double Px[101][25];
  double Cx[101][25];
  double Vy[25][101];
  double Vh[7][101];
  double Vf[7][101];
  double Vg[7][101];
  double Vs[7][101];
  double Za[7][101];
  double Zp[7][101];
  double Zq[7][101];
  double Zr[7][101];
  double Zm[7][101];
  double Zb[7][101];
  double Zu[7][101];
  double Zv[7][101];
  double Zz[7][101];
  double B[64][64];
  double C[64][64];
  double H[64][64];
  double U1[2][101][5];
  double U2[2][101][5];
  double U3[2][101][5];
} space2_;
struct
{
  long Ion;
  long J5;
  long K2;
  long K3;
  long MULTI;
  long Laps;
  long Loop;
  long M;
  long Kr;
  long It;
  long N13h;
  long Ibuf;
  long Npass;
  long Nfail;
  long N;
  long N1;
  long N2;
  long N13;
  long N213;
  long N813;
  long N14;
  long N16;
  long N416;
  long N21;
  long Nt1;
  long Nt2;
} spaces_;

int
fn (long k, long i, long j)
{
  for (j = 0; j < spaces_.N; j++)
    {
      space2_.Px[j][i] += space2_.Vy[k][i] * space2_.Cx[j][k];
    }
}
