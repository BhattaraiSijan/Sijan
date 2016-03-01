#include "display.h"

//projection perspective
float zprp = -5000;
float zvp=0;
float dp=zprp-zvp;
x_y_zCoordinate lookfrom_point(0,0,1);
x_y_zCoordinate lookat_point(0,0,0);
x_y_zCoordinate lookup_vector(0,1,0);

void setPixel(float x, float y, float r, float g, float b)
{
    glColor3f(r,g,b);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}
void setPixel(float x, float y,Color c)
{
    setPixel(x,y,c.R,c.G,c.B);
}


/*void _3D_2D(x_y_zCoordinate P[],int size)
{
    for(int i=0;i<size;i++)
    {
        float h=(viewing::zprp-P[i].z)/viewing::dp;
        float perspective[4][4] = {{1/h,0,0,0},{0,1/h,0,0},{0,0,1,0},{0,0,0,1}};
        matrix Tpersp(perspective);
        *(P+i)=Tpersp**(P+i);
    }
}*/

x_yCoordinate _3D_2D(x_y_zCoordinate P)
{

    x_y_zCoordinate N = (lookfrom_point-lookat_point);
    x_y_zCoordinate n = N.getUnitVector();

    x_y_zCoordinate u = (lookup_vector.crossProduct(N)).getUnitVector();

    x_y_zCoordinate v = (n.crossProduct(u));
    static float camera[4][4] = {{u.x,u.y,u.z,0},
                          {v.x,v.y,v.z,0},
                          {n.x,n.y,n.z,0},
                          {0,0,0,1}};
    matrix T = translate(lookfrom_point);
    matrix R(camera);

    float h=(zprp-P.z)/dp;
    float perspective[4][4] = {{1/h,0,0,0},{0,1/h,0,0},{0,0,1,0},{0,0,0,1}};
    matrix Tpersp(perspective);
    return (Tpersp*R*T*P);
    //return (Tpersp*P);
}
