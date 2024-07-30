#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  // http://ssp.impulsetrain.com/porterduff.html
  // https://en.wikipedia.org/wiki/Alpha_compositing
  for (int h=0; h<height; h++){
    for (int w=0; w<width; w++){
      int rA = A[4 * (w+ h*width)];
      int gA = A[4 * (w+ h*width)+1];
      int bA = A[4 * (w+ h*width)+2];
      double a1 = (double)A[4 * (w+ h*width)+3]/255;
      int rB = B[4 * (w+ h*width)];
      int gB = B[4 * (w+ h*width)+1];
      int bB = B[4 * (w+ h*width)+2];
      double a2 = (double)B[4 * (w+ h*width)+3]/255;

      double a0 = a1 + a2 * (1 - a1);
      int r0 = ((double)(rA*a1 + rB*a2 * (1-a1))) / a0;
      int g0 = ((double)(gA*a1 + gB*a2 * (1-a1))) / a0;
      int b0 = ((double)(bA*a1 + bB*a2 * (1-a1))) / a0;

      C[4 * (w+ h*width)] = r0;
      C[4 * (w+ h*width) + 1] = g0;
      C[4 * (w+ h*width) + 2] = b0;
      C[4 * (w+ h*width) + 3] = (double) a0 * 255.0;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
