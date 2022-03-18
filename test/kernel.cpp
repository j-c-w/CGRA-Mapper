#define NTAPS 32

void kernel(int input[], int output[], int coefficient[])
/*   input :           input sample array */
/*   output:           output sample array */
/*   coefficient:      coefficient array */
{
  int i;
  int j = 0;

//  for(j=0; j< NTAPS; ++j) {
    for (i = 0; i < NTAPS; ++i) {
	  // CGRA Generated from this:
      //output[j] += 1.0 - (input[i]) * coefficient[i] * 13.0;
	  // Fails on this:
      output[j] += input[i] - (coefficient[i]);
	  // Apply rewrite rule X / Y == X * (1 / Y)
      // output[j] += 1.0 - (input[i]) * coefficient[i] * (1.0 / 13.0);
    }
//  }
}
