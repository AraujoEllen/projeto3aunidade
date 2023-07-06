#ifndef PUTBOX_HPP
#define PUTBOX_HPP
#include "FiguraGeometrica.hpp"
#include "sculptor.hpp"

class PutBox : public FiguraGeometrica{
    int x0, y0, z0, x1, y1, z1;
    
public:
  PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);    
  //~PutVoxel(){}  
  void draw(Sculptor &s);
};

#endif // PUTBOX_HPP