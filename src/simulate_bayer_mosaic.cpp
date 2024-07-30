#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int h=0; h<height; h++){
    for (int w=0; w<width; w++){
      int i; //offset for rgb
      if( (w + h * width) % 2 == 0){ //if the index is even, green
        i = 1;
      } else if (h % 2 == 0){ //blue
        i = 2;
      } else { //red
        i = 0;
      }
      bayer[w+h*width] = rgb[3*(w+h*width) + i];
    }
    
  }
  ////////////////////////////////////////////////////////////////////////////
}
