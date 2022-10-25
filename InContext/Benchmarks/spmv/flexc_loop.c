#define SIZE 10000

void kernel(int nnz, int val[], int col[], int row[], int feature[], int output[])
{
  int i = 0;
  int temp;

  #pragma clang loop unroll_count(4)
  for (i = 0; i < nnz; ++i) {
    temp = val[i] * feature[ col[i] ];
    output[ row[i] ] += temp;
  }
}

