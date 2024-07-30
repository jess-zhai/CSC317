#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int h=0; h<height; h++){
    for (int w=0; w<width; w++){
      int id = 3*(w + h*width);
      double r = ((double)rgb[id]) / 255;
      double g = ((double)rgb[id+1]) / 255;
      double b = ((double)rgb[id+2]) / 255;
      double hue; 
      double s; 
      double v;
      rgb_to_hsv(r, g, b, hue, s, v);
      s = s * (1-factor);
      if (s < 0){
        s = 0;
      } else if (s > 1){
        s = 1;
      }
      hsv_to_rgb(hue, s, v, r, g, b);
      desaturated[id] = (unsigned char) r;
      desaturated[id+1] = (unsigned char) g;
      desaturated[id+2] = (unsigned char) b;
    }
  }
  
  ////////////////////////////////////////////////////////////////////////////
}
