#include "demosaic.h"

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int h=0; h < height; h++){
    for (int w=0; w < width; w++){
      if ((w + h * width) % 2 == 0){ //green
          float sumred = 0;
          float sumblue = 0;
          int countr = 0;
          int countb = 0;
          int green = bayer[w + h * width];
          if(h - 1 >= 0){
            sumred += bayer[w+(h-1)*width];
            countr +=1;
          }
          if (h+1 < height){
            sumred += bayer[w+(h+1)*width];
            countr += 1;
          }
          if(w - 1 >= 0){
            sumblue += bayer[w-1 + h*width];
            countb +=1;
          }
          if(w+1 < width){
            sumblue += bayer[w+1 + h*width];
            countb += 1;
          }
          sumred /= countr;
          sumblue /= countb;
          rgb[3*(w+h*width)] = (int)sumred;
          rgb[3*(w+h*width) + 1] = green;
          rgb[3*(w+h*width) + 2] = (int)sumblue;
      } else if (h % 2 == 0){ //blue
        float sumred = 0;
        float sumgreen = 0;
        int countr = 0;
        int countg = 0;
        int blue = bayer[w + h * width];
        if(h - 1 >= 0){
          sumgreen += bayer[w+(h-1)*width];
          countg +=1;
          if (w - 1 >= 0){
            sumred += bayer[w-1 + (h-1)*width];
            countr +=1;
          }
          if (w+1 < width){
            sumred += bayer[w+1 + (h-1)*width];
            countr += 1;
          }
        }
        if (h+1 < height){
          sumgreen += bayer[w+(h+1)*width];
          countg += 1;
          if (w - 1 >= 0){
            sumred += bayer[w-1 + (h+1)*width];
            countr +=1;
          }
          if (w+1 < width){
            sumred += bayer[w+1 + (h+1)*width];
            countr += 1;
          }
        }
        if(w - 1 >= 0){
          sumgreen += bayer[w-1 + h*width];
          countg +=1;
        }
        if(w+1 < width){
          sumgreen += bayer[w+1 + h*width];
          countg += 1;
        }
        sumred /= countr;
        sumgreen /= countg;
        rgb[3*(w+h*width)] = (int)sumred;
        rgb[3*(w+h*width) + 1] = (int) sumgreen;
        rgb[3*(w+h*width) + 2] = blue;
      } else {
        float sumblue = 0;
        float sumgreen = 0;
        int countb = 0;
        int countg = 0;
        int red = bayer[w + h * width];
        if(h - 1 >= 0){
          sumgreen += bayer[w+(h-1)*width];
          countg +=1;
          if (w - 1 >= 0){
            sumblue += bayer[w-1 + (h-1)*width];
            countb +=1;
          }
          if (w+1 < width){
            sumblue += bayer[w+1 + (h-1)*width];
            countb += 1;
          }
        }
        if (h+1 < height){
          sumgreen += bayer[w+(h+1)*width];
          countg += 1;
          if (w - 1 >= 0){
            sumblue += bayer[w-1 + (h+1)*width];
            countb +=1;
          }
          if (w+1 < width){
            sumblue += bayer[w+1 + (h+1)*width];
            countb += 1;
          }
        }
        if(w - 1 >= 0){
          sumgreen += bayer[w-1 + h*width];
          countg +=1;
        }
        if(w+1 < width){
          sumgreen += bayer[w+1 + h*width];
          countg += 1;
        }
        sumblue /= countb;
        sumgreen /= countg;
        rgb[3*(w+h*width)] = red;
        rgb[3*(w+h*width) + 1] = (int) sumgreen;
        rgb[3*(w+h*width) + 2] = (int)sumblue;
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
