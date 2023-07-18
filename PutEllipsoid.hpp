#ifndef PUTELLIPSOID_HPP
#define PUTELLIPSOID_HPP
#include "FiguraGeometrica.hpp"
#include "sculptor.hpp"

/*! \brief
  *  Ativa todos os voxels que satizfazem a equacao 
  *  da elipsoide, atribuindo cor e transparencia
*/
class PutEllipsoid : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;
    
public:
  PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
  ~PutEllipsoid(){}  
  void draw(Sculptor &s);
};

#endif // PUTELLIPSOID_HPP