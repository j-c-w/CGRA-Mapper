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

int
fn (long k, long jn, long j)
{
  for (j = 1; j < jn; j++)
    {
      space2_.Za[k][j] =
	(space2_.Zp[k + 1][j - 1] + space2_.Zq[k + 1][j - 1] -
	 space2_.Zp[k][j - 1] - space2_.Zq[k][j - 1]) * (space2_.Zr[k][j] +
							 space2_.Zr[k][j -
								       1]) /
	(space2_.Zm[k][j - 1] + space2_.Zm[k + 1][j - 1]);
      space2_.Zb[k][j] =
	(space2_.Zp[k][j - 1] + space2_.Zq[k][j - 1] - space2_.Zp[k][j] -
	 space2_.Zq[k][j]) * (space2_.Zr[k][j] + space2_.Zr[k -
							    1][j]) /
	(space2_.Zm[k][j] + space2_.Zm[k][j - 1]);
    }
}
