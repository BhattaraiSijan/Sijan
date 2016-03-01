#ifndef BASIC3D_H
#define BASIC3D_H

#define White Color(1.0,1.0,1.0,1.0)

#include "basic2D.h"


void draw3D(x_y_zCoordinate Vertices[],int faces_size,Faces Faces[],int each_face,Color c=White);
void drawLine(x_y_zCoordinate, x_y_zCoordinate);
void drawPolygon(x_y_zCoordinate, x_y_zCoordinate, x_y_zCoordinate);
void drawPolygon(x_y_zCoordinate, x_y_zCoordinate, x_y_zCoordinate, x_y_zCoordinate);
void drawShadow(x_y_zCoordinate c1,x_y_zCoordinate c2,x_y_zCoordinate c3);
void DrawTriangle(x_y_zCoordinate c1,Color color1,x_y_zCoordinate c2,Color color2,x_y_zCoordinate c3,Color color3);

class sphere
{
public:
    const static int Band_Power = 6;
    const static int Band_Points = 64;
    const static int Band_Mask = 62;
    const static int Sections_In_Band = ((Band_Points/2)-1);
    const static int Total_Points = (Sections_In_Band*Band_Points);
    const static double Section_Arc = (6.28/Sections_In_Band);
    float x_angle;
    float y_angle;

    x_y_zCoordinate Vertices[2000];
    Faces faces[2000];

    void create(int radius);
    void draw();
};

#endif // BASIC3D_H
