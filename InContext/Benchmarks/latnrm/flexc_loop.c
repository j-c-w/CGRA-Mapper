
#define ORDER 8

void kernel(float input, float *output, float coefficient[16],
            float internal_state[16])
/*    input:           input sample array */
/*    output:          output sample array */
/*    coefficient:     coefficient array */
/*    internal_state:  internal state array */
{
  int i;
  float left, right, top, bottom;
  float q_coef, k_coef;
  float term_1, term_2;
  float sum;

  top = input;
  q_coef = coefficient[0];
  //#pragma clang loop unroll_count(4)
  for (i = 0; i < ORDER; i++) {
    k_coef = coefficient[2*i];
    left = top;
    right = internal_state[i];
    internal_state[i] = bottom;
    top = q_coef * left - k_coef * right;
    bottom = q_coef * right + k_coef * left;
    q_coef = coefficient[2*i+1];
  }
}
