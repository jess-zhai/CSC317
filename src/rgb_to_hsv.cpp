#include "rgb_to_hsv.h"
#include <algorithm>
#include <cmath>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  //formula: https://www.rapidtables.com/convert/color/rgb-to-hsv.html 
  double cmax = std::max(std::max(r, g), b);
  double cmin = std::min(std::min(r, g), b);
  double delta = (double) cmax - cmin;
  if (delta == 0){
    h = 0;
  } else if (cmax == r){
    
    h = 60 * fmod(((g - b)/delta), 6);
  
  } else if (cmax == g) {
    h = 60 * ((b - r)/delta + 2);
  } else {
    h = 60 * ((r - g)/delta + 4);
  }
  if (h >= 360){
    h -= 360;
  } else if (h < 0){
    h += 360;
  }
  if (cmax == 0){
    s = 0;
  } else {
    s = delta/cmax;
  }
  v = cmax;
  ////////////////////////////////////////////////////////////////////////////
}
