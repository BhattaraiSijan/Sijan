#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL/glut.h>
#include <GL/gl.h>
#include "vector.h"
#include "transformation3D.h"

#define White Color(1.0,1.0,1.0,1.0)




void setPixel(float x,float y,float r=1.0,float g=1.0,float b=1.0);

void setPixel(float x, float y,Color c);

void _3D_2D(x_y_zCoordinate P[],int size);

x_yCoordinate _3D_2D(x_y_zCoordinate P);

//x_y_zCoordinate toScreen(x_y_zCoordinate);

#endif // DISPLAY_H
