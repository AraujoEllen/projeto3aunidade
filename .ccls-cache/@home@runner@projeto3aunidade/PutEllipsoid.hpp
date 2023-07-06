#ifndef PUTELLIPSOID_HPP
#define PUTELLIPSOID_HPP
#include "FiguraGeometrica.hpp"
#include "sculptor.hpp"

class PutEllipsoid : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;
    
public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
  //~PutVoxel(){}  
  void draw(Sculptor &s);
};

#endif // PUTELLIPSOID_HPP