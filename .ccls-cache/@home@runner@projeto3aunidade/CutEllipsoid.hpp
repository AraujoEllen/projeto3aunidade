#ifndef CUTELLIPSOID_HPP
#define CUTELLIPSOID_HPP
#include "FiguraGeometrica.hpp"
#include "sculptor.hpp"

class CutEllipsoid : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;
    
public:
  CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);    
  //~PutVoxel(){}  
  void draw(Sculptor &s);
};

#endif // CUTELLIPSOID_HPP