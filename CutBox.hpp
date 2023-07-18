#ifndef CUTBOX_HPP
#define CUTBOX_HPP
#include "FiguraGeometrica.hpp"
#include "sculptor.hpp"

/*! \brief
  *  Desativa uma sequencia de voxels.
*/ 
class CutBox : public FiguraGeometrica{
  int x0, y0, z0, x1, y1, z1;
    
public:
    CutBox(int x0, int y0, int z0,int x1, int y1, int z1);
  //~PutVoxel(){}  
  void draw(Sculptor &s);
};

#endif // CUTBOX_HPP