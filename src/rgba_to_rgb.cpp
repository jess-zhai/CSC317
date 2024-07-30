#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  // should have same pixels as rgba, but skip the alpha. so read 3, skip 1
  int j = 0;
  for (int i=0; i < height*width*4; i++) {
    if ((i+1) % 4 != 0) {
      rgb[j] = rgba[i];
      j++;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
