#include "matrix.h"

matrix::matrix(float m[][rows])
{
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            mat[i][j] = m[i][j];
        }
    }
}

matrix::matrix()
{
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            mat[i][j] = 0;
        }
    }
}

const x_y_zCoordinate operator *(const matrix &m, const x_y_zCoordinate &p)
{
    float ar[4], tem[4], sum;
    ar[0] = p.x;
    ar[1] = p.y;
    ar[2] = p.z;
    ar[3] = p.p;

    for (int i = 0; i < 4; i++) {
        sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += m.mat[i][j] * ar[j];
        }
        tem[i] = sum;
    }
    return (x_y_zCoordinate(tem[0], tem[1], tem[2], tem[3]));
}

matrix matrix::operator*(matrix x)// overloading * for multiplication
{
      matrix c;// this will hold our result
      for(int i=0;i<4;i++)
      {
          for(int j=0;j<4;j++)
          {
              c.mat[i][j]=0;
              for(int k=0;k<4;k++)
              {
                  c.mat[i][j]+=mat[i][k]*x.mat[k][j];
              }
          }
      }
      return(c);
}
