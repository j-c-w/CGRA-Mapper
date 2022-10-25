#include "blowfish.h"
#define BF_LONG unsigned long

#define BF_M	0x3fc
#define BF_0	22L
#define BF_1	14L
#define BF_2	 6L
#define BF_3	 2L /* left shift */

#define BF_ENC(LL,R,S,P) \
	LL^=P; \
	LL^= (((*(BF_LONG *)((unsigned char *)&(S[  0])+((R>>BF_0)&BF_M))+ \
		*(BF_LONG *)((unsigned char *)&(S[256])+((R>>BF_1)&BF_M)))^ \
		*(BF_LONG *)((unsigned char *)&(S[512])+((R>>BF_2)&BF_M)))+ \
		*(BF_LONG *)((unsigned char *)&(S[768])+((R<<BF_3)&BF_M)));

void BF_encrypt(data,key,encrypt)
BF_LONG *data;
BF_KEY *key;
int encrypt;
  {
  register BF_LONG l,r,temp,*p,*s;

  p=key->P;
  s= &(key->S[0]);
  l=data[0];
  r=data[1];

  if (encrypt)
    {
    l^=p[0];
    int i=1;
    for (; i<21; ++i) {
      BF_ENC(r,l,s,p[i]);
      // we only consider BF_ENC function for now.
      temp = r;
      r = l;
      l = temp;
    }
    r^=p[0];
    }
  data[1]=l&0xffffffff;
  data[0]=r&0xffffffff;
  }
