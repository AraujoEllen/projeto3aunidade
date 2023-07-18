#ifndef CUTVOXEL_HPP
#define CUTVOXEL_HPP
#include "FiguraGeometrica.hpp"
#include "sculptor.hpp"

/*! \brief
  *  Desativa o voxel na posicao (x,y,z).
*/
class CutVoxel : public FiguraGeometrica{
  int x, y, z;
    
public:
  CutVoxel(int x, int y, int z);
  ~CutVoxel(){}  
  void draw(Sculptor &s);
};

#endif // CUTVOXEL_HPP