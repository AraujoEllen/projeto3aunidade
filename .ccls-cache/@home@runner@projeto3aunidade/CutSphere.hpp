#ifndef CUTSPHERE_HP
#define CUTSPHERE_HP
#include "FiguraGeometrica.hpp"
#include "sculptor.hpp"

class CutSphere : public FiguraGeometrica{
private:
    int xcenter, ycenter, zcenter, radius;
    
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
  //~PutVoxel(){}  
  void draw(Sculptor &s);
};

#endif // CUTSPHERE_HP