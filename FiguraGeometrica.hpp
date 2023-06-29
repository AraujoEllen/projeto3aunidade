#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H


class FiguraGeometrica{
public:
    FiguraGeometrica();
    // FUNCAO VIRTUAL PURA TORNA A CLASSE ABSTRATA
    virtual void draw(Sculptor *s)=0;
};

#endif // FIGURAGEOMETRICA_H