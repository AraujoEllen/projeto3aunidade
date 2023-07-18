#include "sculptor.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
  std::cout <<"Alo";
  
  nx = _nx; ny = _ny; nz = _nz;
  int i, j; 
  
  //alocacao dinamica da matriz 3D
  v = new Voxel**[nx]; //1a dimensao da matriz 
  
  for(i = 0; i < nx; i++){
    v[i] = new Voxel*[ny]; //2a dimensao da matriz
  }
  
  for(i = 0; i < nx; i++){
    for(j = 0; j < ny; j++){
      v[i][j] = new Voxel[nz]; //3a dimensao da matriz
    }
  }
}

//implementacao do destrutor da classe 
Sculptor::~Sculptor(){
  int i, j;

  //liberando a memoria alocada
  for(i = 0; i < nx; i++){
    for(j = 0; j < ny; j++){
      delete [] v[i][j]; //libera a ultima sequencia alocada
    }  
  }  
  
  for(i = 0; i < nx; i++){
    delete [] v[i]; //libera a penultima sequencia alocada
  } 
  
  delete v; //libera a primeira sequencia alocada
}
   
//define a cor e a transparencia atual do desenho
void Sculptor::setColor(float r, float g, float b, float alpha){
  if (r < 0 || g < 0 || b < 0 || alpha < 0) {
    std::cout<<"Erro!";
  } 
  else {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = alpha;
  }
}

//ativa o voxel na posicao (x,y,z) atribuindo cor e transparencia
void Sculptor::putVoxel(int x, int y, int z){
  if (x < 0 || y < 0 || z < 0 || x >= nx || y >= ny || z >= nz) {
    return;
  }
  else{
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
  }
}
    
//desativa o voxel na posicao (x,y,z)
void Sculptor::cutVoxel(int x, int y, int z){
   if (x < 0 || y < 0 || z < 0 || x >= nx || y >= ny || z >= nz) {
    return;
  }

  v[x][y][z].show = false;
}
  
//ativa uma sequencia de voxels nos intervalos definidos
//abaixo, atribuindo cor e transparencia
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
  for(int x = x0; x <= x1; x++){
    for (int y = y0; y <= y1; y++){
      for (int z = z0; z <= z1; z++){
        Sculptor::putVoxel(x, y, z);
      }
    }
  }  
}

//desativa uma sequencia de voxels
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
  for(int x = x0; x <= x1; x++){
    for (int y = y0; y <= y1; y++){
      for (int z = z0; z <= z1; z++){
        Sculptor::cutVoxel(x, y, z);
      }
    }
  } 
}

//ativa todos os voxels que satizfazem a equacao 
//da esfera, atribuindo cor e transparencia
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
  //equacao da esfera
  // (x-x0)^2 + (y-y0)^2 + (z-zo)^2 = raio^2
  // x0, y0, z0 (centro)
  int i, j, k;
  
  for(i = 0; i < nx; i++){
    for(j = 0; j < ny; j++){
      for(k = 0; k < nz; k++){
        if (((pow(i-xcenter, 2))+(pow(j-ycenter, 2))+(pow(k-zcenter, 2))) < (pow(radius, 2))) {
          Sculptor::putVoxel(i,j,k);
        }
      }    
    }
  }
}

//desativa todos os voxels que satizfazem 
//a equacao da esfera
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
  int i, j, k;
  
  for(i = 0; i < nx; i++){
    for(j = 0; j < ny; j++){
      for(k = 0; k < nz; k++){
        if (((pow(i-xcenter, 2))+(pow(j-ycenter, 2))+(pow(k-zcenter, 2))) < (pow(radius, 2))) {
          Sculptor::cutVoxel(i, j, k);      
        }
      }    
    }
  } 
}

//ativa todos os voxels que satizfazem a equacao 
//da elipsoide, atribuindo cor e transparencia
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  //equacao da elipsoide
  //[(x^2)/(a^2) + (y^2)/(b^2) + (z^2)/(c^2)] = 1
  // a,b,c (raios)
  int i, j, k;
  
  for(i = 0; i < nx; i++){
    for(j = 0; j < ny; j++){
      for(k = 0; k < nz; k++){
        if (((pow(i-xcenter, 2) / pow(rx, 2))+(pow(j-ycenter, 2) / pow(ry, 2)) +
          (pow(k-zcenter, 2) / pow(rz, 2))) < 1) {
          Sculptor::putVoxel(i,j,k);
        }
      }
    }
  }  
}

