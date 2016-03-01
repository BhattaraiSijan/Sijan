#include "basic2D.h"

void drawLine(int x1,int y1,int x2,int y2,Color color)
{
    if((x1<=WINDOW_X/2 && x1>=-WINDOW_X/2) && (y1<=WINDOW_Y/2 && y1>=-WINDOW_Y/2)){
    float xdiff = (x2 - x1);
    float ydiff = (y2 - y1);


    if (xdiff == 0.0f && ydiff == 0.0f)
    {
        setPixel(x1, y1,color);
        return;
    }

    if (fabs(xdiff) > fabs(ydiff))
    {
        float xmin, xmax;

        // set xmin to the lower x value given
        // and xmax to the higher value
        if (x1 < x2)
        {
            xmin = x1;
            xmax = x2;
        }
        else
        {
            xmin = x2;
            xmax = x1;
        }

        // draw line in terms of y slope
        float slope = ydiff / xdiff;
        for (float x = xmin; x <= xmax; x += 1.0f)
        {
            float y = y1 + ((x - x1) * slope);
            setPixel(x, y,color);
        }
    }
    else
    {
        float ymin, ymax;

        // set ymin to the lower y value given
        // and ymax to the higher value
        if (y1 < y2)
        {
            ymin = y1;
            ymax = y2;
        }
        else
        {
            ymin = y2;
            ymax = y1;
        }

        // draw line in terms of x slope
        float slope = xdiff / ydiff;
        for (float y = ymin; y <= ymax; y += 1.0f)
        {
            float x = x1 + ((y - y1) * slope);
            setPixel(x, y,color);
        }
    }}
    else
        ;
}

void drawLine(x_yCoordinate c1,x_yCoordinate c2,Color color)
{
    drawLine(c1.x,c1.y,c2.x,c2.y,color);
}

void drawPolygon(x_yCoordinate c1, x_yCoordinate c2, x_yCoordinate c3, Color color)
{
    drawLine(c1,c2,color);
    drawLine(c2,c3,color);
    drawLine(c3,c1,color);
}

void drawPolygon(x_yCoordinate c1, x_yCoordinate c2,
                 x_yCoordinate c3,x_yCoordinate c4, Color color)
{
    drawLine(c1,c2,color);
    drawLine(c2,c3,color);
    drawLine(c3,c4,color);
    drawLine(c4,c1,color);

}



Edge::Edge(x_yCoordinate c1,const Color &color1,x_yCoordinate c2,const Color &color2){
    if (c1.y < c2.y) {
        Color1 = color1;
        X1 = c1.x;
        Y1 = c1.y;
        Z1 = c1.z;
        Color2 = color2;
        X2 = c2.x;
        Y2 = c2.y;
        Z2 = c2.z;
    } else {
        Color1 = color2;
        X1 = c2.x;
        Y1 = c2.y;
        Z1 = c2.z;
        Color2 = color1;
        X2 = c1.x;
        Y2 = c1.y;
        Z2 = c1.z;
    }
}

Span::Span( int x1,const Color &color1, int x2,const Color &color2) {
    if (x1 < x2) {
        Color1 = color1;
        X1 = x1;
        Color2 = color2;
        X2 = x2;
    } else {
        Color1 = color2;
        X1 = x2;
        Color2 = color1;
        X2 = x1;
    }
}

void Rasterizer::DrawSpan(const Span &span, int y) {
    int xdiff = span.X2 - span.X1;
    if (xdiff == 0)
        return;

    Color colordiff = span.Color2 - span.Color1;


    float factor = 0.0f;
    float factorStep = 1.0f / (float) xdiff;
    // draw each pixel in the span
    for (int x = span.X1; x < span.X2; x++) {
        depth = (-D-A*x-B*y)/C;
        if((x<=WINDOW_X/2 && x>=-WINDOW_X/2) && (y<=WINDOW_Y/2 && y>=-WINDOW_Y/2))
        {
            if(depth  < z[x+600][y+350]){
                z[x+600][y+350]=depth;
                setPixel(x, y,span.Color1 + (colordiff * factor));
            }
            else
                ;
        factor += factorStep;
    }

}
}

void Rasterizer::clearZbuffer(){
    for(int i=0;i<1200;i++)
    {
        for(int j=0;j<700;j++)
        {
            z[i][j]=99999999;
        }
    }
}

void Rasterizer::DrawSpansBetweenEdges(const Edge &e1, const Edge &e2) {
    // calculate difference between the y coordinates
    // of the first edge and return if 0

    float e1ydiff = (float) (e1.Y2 - e1.Y1);
    if (e1ydiff == 0.0f)
        return;

    // calculate difference between the y coordinates
    // of the second edge and return if 0
    float e2ydiff = (float) (e2.Y2 - e2.Y1);
    if (e2ydiff == 0.0f)
        return;

    // calculate differences between the x coordinates
    // and colors of the points of the edges
    float e1xdiff = (float) (e1.X2 - e1.X1);
    float e2xdiff = (float) (e2.X2 - e2.X1);
    Color e1colordiff = (e1.Color2 - e1.Color1);
    Color e2colordiff = (e2.Color2 - e2.Color1);

    // calculate factors to use for interpolation
    // with the edges and the step values to increase
    // them by after drawing each span
    float factor1 = (float) (e2.Y1 - e1.Y1) / e1ydiff;
    float factorStep1 = 1.0f / e1ydiff;
    float factor2 = 0.0f;
    float factorStep2 = 1.0f / e2ydiff;

    // loop through the lines between the edges and draw spans
    for (int y = e2.Y1; y < e2.Y2; y++) {
        // create and draw span
        Span span(e1.X1 + (int) (e1xdiff * factor1),e1.Color1 + (e1colordiff * factor1),
                  e2.X1 + (int) (e2xdiff * factor2),e2.Color1 + (e2colordiff * factor2));
        DrawSpan(span, y);

        // increase factors
        factor1 += factorStep1;
        factor2 += factorStep2;
    }
}

void Rasterizer::DrawTriangle(x_yCoordinate c1,const Color &color1,x_yCoordinate c2,const Color &color2
                              ,x_yCoordinate c3,const Color &color3) {

    x_yCoordinate V1 = c2-c1;
    x_yCoordinate V2 = c3-c2;
    x_yCoordinate ABC = V1.crossProduct(V2);
    //x_yCoordinate PP(0,0,1);

    //n=ABC.getUnitVector();
    //k = PP.getUnitVector().dotProduct(n);
     A = ABC.x;
     B = ABC.y;
     C = ABC.z;
     D = -A*c1.x-B*c1.y-C*c1.z;
     //k = (c1.z+c2.z+c3.z)/3;


    // create edges for the triangle
    Edge edges[3] = { Edge(c1,color1,c2,color2), Edge(c2,color2,c3,color3),Edge(c3,color3,c1,color1)};

    int maxLength = 0;
    int longEdge = 0;

    // find edge with the greatest length in the y axis
    for (int i = 0; i < 3; i++) {
        int length = edges[i].Y2 - edges[i].Y1;
        if (length > maxLength) {
            maxLength = length;
            longEdge = i;
        }
    }

    int shortEdge1 = (longEdge + 1) % 3;
    int shortEdge2 = (longEdge + 2) % 3;



    // draw spans between edges; the long edge can be drawn
    // with the shorter edges to draw the full triangle
    DrawSpansBetweenEdges(edges[longEdge], edges[shortEdge1]);
    DrawSpansBetweenEdges(edges[longEdge], edges[shortEdge2]);
}
