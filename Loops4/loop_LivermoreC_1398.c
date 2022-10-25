// Source is: /home/alex/.local/share/compy-Learn/1.0/LivermoreC/content/file.c

#include <stdint.h>
#include <stdio.h>




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
  long E[96];
  long F[96];
  long Ix[1001];
  long Ir[1001];
  long Zone[300];
} ispace_;

int
fn (long k)
{
  for (k = 0; k < spaces_.N; k++)
    {
      space1_.Vx[k] =
	space1_.Vx[k] + space1_.Ex1[k] + (space1_.Xx[k] -
					  space1_.Xi[k]) * space1_.Dex1[k];
      space1_.Xx[k] = space1_.Xx[k] + space1_.Vx[k] + spacer_.Flx;
      ispace_.Ir[k] = space1_.Xx[k];
      space1_.Rx[k] = space1_.Xx[k] - ispace_.Ir[k];
      ispace_.Ir[k] = (ispace_.Ir[k] & 2048 - 1) + 1;
      space1_.Xx[k] = space1_.Rx[k] + ispace_.Ir[k];
    }
}
