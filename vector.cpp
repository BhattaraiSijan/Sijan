#include "vector.h"

//coordinate
x_yCoordinate::x_yCoordinate() :x(0), y(0) {}
x_yCoordinate::x_yCoordinate(float a, float b,float c) :x(a), y(b) , z(c){}
x_yCoordinate::x_yCoordinate(x_y_zCoordinate p):x(p.x),y(p.y),z(p.z),m(sqrt(x*x+y*y+z*z)){}
x_yCoordinate x_yCoordinate::operator +(const x_yCoordinate &c) const {
    return x_yCoordinate(x + c.x, y + c.y, z + c.z);
}

x_yCoordinate x_yCoordinate::operator -(const x_yCoordinate &c) const {
    return x_yCoordinate(x - c.x, y - c.y, z - c.z);
}

x_yCoordinate x_yCoordinate::scale(float a)
{
    return (x_yCoordinate(a*x,a*y,a*z));
}

x_yCoordinate x_yCoordinate::crossProduct(x_yCoordinate v)
{
    return (x_yCoordinate(y*v.z-z*v.y  ,v.x*z-x*v.z  ,x*v.y-y*v.x));
}

x_yCoordinate x_yCoordinate::getUnitVector()
{
    return (x_yCoordinate(x/m,y/m,z/m));
}

float x_yCoordinate::dotProduct(x_yCoordinate v)
{
    //float dotP = x*v.x + y*v.y+ z*v.z;
    //return dotP;
    return (float(x*v.x + y*v.y+ z*v.z));
}



x_y_zCoordinate::x_y_zCoordinate():x(0), y(0), z(0), p(1) ,magnitude(sqrt(x*x+y*y+z*z)){}
x_y_zCoordinate::x_y_zCoordinate(float a, float b, float c, float d,Color e)
    :x(a), y(b), z(c), p(d),color(e),magnitude(sqrt(x*x+y*y+z*z)) {}

x_y_zCoordinate x_y_zCoordinate::operator +(const x_y_zCoordinate &c) const {
    return x_y_zCoordinate(x + c.x, y + c.y, z + c.z);
}

x_y_zCoordinate x_y_zCoordinate::operator -(const x_y_zCoordinate &c) const {
    return x_y_zCoordinate(x - c.x, y - c.y, z - c.z);
}

x_y_zCoordinate x_y_zCoordinate::operator /(float f) const{
    return x_y_zCoordinate(x/f,y/f,z/f);
}
//faces

Faces::Faces():w(0),x(0),y(0),z(0){}
Faces::Faces(float a):w(a),x(0),y(0),z(0){}
Faces::Faces(float a,float b):w(a),x(b),y(0),z(0){}
Faces::Faces(float a,float b,float c):w(a),x(b),y(c),z(0){}
Faces::Faces(float a,float b,float c,float d):w(a),x(b),y(c),z(d){}


//x_y_zCoordinate

x_y_zCoordinate x_y_zCoordinate::scale(float a)
{
    return (x_y_zCoordinate(a*x,a*y,a*z));
}

x_y_zCoordinate x_y_zCoordinate::crossProduct(x_y_zCoordinate v)
{
    return (x_y_zCoordinate(y*v.z-z*v.y  ,v.x*z-x*v.z  ,x*v.y-y*v.x));
}

x_y_zCoordinate x_y_zCoordinate::getUnitVector()
{
    return (x_y_zCoordinate(x/magnitude,y/magnitude,z/magnitude));
}

float x_y_zCoordinate::dotProduct(x_y_zCoordinate v)
{
    //float dotP = x*v.x + y*v.y+ z*v.z;
    //return dotP;
    return (float(x*v.x + y*v.y+ z*v.z));
}
