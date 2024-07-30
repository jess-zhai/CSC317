#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  // rgb stays the same. need to do rowwise. e.g. pixel in row 1 col 1 swap with row1 col -1.
  // if odd columns, middle one stays the same
  
  // std::vector<int> rgb1(num_channels);
  // std::vector<int> rgb2(num_channels);
  int h = 0;
  while (h < height){
    int w = 0;
    while (w < width/2+1){
      for (int i = 0; i < num_channels; i++){
        reflected[(h * width + (width-1 - w)) * num_channels+i] = input[(h * width + w) * num_channels+i];
        reflected[(h * width + w) * num_channels+i] = input[(h * width + (width-1 - w)) * num_channels+i];
      }
      // rgb1[0], rgb1[1], rgb1[2] = input[h * w * 3], input[h * w * 3+ 1], input[h * w * 3 + 2];
      // rgb2[0], rgb2[1], rgb2[2] = input[h * (width - w) * 3], input[h * (width - w) * 3+ 1], input[h * (width - w) * 3 + 2];
      // reflected[h * w * 3], reflected[h * w * 3 +1], reflected[h * w * 3 +2] = rgb2[0], rgb2[1], rgb2[2];
      // reflected[h * (width - w) * 3], reflected[h * (width - w) * 3+ 1], reflected[h * (width - w) * 3 + 2] = rgb1[0], rgb1[1], rgb1[2];
      w++;
    }
    h++;
  }
  ////////////////////////////////////////////////////////////////////////////
}