//desativa todos os voxels que satizfazem 
//a equacao da elipsoide
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  int i, j, k;
  
  for(i = 0; i < nx; i++){
    for(j = 0; j < ny; j++){
      for(k = 0; k < nz; k++){
        if (((pow(i-xcenter, 2) / pow(rx, 2))+(pow(j-ycenter, 2) / pow(ry, 2)) +
          (pow(k-zcenter, 2) / pow(rz, 2))) < 1) {
          Sculptor::cutVoxel(i,j,k);
        }
      }
    }
  } 
}

//grava a escultura no formato OFF no arquivo filename
void Sculptor::writeOFF(const char* filename){
  int quant_voxel = 0, n_vertices = 0;
  int i, j, k;
  
  std::ofstream fout; //objeto para fluxo de saida
  fout.open(filename); //abre o fluxo p/ arquivo 'filename'
  
  if(!fout.is_open()){ //se nao coseguir abrir o arquivo
    std::cout<< "Erro ao abrir o arquivo!" << "\n"; //mostra a mensagem
    exit(1);
  }

  //percorre todas as dimensoes e verifica os voxels ativos
  for(i = 0; i < nx; i++){
    for(j = 0; j < ny; j++){
      for(k = 0; k < nz; k++){
        if((v[i][j][k].show)){
          quant_voxel++; //guarda o numero de voxels ativos
        }
      }
    }
  }
  
  fout<<"OFF\n"; //define OFF na primeira linha
  fout<< quant_voxel*8 <<" "<< quant_voxel*6 <<" "<< "0\n";
  //exibe a quantidade total de faces, vertices e arestas
  
  //define as coordenadas dos vértices do cubo
  for(i = 0; i < nx; i++){
    for(j = 0; j < ny; j++){
      for(k = 0; k < nz; k++){
        if((v[i][j][k].show)){
          fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl; // P0
          fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl; // P1
          fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl; // P2
          fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl; // P3
          fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl; // P4
          fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl; // P5
          fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl; // P6
          fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl; // P7
        }
      }
    }
  }
  
  quant_voxel=0; //reseta a quantidade de voxels
  fout << std::fixed;
  fout << std::setprecision(2);
  
  for(i = 0; i < nx; i++){
    for(j = 0; j < ny; j++){
      for(k = 0; k < nz; k++){
        if((v[i][j][k].show)){
          n_vertices = quant_voxel*8;
          
          fout << "4"
               << " " << n_vertices + 0 << " " << n_vertices + 3 << " "
               << n_vertices + 2 << " " << n_vertices + 1 << " " << v[i][j][k].r
               << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
               << v[i][j][k].a << std::endl;
          fout << "4"
               << " " << n_vertices + 4 << " " << n_vertices + 5 << " "
               << n_vertices + 6 << " " << n_vertices + 7 << " " << v[i][j][k].r
               << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
               << v[i][j][k].a << std::endl;
          fout << "4"
               << " " << n_vertices + 0 << " " << n_vertices + 1 << " "
               << n_vertices + 5 << " " << n_vertices + 4 << " " << v[i][j][k].r
               << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
               << v[i][j][k].a << std::endl;
          fout << "4"
               << " " << n_vertices + 0 << " " << n_vertices + 4 << " "
               << n_vertices + 7 << " " << n_vertices + 3 << " " << v[i][j][k].r
               << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
               << v[i][j][k].a << std::endl;
          fout << "4"
               << " " << n_vertices + 3 << " " << n_vertices + 7 << " "
               << n_vertices + 6 << " " << n_vertices + 2 << " " << v[i][j][k].r
               << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
               << v[i][j][k].a << std::endl;
          fout << "4"
               << " " << n_vertices + 1 << " " << n_vertices + 2 << " "
               << n_vertices + 6 << " " << n_vertices + 5 << " " << v[i][j][k].r
               << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
               << v[i][j][k].a << std::endl;
        
          quant_voxel++;
        }
      }
    }
  }

  fout.close(); //fecha o fluxo
}