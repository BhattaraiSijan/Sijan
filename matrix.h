#ifndef MATRIX_H
#define MATRIX_H
#include "vector.h"
#include "iostream"
#define columns 4
#define rows 4

class matrix {
public:
    float mat[columns][rows];
public:
    matrix(float m[][rows]);
    matrix();
    friend const x_y_zCoordinate operator *(const matrix &m,const x_y_zCoordinate &p);
    //friend const Vector operator *(const matrix &m,const Vector &p);
    matrix operator*(matrix);
    void display(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
            std::cout<<mat[i][j]<<" ";}
            std::cout<<std::endl;
        }
    }
};

#endif // MATRIX_H
