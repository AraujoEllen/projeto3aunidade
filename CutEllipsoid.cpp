#include "CutEllipsoid.hpp"
#include "sculptor.hpp"
#include <math.h>

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  this->xcenter = xcenter; this->ycenter = ycenter; this->zcenter = zcenter;
  this->rx = rx; this->ry = ry; this->rz = rz;
}
  
void CutEllipsoid::draw(Sculptor &s){
  
  float aux_x, aux_y, aux_z;
  int i, j, k;
  
  for ( i = 0; i < xcenter; i++){
    for ( j = 0; j < ycenter; j++){
      for ( k = 0; k < zcenter; k++){
        aux_x = ((float)(i-xcenter)*(float)(i-xcenter))/(rx * rx);
        aux_y = ((float)(j-ycenter)*(float)(j-ycenter))/(ry * ry);
        aux_z = ((float)(k-zcenter)*(float)(k-zcenter))/(rz * rz);
          if((aux_x + aux_y + aux_z) < 1){ 
          s.cutVoxel(i,j,k);
        }
      }
    }
  }
}
