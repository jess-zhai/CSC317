#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            for (int i = 0; i < num_channels; i++){
              // modified similar rotation index from https://stackoverflow.com/questions/20149783/rotating-a-2d-converted-1d-array-90-degrees-clockwise
              rotated[num_channels * ((width - w - 1) * height + h) + i] = 
              input[num_channels * (w + h * width) + i];
            }
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}
