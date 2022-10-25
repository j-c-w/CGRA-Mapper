// Source is: /home/alex/.local/share/compy-Learn/1.0/LivermoreC/content/file.c

#include <stdint.h>
#include <stdio.h>




struct
{
  double A11;
  double A12;
  double A13;
  double A21;
  double A22;
  double A23;
  double A31;
  double A32;
  double A33;
  double Ar;
  double Br;
  double C0;
  double Cr;
  double Di;
  double Dk;
  double Dm22;
  double Dm23;
  double Dm24;
  double Dm25;
  double Dm26;
  double Dm27;
  double Dm28;
  double Dn;
  double E3;
  double E6;
  double Expmax;
  double Flx;
  double Q;
  double Qa;
  double R;
  double Ri;
  double S;
  double Scale;
  double Sig;
  double Stb5;
  double T;
  double Xnc;
  double Xnei;
  double Xnm;
} spacer_;
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
fn (long ky, long kx, long nl1, long nl2)
{
  for (ky = 1; ky < spaces_.N; ky++)
    {
      space1_.Du1[ky] =
	space2_.U1[nl1][ky + 1][kx] - space2_.U1[nl1][ky - 1][kx];
      space1_.Du2[ky] =
	space2_.U2[nl1][ky + 1][kx] - space2_.U2[nl1][ky - 1][kx];
      space1_.Du3[ky] =
	space2_.U3[nl1][ky + 1][kx] - space2_.U3[nl1][ky - 1][kx];
      space2_.U1[nl2][ky][kx] =
	space2_.U1[nl1][ky][kx] + spacer_.A11 * space1_.Du1[ky] +
	spacer_.A12 * space1_.Du2[ky] + spacer_.A13 * space1_.Du3[ky] +
	spacer_.Sig * (space2_.U1[nl1][ky][kx + 1] -
		       2.0 * space2_.U1[nl1][ky][kx] +
		       space2_.U1[nl1][ky][kx - 1]);
      space2_.U2[nl2][ky][kx] =
	space2_.U2[nl1][ky][kx] + spacer_.A21 * space1_.Du1[ky] +
	spacer_.A22 * space1_.Du2[ky] + spacer_.A23 * space1_.Du3[ky] +
	spacer_.Sig * (space2_.U2[nl1][ky][kx + 1] -
		       2.0 * space2_.U2[nl1][ky][kx] +
		       space2_.U2[nl1][ky][kx - 1]);
      space2_.U3[nl2][ky][kx] =
	space2_.U3[nl1][ky][kx] + spacer_.A31 * space1_.Du1[ky] +
	spacer_.A32 * space1_.Du2[ky] + spacer_.A33 * space1_.Du3[ky] +
	spacer_.Sig * (space2_.U3[nl1][ky][kx + 1] -
		       2.0 * space2_.U3[nl1][ky][kx] +
		       space2_.U3[nl1][ky][kx - 1]);
    }
}
