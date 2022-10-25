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
  double U[1001];
  double V[1001];
  double W[1001];
  double X[1001];
  double Y[1001];
  double Z[1001];
  double G[1001];
  double Du1[101];
  double Du2[101];
  double Du3[101];
  double Grd[1001];
  double Dex[1001];
  double Xi[1001];
  double Ex[1001];
  double Ex1[1001];
  double Dex1[1001];
  double Vx[1001];
  double Xx[1001];
  double Rx[1001];
  double Rh[2048];
  double Vsp[101];
  double Vstp[101];
  double Vxne[101];
  double Vxnd[101];
  double Ve3[101];
  double Vlr[101];
  double Vlin[101];
  double B5[101];
  double Plan[300];
  double D[300];
  double Sa[101];
  double Sb[101];
} space1_;

int
fn (long k, long i)
{
  for (k = 0; k < i; k++)
    {
      space1_.W[i] += space2_.B[k][i] * space1_.W[(i - k) - 1];
    }
}
