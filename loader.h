#ifndef LOADER_H
#define LOADER_H

#include <stdio.h>
#include <cstring>
#include <basic3D.h>


class Object
{
public:
    x_y_zCoordinate vertices[2000000];
    x_y_zCoordinate TF1;
    x_y_zCoordinate RA1,RA2;
    Faces faces[2000000];
    unsigned int face_size;
    unsigned int vertices_size;
    int each_face_size;
    bool loadOBJ(const char * path,int each_face=3);
    //void set();
    void draw(Color c=White);
};







#endif // LOADER_H
