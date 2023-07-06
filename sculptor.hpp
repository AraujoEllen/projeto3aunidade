#ifndef SCULPTOR_HPP
#define SCULPTOR_HPP

struct Voxel {
  float r,g,b; // Cores
  float a; // Transparencia
  bool show; // Mostrado ou nao
};

class Sculptor {
private:
  Voxel ***v; // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:

/*! \brief
  *  Implementação do construtor.
*/
  Sculptor(int _nx, int _ny, int _nz);

/*! \brief
  *  Implementação do destrutor.
*/
  ~Sculptor();

/*! \brief
  *  Define a cor e a transparencia atual do desenho.
*/
  void setColor(float r, float g, float b, float alpha);

/*! \brief
  *  Ativa o voxel na posicao (x,y,z) atribuindo cor e transparencia.
*/ 
  void putVoxel(int x, int y, int z);

/*! \brief
  *  Desativa o voxel na posicao (x,y,z).
*/
  void cutVoxel(int x, int y, int z);

/*! \brief
  *  Ativa uma sequencia de voxels nos intervalos definidos
  *  abaixo, atribuindo cor e transparencia.
*/ 
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

/*! \brief
  *  Desativa uma sequencia de voxels.
*/ 
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

/*! \brief
  *  Ativa todos os voxels que satizfazem a equacao 
  *  da esfera, atribuindo cor e transparencia
*/
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);

/*! \brief
  *  Desativa todos os voxels que satizfazem 
  *  a equacao da esfera.
*/
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

/*! \brief
  *  Ativa todos os voxels que satizfazem a equacao 
  *  da elipsoide, atribuindo cor e transparencia
*/
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

/*! \brief
  *  Desativa todos os voxels que satizfazem 
  *  a equacao da elipsoide.
*/
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

/*! \brief
  *  Grava a escultura no formato OFF no arquivo filename.
*/  
  void writeOFF(const char* filename);
};

#endif // SCULPTOR.HPP