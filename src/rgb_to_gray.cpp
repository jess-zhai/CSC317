#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  //
  for (int h=0; h < height; h++){
    for (int w=0; w < width; w++){
      double r = (double)rgb[3 * (w + h * width)] / 255;
      double g = (double)rgb[3 * (w + h * width)+1] / 255;
      double b = (double)rgb[3 * (w + h * width)+2] / 255;
      const double grayTemp = 0.2126 * r + 0.7152 * g + 0.0722 * b;
      const double grayscale = grayTemp * 255;
      gray[w + h*width] = (unsigned char) grayscale;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}


