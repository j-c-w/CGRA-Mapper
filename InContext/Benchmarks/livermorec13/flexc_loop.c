// Source is: /home/alex/.local/share/compy-Learn/1.0/LivermoreC/content/file.c

#include <stdint.h>
#include <stdio.h>




struct
{
  long E[96];
  long F[96];
  long Ix[1001];
  long Ir[1001];
  long Zone[300];
} ispace_;
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
fn (long i2, long j1, long ip, long j2, long i1)
{
  for (ip = 0; ip < spaces_.N; ip++)
    {
      i1 = space2_.P[ip][0];
      j1 = space2_.P[ip][1];
      i1 &= 64 - 1;
      j1 &= 64 - 1;
      space2_.P[ip][2] += space2_.B[j1][i1];
      space2_.P[ip][3] += space2_.C[j1][i1];
      space2_.P[ip][0] += space2_.P[ip][2];
      space2_.P[ip][1] += space2_.P[ip][3];
      i2 = space2_.P[ip][0];
      j2 = space2_.P[ip][1];
      i2 = (i2 & 64 - 1) - 1;
      j2 = (j2 & 64 - 1) - 1;
      space2_.P[ip][0] += space1_.Y[i2 + 32];
      space2_.P[ip][1] += space1_.Z[j2 + 32];
      i2 += ispace_.E[i2 + 32];
      j2 += ispace_.F[j2 + 32];
      space2_.H[j2][i2] += 1.0;
    }
}
