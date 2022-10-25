
typedef int        TOTAL_TYPE; /* this is faster for "int" but should be "float" for large d masks */

#define SEVEN_SUPP           /* size for non-max corner suppression; SEVEN_SUPP or FIVE_SUPP */
#define MAX_CORNERS   15000  /* max corners per frame */

typedef  unsigned char uchar;
typedef  struct {int x,y,info, dx, dy, I;} CORNER_LIST[MAX_CORNERS];

susan_corners(in,r,bp,max_no,corner_list,x_size,y_size)
  unsigned char       *in, *bp;
  int         *r, max_no, x_size, y_size;
  CORNER_LIST corner_list;
{
int   n,x,y,sq,xx,yy,
      i,j,*cgx,*cgy;
float divide;
unsigned char c,*p,*cp;

  memset (r,0,x_size * y_size * sizeof(int));

  cgx=(int *)malloc(x_size*y_size*sizeof(int));
  cgy=(int *)malloc(x_size*y_size*sizeof(int));

  for (i=5;i<y_size-5;i++)
    for (j=5;j<x_size-5;j++) {
        n=100;
        p=in + (i-3)*x_size + j - 1;
        cp=bp + in[i*x_size+j];

        n+=*(cp-*p++);
        n+=*(cp-*p++);
        n+=*(cp-*p);
        p+=x_size-3;

        n+=*(cp-*p++);
        n+=*(cp-*p++);
        n+=*(cp-*p++);
        n+=*(cp-*p++);
        n+=*(cp-*p);
        p+=x_size-5;

        n+=*(cp-*p++);
        n+=*(cp-*p++);
        n+=*(cp-*p++);
        n+=*(cp-*p++);
        n+=*(cp-*p++);
        n+=*(cp-*p++);
        n+=*(cp-*p);
        p+=x_size-6;

        n+=*(cp-*p++);
        n+=*(cp-*p++);
        n+=*(cp-*p);
      if (n<max_no){    /* do this test early and often ONLY to save wasted computation */
        p+=2;
        n+=*(cp-*p++);
      if (n<max_no){
        n+=*(cp-*p++);
      if (n<max_no){
        n+=*(cp-*p);
      if (n<max_no){
        p+=x_size-6;

        n+=*(cp-*p++);
      if (n<max_no){
        n+=*(cp-*p++);
      if (n<max_no){
        n+=*(cp-*p++);
      if (n<max_no){
        n+=*(cp-*p++);
      if (n<max_no){
        n+=*(cp-*p++);
      if (n<max_no){
        n+=*(cp-*p++);
      if (n<max_no){
        n+=*(cp-*p);
      if (n<max_no){
        p+=x_size-5;

        n+=*(cp-*p++);
      if (n<max_no){
        n+=*(cp-*p++);
      if (n<max_no){
        n+=*(cp-*p++);
      if (n<max_no){
        n+=*(cp-*p++);
      if (n<max_no){
        n+=*(cp-*p);
      if (n<max_no){
        p+=x_size-3;

        n+=*(cp-*p++);
      if (n<max_no){
        n+=*(cp-*p++);
      if (n<max_no){
        n+=*(cp-*p);

        if (n<max_no)
        {
            x=0;y=0;
            p=in + (i-3)*x_size + j - 1;

            c=*(cp-*p++);x-=c;y-=3*c;
            c=*(cp-*p++);y-=3*c;
            c=*(cp-*p);x+=c;y-=3*c;
            p+=x_size-3;

            c=*(cp-*p++);x-=2*c;y-=2*c;
            c=*(cp-*p++);x-=c;y-=2*c;
            c=*(cp-*p++);y-=2*c;
            c=*(cp-*p++);x+=c;y-=2*c;
            c=*(cp-*p);x+=2*c;y-=2*c;
            p+=x_size-5;

            c=*(cp-*p++);x-=3*c;y-=c;
            c=*(cp-*p++);x-=2*c;y-=c;
            c=*(cp-*p++);x-=c;y-=c;
            c=*(cp-*p++);y-=c;
            c=*(cp-*p++);x+=c;y-=c;
            c=*(cp-*p++);x+=2*c;y-=c;
            c=*(cp-*p);x+=3*c;y-=c;
            p+=x_size-6;

            c=*(cp-*p++);x-=3*c;
            c=*(cp-*p++);x-=2*c;
            c=*(cp-*p);x-=c;
            p+=2;
            c=*(cp-*p++);x+=c;
            c=*(cp-*p++);x+=2*c;
            c=*(cp-*p);x+=3*c;
            p+=x_size-6;

            c=*(cp-*p++);x-=3*c;y+=c;
            c=*(cp-*p++);x-=2*c;y+=c;
            c=*(cp-*p++);x-=c;y+=c;
            c=*(cp-*p++);y+=c;
            c=*(cp-*p++);x+=c;y+=c;
            c=*(cp-*p++);x+=2*c;y+=c;
            c=*(cp-*p);x+=3*c;y+=c;
            p+=x_size-5;

            c=*(cp-*p++);x-=2*c;y+=2*c;
            c=*(cp-*p++);x-=c;y+=2*c;
            c=*(cp-*p++);y+=2*c;
            c=*(cp-*p++);x+=c;y+=2*c;
            c=*(cp-*p);x+=2*c;y+=2*c;
            p+=x_size-3;

            c=*(cp-*p++);x-=c;y+=3*c;
            c=*(cp-*p++);y+=3*c;
            c=*(cp-*p);x+=c;y+=3*c;

            xx=x*x;
            yy=y*y;
            sq=xx+yy;
            if ( sq > ((n*n)/2) )
            {
              if(yy<xx) {
                divide=(float)y/(float)abs(x);
                sq=abs(x)/x;
                sq=*(cp-in[(i+FTOI(divide))*x_size+j+sq]) +
                   *(cp-in[(i+FTOI(2*divide))*x_size+j+2*sq]) +
                   *(cp-in[(i+FTOI(3*divide))*x_size+j+3*sq]);}
              else {
                divide=(float)x/(float)abs(y);
                sq=abs(y)/y;
                sq=*(cp-in[(i+sq)*x_size+j+FTOI(divide)]) +
                   *(cp-in[(i+2*sq)*x_size+j+FTOI(2*divide)]) +
                   *(cp-in[(i+3*sq)*x_size+j+FTOI(3*divide)]);}

              if(sq>290){
                r[i*x_size+j] = max_no-n;
                cgx[i*x_size+j] = (51*x)/n;
                cgy[i*x_size+j] = (51*y)/n;}
            }
	}
}}}}}}}}}}}}}}}}}}}

}
