#include "transformation3D.h"

void translate(x_y_zCoordinate P[], int size, x_y_zCoordinate t)
{
    for(int i=0;i<size;i++)
    {
        float translation[4][4] = {{1,0,0,t.x},{0,1,0,t.y},{0,0,1,t.z},{0,0,0,1}};
        matrix T(translation);
        *(P+i)=T**(P+i);
    }
}


matrix translate(x_y_zCoordinate translation_vector)
{
    float translation[4][4] = {{1,0,0,translation_vector.x},{0,1,0,translation_vector.y},{0,0,1,translation_vector.z},{0,0,0,1}};
    matrix T(translation);
    return (T);
}

matrix rotate_xaxis(float angle)
{
    float thita = angle*PI/180;
    float rotation_x[4][4] = {{1,0,0,0},{0,(float)cos(thita),(float)-sin(thita),0},{0,(float)sin(thita),(float)cos(thita),0},{0,0,0,1}};
    return (matrix(rotation_x));
}

matrix rotate_yaxis(float angle)
{
    float thita = angle*PI/180;
    float rotation_y[4][4] = {{(float)cos(thita),0,(float)sin(thita),0},{0,1,0,0},{(float)-sin(thita),0,(float)cos(thita),0},{0,0,0,1}};
    return (matrix(rotation_y));
}

matrix rotate_zaxis(float angle)
{
    float thita = angle*PI/180;
    float rotation_z[4][4] = {{(float)cos(thita),(float)-sin(thita),0,0},{(float)sin(thita),(float)cos(thita),0,0},{0,0,1,0},{0,0,0,1}};
    return (matrix(rotation_z));
}

matrix rotate_oaxis(x_y_zCoordinate c1,x_y_zCoordinate c2, float angle)
{
    float thita = angle*PI/180;
    x_y_zCoordinate v(c2-c1);
    //x_y_zCoordinate u = v.getUnitVector();

    //float d = sqrt(u.y*u.y+u.z*u.z);
    //float alpha = acos(u.z/d);
    //float beta = acos(d);
    //std::cout<<"mama"<<alpha<<"    "<<beta<<"mama";
    //stepwise rotation
    matrix T1 = translate(x_y_zCoordinate(-c1.x,-c1.y,-c1.z));//step 1
    //matrix R2a = rotate_xaxis(alpha);//step 2a
    //matrix R2b = rotate_yaxis(beta);//step 2b
    //matrix R3 = rotate_zaxis(thita);//step 3
    //matrix R4a = rotate_xaxis(-alpha);//step 4a
    //matrix R4b = rotate_yaxis(-beta);//step 4b
    matrix T5 = translate(c1);//step 5
    //return (T5*R4b*R4a*R3*R2b*R2a*T1);
    float cosA2 = cos(thita/2.0);
    float sinA2 = sin(thita/2.0);
    float a = sinA2*(v.x)/v.magnitude;
    float b = sinA2*(v.y)/v.magnitude;
    float c = sinA2*(v.z)/v.magnitude;
    float mat[4][4] = {{1.0-2*b*b-2*c*c, 2*a*b-2*cosA2*c, 2*a*c+2*cosA2*b, 0},
                       {2*a*b+2*cosA2*c, 1.0-2*a*a-2*c*c, 2*b*c-2*cosA2*a, 0},
                       {2*a*c-2*cosA2*b, 2*b*c+2*cosA2*a, 1.0-2*a*a-2*b*b, 0},
                       {0              ,              0,              0,   1}};
    matrix matt(mat);
    return(T5*matt*T1);
}


matrix scale(x_y_zCoordinate scaling_factor)
{
    float scaling[4][4] = {{scaling_factor.x,0,0,0},{0,scaling_factor.y,0,0},{0,0,scaling_factor.z},{0,0,0,1}};
    return (matrix(scaling));
}
