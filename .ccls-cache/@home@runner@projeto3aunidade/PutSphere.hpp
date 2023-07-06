#ifndef PUTSPHERE_HP
#define PUTSPHERE_HP
#include "FiguraGeometrica.hpp"
#include "sculptor.hpp"

class PutSphere : public FiguraGeometrica{
  int xcenter, ycenter, zcenter, radius;
    
public:
  PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
  ~PutSphere(){}  
  void draw(Sculptor &s);
};

#endif // PUTSPHERE_HP