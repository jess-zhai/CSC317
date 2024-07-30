#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  // convert image to hsv, shift, and convert back
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
      hue += shift;
      if (hue >= 360){
        hue -= 360;
      } else if (h < 0){
        hue += 360;
      }
      hsv_to_rgb(hue, s, v, r, g, b);
      shifted[id] = (unsigned char) r;
      shifted[id+1] = (unsigned char) g;
      shifted[id+2] = (unsigned char)b;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
