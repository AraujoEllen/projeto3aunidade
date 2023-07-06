#include "FiguraGeometrica.hpp"
#include "PutVoxel.hpp"
#include "CutVoxel.hpp"
#include "PutBox.hpp"
#include "CutBox.hpp"
#include "PutSphere.hpp"
#include "CutSphere.hpp"
#include "PutEllipsoid.hpp"
#include "CutEllipsoid.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main(){
    std::vector<FiguraGeometrica*> figs;
    FiguraGeometrica *pfig;
    std::ifstream fin;
    std::string s;
    fin.open("figura.txt");
    float r,g,b,a;
    int nx, ny, nz;
    int xcenter, ycenter, zcenter, raio;
    int x0, y0, z0, x1, y1, z1;
  
    while(fin.good()){
        fin >> s;
        if(fin.good()){
          std::cout << s << "\n";
          if(s.compare("dim") == 0){
            fin >> nx >> ny >> nz;
          }
          else if(s.compare("putbox") == 0){
            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
          }
          else if(s.compare("cutbox") == 0){
            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
          }
          else if(s.compare("putsphere") == 0){
            fin >> xcenter >> ycenter >> zcenter >> raio >> r >> g >> b >> a;
            figs.push_back(new PutSphere(xcenter, ycenter, zcenter, raio, r, g, b, a));
          }
          else if(s.compare("cutsphere") == 0){
            fin >> xcenter >> ycenter >> zcenter >> raio;
            figs.push_back(new CutSphere(xcenter, ycenter, zcenter, raio));
          }
        }
  }
    Sculptor *s ;
    s = new Sculptor(nx, ny, nz);
    for(int i=0; i<figs.size(); i++){
        figs[i]->draw(*s);
      //  figs[i]->draw(*s);
    }
    // s->writeOFF("saida.off");

/*    figs.push_back(new Circulo());
    figs.push_back(new Circulo());
    figs.push_back(new Reta());
    figs.push_back(new Retangulo());
    figs.push_back(new Retangulo());

    for(int i=0; i<figs.size(); i++){
        figs[i]->draw();
    }

    for(int i=0; i<figs.size(); i++){
        delete figs[i];
    }

    std::cout << "passou\n";

    Reta r;
    Retangulo rg;
    Circulo c;

    pfig = &r;
    pfig->draw();

    pfig = &c;
    pfig->draw();

    pfig = new Retangulo();
    pfig->draw();

*/
    return 0;
}