#ifndef BASIC2D_H
#define BASIC2D_H

#include "display.h"

#define WINDOW_X 1200
#define WINDOW_Y 700


void drawLine(int,int,int,int,Color color=White);
void drawLine(x_yCoordinate,x_yCoordinate,Color color=White);
void drawPolygon(x_yCoordinate,x_yCoordinate,x_yCoordinate,Color color = White);
void drawPolygon(x_yCoordinate,x_yCoordinate,
                 x_yCoordinate,x_yCoordinate,Color color= White);


class Edge {
public:
    Color Color1, Color2;
    int X1, Y1, X2, Y2,Z1,Z2;
    Edge(x_yCoordinate c1,const Color &, x_yCoordinate c2,const Color &);
};

class Span {
public:
    Color Color1,Color2;
    int X1, X2 , Z1 , Z2;
    Span(int x1,const Color &color1, int x2,const Color &color2);
};


class Rasterizer {
public:
    float A,B,C,D;
    x_yCoordinate n;
    float k;
    float depth;
    float z[1200][700];
    Rasterizer(){}
    //{for(int i=0;i<1200;i++){for(int j=0;j<700;j++){z[i][j]=0;}}}
    void DrawSpan(const Span &span, int y);
    void DrawSpansBetweenEdges(const Edge &e1, const Edge &e2);
    void clearZbuffer();
    void DrawTriangle(x_yCoordinate,const Color &color1,x_yCoordinate,const Color &color2,x_yCoordinate,const Color &color3);
};

#endif // BASIC2D_H
