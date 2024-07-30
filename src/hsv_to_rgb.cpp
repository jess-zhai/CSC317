#include "hsv_to_rgb.h"
#include <algorithm>
#include <cmath>

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // formula used: https://www.rapidtables.com/convert/color/hsv-to-rgb.html
  double c = v * s;
  double x = c * (1 - fabs(fmod(h / 60, 2) - 1));
  double m = v - c;

  double r1, g1, b1; 

  if (0 <= h && h < 60) {
    r1 = c;
    g1 = x;
    b1 = 0;
  } else if (60 <= h && h < 120) {
    r1 = x;
    g1 = c;
    b1 = 0;
  } else if (120 <= h && h < 180) {
    r1 = 0;
    g1 = c;
    b1 = x;
  } else if (180 <= h && h < 240) {
    r1 = 0;
    g1 = x;
    b1 = c;
  } else if (240 <= h && h < 300) {
    r1 = x;
    g1 = 0;
    b1 = c;
  } else if (300 <= h && h < 360) {
    r1 = c;
    g1 = 0;
    b1 = x;
  }

  r = (r1 + m) * 255;
  g = (g1 + m) * 255;
  b = (b1 + m) * 255;
  ////////////////////////////////////////////////////////////////////////////
}
