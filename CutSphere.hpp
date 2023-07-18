#ifndef CUTSPHERE_HP
#define CUTSPHERE_HP
#include "FiguraGeometrica.hpp"
#include "sculptor.hpp"

/*! \brief
  *  Desativa todos os voxels que satizfazem 
  *  a equacao da esfera.
*/
class CutSphere : public FiguraGeometrica{
private:
    int xcenter, ycenter, zcenter, radius;
    
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
  //~PutVoxel(){}  
  void draw(Sculptor &s);
};

#endif // CUTSPHERE_HP