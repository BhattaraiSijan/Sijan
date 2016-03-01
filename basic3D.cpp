#include "basic3D.h"

x_y_zCoordinate L(1,1,1);

x_y_zCoordinate V(0,0,100);
Color shadow(0.1,0.2,0.1);

Rasterizer r;
void drawLine(x_y_zCoordinate c1, x_y_zCoordinate c2)
{
    drawLine(_3D_2D(c1),_3D_2D(c2));
}

void drawPolygon(x_y_zCoordinate c1, x_y_zCoordinate c2, x_y_zCoordinate c3)
{
    drawPolygon(_3D_2D(c1),_3D_2D(c2),_3D_2D(c3));
}

void drawPolygon(x_y_zCoordinate c1, x_y_zCoordinate c2, x_y_zCoordinate c3, x_y_zCoordinate c4)
{
    drawPolygon(_3D_2D(c1),_3D_2D(c2),_3D_2D(c3),_3D_2D(c4));
}


void DrawTriangle(x_y_zCoordinate c1,Color color1,x_y_zCoordinate c2,Color color2,x_y_zCoordinate c3,Color color3)
{
    x_y_zCoordinate V1 = c2-c1;
    x_y_zCoordinate V2 = c3-c2;
    float d = (L-(c1+c2+c3)/3).magnitude;
    //float dist=1/(1+0.1*d+0.1*d*d);
    x_y_zCoordinate N = V1.crossProduct(V2).getUnitVector();

    float Ns = 32.0;
    x_y_zCoordinate H = (L+V).getUnitVector();
    float I = 0.8*0.6+(0.5)*(0.6)*(N.dotProduct(L.getUnitVector()));//+(0.5)*(0.4)*pow(N.dotProduct(H),Ns);

    //r.DrawTriangle(_3D_2D(c1),color1,_3D_2D(c2),color2,_3D_2D(c3),color3);
    r.DrawTriangle(_3D_2D(c1),color1*I,_3D_2D(c2),color2*I,_3D_2D(c3),color3*I);
}

void draw3D(x_y_zCoordinate Vertices[],int faces_size, Faces Faces[],int each_size,Color c)
{
    if(each_size==2)
    {
        for(int i=0;i<faces_size;i++)
        {
            drawLine(Vertices[(int)Faces[i].w],Vertices[(int)Faces[i].x]);
        }
    }
    if(each_size==3)
    {
        for(int i=0;i<faces_size;i++)
        {
            Color c1(170/255.0, 140/255.0, 189/255.0),cabin(253/255.0, 253/255.0, 18/255.0),
                    c3(0.8,0.78,0.8),jhyal(0.81,0.875,0.94);
            Color boom(1,1,0),hook(0.9,0.9,0.7),sup(210/255.0, 200/255.0, 100/255.0),t(0.81,0.875,0.94);

            /*if(i<17959){DrawTriangle(Vertices[(int)Faces[i].w],c1,Vertices[(int)Faces[i].x]
                        ,c1,Vertices[(int)Faces[i].y],c1);}
            else if(i<59329 && i>21773 ){
                DrawTriangle(Vertices[(int)Faces[i].w],cabin,Vertices[(int)Faces[i].x]
                        ,cabin,Vertices[(int)Faces[i].y],cabin);}
            else if(i<65274 && i>84425 ){
                DrawTriangle(Vertices[(int)Faces[i].w],jhyal,Vertices[(int)Faces[i].x]
                        ,jhyal,Vertices[(int)Faces[i].y],jhyal);}
            else if(i>125160 ){
                DrawTriangle(Vertices[(int)Faces[i].w],boom,Vertices[(int)Faces[i].x]
                        ,boom,Vertices[(int)Faces[i].y],boom);}
            else if(i<99898 && i>93443 ){
                DrawTriangle(Vertices[(int)Faces[i].w],hook,Vertices[(int)Faces[i].x]
                        ,hook,Vertices[(int)Faces[i].y],hook);}
            else if((i>59329 && i< 63865) || (i>84425 && i<88934) || (i>88934 && i<93443) || (i>116115 &&i<125160)){
                DrawTriangle(Vertices[(int)Faces[i].w],sup,Vertices[(int)Faces[i].x]
                        ,sup,Vertices[(int)Faces[i].y],sup);}
            else
                DrawTriangle(Vertices[(int)Faces[i].w],c3,Vertices[(int)Faces[i].x]
                        ,c3,Vertices[(int)Faces[i].y],c3);*/
                //drawShadow(Vertices[(int)Faces[i].w],Vertices[(int)Faces[i].x]
                  //      ,Vertices[(int)Faces[i].y]);
            DrawTriangle(Vertices[(int)Faces[i].w],c,Vertices[(int)Faces[i].x]
                    ,c,Vertices[(int)Faces[i].y],c);
            //drawPolygon(Vertices[(int)Faces[i].w],Vertices[(int)Faces[i].x],Vertices[(int)Faces[i].y]);
            //0      - 17959  crawler
            //17959  - 19025  wire44
            //19025  - 20434  wire22
            //20434  - 21773  wire2
            //21773  - 59329  cabin
            //59329  - 63865  sup1
            //63865  - 65274  wire11
            //65274  - 84425  jhyal
            //84425  - 88934  sup4
            //88934  - 93443  sup2
            //93443  - 99898  hook
            //99898  - 101444 wire4
            //101444 - 102990 wire3
            //102990 - 104329 wire1
            //104329 - 115049 wiresup
            //115049 - 116115 wire33
            //116115 - 125160 sup
            //125160          boom

        }
    }
    if(each_size==4)
    {
        for(int i=0;i<faces_size;i++)
        {
            drawPolygon(Vertices[(int)Faces[i].w],Vertices[(int)Faces[i].x],Vertices[(int)Faces[i].y],Vertices[(int)Faces[i].z]);
        }
    }
}


void drawShadow(x_y_zCoordinate c1, x_y_zCoordinate c2, x_y_zCoordinate c3)
{
    float shad[4][4] = {{1,0,0,0},{0,1,0,0},
                        {-L.x/L.z,-L.y/L.z,0,0},{0,0,0,1}};
    matrix S(shad);
    DrawTriangle(S*c1,shadow,S*c2,shadow,S*c3,shadow);
}


void sphere::create(int radius)
{
    for (int i=0;i<Total_Points;i++)
    {
        // using last bit to alternate,+band number (which band)
        x_angle=(float)(i&1)+(i>>Band_Power);

        /* (i&Band_Mask)>>1 == Local Y value in the band
         (i>>Band_Power)*((Band_Points/2)-1) == how many bands
          have we processed?
         Remember - we go "right" one value for every 2 points.
          i>>bandpower - tells us our band number*/

        y_angle=(float)((i&Band_Mask)>>1)+((i>>Band_Power)*(Sections_In_Band));

        x_angle*=(float)Section_Arc/2.0f; // remember - 180° x rot not 360
        y_angle*=(float)Section_Arc;

        float x = radius*sin(x_angle)*sin(y_angle);
        float y = radius*cos(x_angle);
        float z =  radius*sin(x_angle)*cos(y_angle);
        Vertices[i] = {x,y,z};
    }
}

void sphere::draw()
{
    Color c1(1,0,0),c2(0.3,0.6,0),c3(1,1,0);
    for(int i=0;i<Total_Points-2;i++)
    {
        drawPolygon(Vertices[i],Vertices[i+1],Vertices[i+2],c3);

        //DrawTriangle(Vertices[i],c1,Vertices[i+1],c1,Vertices[i+2],c1);
    }

}

