#include "CutVoxel.hpp"
#include "sculptor.hpp"
#include <iostream>

CutVoxel::CutVoxel(int x, int y, int z){
    this->x = x; this->y = y; this->z = z; 
    //this->r = r; this->g = g; this->b = b; this->a = a;
}

void CutVoxel::draw(Sculptor &s){
  //s.setColor(r, g, b, a);
  s.cutVoxel(x,y,z);
}