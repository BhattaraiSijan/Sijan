#ifndef TRANSFORMATION3D_H
#define TRANSFORMATION3D_H

#include "matrix.h"

void translate(x_y_zCoordinate P[],int,x_y_zCoordinate t);

matrix translate(x_y_zCoordinate translation_vector);//this will return the 4x4 translation matrix accor. to given vector

matrix rotate_xaxis(float angle);//this will return the 4x4 matrix to rotate along x-axis
matrix rotate_yaxis(float angle);//this will return the 4x4 matrix to rotate along y-axis
matrix rotate_zaxis(float angle);//this will return the 4x4 matrix to rotate along z-axis

matrix rotate_oaxis(x_y_zCoordinate c1,x_y_zCoordinate c2, float angle);

matrix scale(x_y_zCoordinate scaling_factor);

#endif // TRANSFORMATION3D_H
