#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
#include <GL/glu.h>
#include <iostream>

#include "color.h"

#define PI 3.1429

class x_y_zCoordinate;

class x_yCoordinate
{
public:
    float x,y,z=1,m;
    x_yCoordinate();
    x_yCoordinate(float,float,float c=1);
    x_yCoordinate(x_y_zCoordinate);
    x_yCoordinate scale(float);

    float dotProduct(x_yCoordinate v);
    x_yCoordinate crossProduct(x_yCoordinate v);
    x_yCoordinate getUnitVector();
    x_yCoordinate operator +(const x_yCoordinate &c) const;
    x_yCoordinate operator -(const x_yCoordinate &c) const;

    void display(){
        std::cout<<"("<<x<<","<<y<<","<<")"<<std::endl;
    }
};

class x_y_zCoordinate
{
public:
    float x, y, z, p;
    Color color;
    float magnitude;
    x_y_zCoordinate();
    x_y_zCoordinate(float, float, float, float d=1,Color c=Color(1,1,1,1));

    x_y_zCoordinate scale(float);

    float dotProduct(x_y_zCoordinate v);
    x_y_zCoordinate crossProduct(x_y_zCoordinate v);
    x_y_zCoordinate getUnitVector();
    x_y_zCoordinate operator +(const x_y_zCoordinate &c) const;
    x_y_zCoordinate operator -(const x_y_zCoordinate &c) const;
    x_y_zCoordinate operator /(float f) const;

    void display(){
        std::cout<<"("<<x<<","<<y<<","<<z<<")"<<p<<std::endl;
    }

};

class Faces
{
public:
    int w,x,y,z;
    Faces();
    Faces(float);
    Faces(float,float);
    Faces(float,float,float);
    Faces(float,float,float,float);
    //Faces(float,float,float,float,float);
    //Faces(float,float,float,float,float,float);

    void display()
    {
        std::cout<<std::endl<<"("<<w<<","<<x<<","<<y<<","<<z<<")";
    }
};

#endif // VECTOR_H
