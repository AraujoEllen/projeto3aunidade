#ifndef FIGURAGEOMETRICA_HPP
#define FIGURAGEOMETRICA_HPP
#include "sculptor.hpp"

/*! \brief
  *Classe abstrata que representa objetos primitivos genéricos
*/
class FiguraGeometrica{
protected:
    float r, g, b, a;
public:
    FiguraGeometrica(){};
    virtual ~FiguraGeometrica(){};
    // FUNCAO VIRTUAL PURA TORNA A CLASSE ABSTRATA
    virtual void draw(Sculptor &s)=0;
};

#endif // FIGURAGEOMETRICA_HPP