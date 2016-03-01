#include <iostream>
#include "GL/freeglut.h"

#include "color.h"
#include "string"
#include "basic3D.h"
#include "vector.h"
#include "loader.h"
#include "matrix.h"
#include "transformation3D.h"
#include "unistd.h"

#define WINDOW_X 1200
#define WINDOW_Y 700

using namespace std;

void keyboard_event(unsigned char ,int,int);
void special_keyboard(int ,int ,int);
void mouse_event(int,int,int,int);

sphere sph;
sphere light;
Object o;
Object boom;
Object hook;
Object rem;
extern Rasterizer r;
x_y_zCoordinate look_from;
static x_y_zCoordinate kaka(0,0,0);

matrix T = translate(x_y_zCoordinate(25,0,0));
matrix T2 = translate(x_y_zCoordinate(-25,0,0));
matrix UP = translate(x_y_zCoordinate(0,20,0));
matrix DOWN = translate(x_y_zCoordinate(0,-20,0));
matrix IN = translate(x_y_zCoordinate(0,0,-20));
matrix OUT = translate(x_y_zCoordinate(0,0,20));

matrix XR = rotate_xaxis(-10);
matrix YR = rotate_yaxis(10);
matrix ZR = rotate_zaxis(10);

static matrix RR,MM,NN;

matrix SCY = scale(x_y_zCoordinate(1,1.5,1));
matrix SCH = scale(x_y_zCoordinate(1.2,1.2,1.2));
matrix SCL = scale(x_y_zCoordinate(0.8,0.8,0.8));
matrix SCE = scale(x_y_zCoordinate(48,48,48));

matrix SCS = translate(x_y_zCoordinate(420,-295,0));

matrix rames = translate(x_y_zCoordinate(0.009533,23.997164,240.490788));
//light
x_y_zCoordinate ligh(-432,-100,-117);
matrix LL = translate(ligh);

static bool set = false;

matrix YY = translate(x_y_zCoordinate(0,-250,0));
matrix LLL = scale(x_y_zCoordinate(0.5,0.5,0.5));
matrix YYY = rotate_yaxis(75);
matrix TTTT = translate(x_y_zCoordinate(0,-20,0));
matrix LLLL = translate(x_y_zCoordinate(0,20,0));
void rotatee();
void display()
{

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (WINDOW_X,WINDOW_Y);
    glutInitWindowPosition (90,0);
    glutCreateWindow ("KAKA_GL");
    glClearColor (0.8, 0.72, 0.97, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WINDOW_X/2, WINDOW_X/2, -WINDOW_Y/2, WINDOW_Y/2, -WINDOW_X/2, WINDOW_X/2);
    glClear (GL_COLOR_BUFFER_BIT);
    glPointSize(1);

    o.loadOBJ("/home/ezer/Documents/Qt/CGproject/Models/crawler1.obj");
    rem.loadOBJ("/home/ezer/Documents/Qt/CGproject/Models/rem1.obj");
    boom.loadOBJ("/home/ezer/Documents/Qt/CGproject/Models/boom1.obj");
    hook.loadOBJ("/home/ezer/Documents/Qt/CGproject/Models/hook1.obj");

    /*rem.TF1 = x_y_zCoordinate(0,0,+113.8);
    rem.TF2 = x_y_zCoordinate(-0,0,-113.8);

    rem.RA1 = x_y_zCoordinate(0,-13.45,-133.8);
    rem.RA2 = x_y_zCoordinate(0,+13.45,-133.8);*/

    rem.TF1 = x_y_zCoordinate(0,0,0);

    rem.RA1 = x_y_zCoordinate(0,0,0);
    rem.RA2 = x_y_zCoordinate(0,1,0);

    RR = rotate_oaxis(rem.RA1,rem.RA2,30);
    NN = translate(kaka);
    MM = translate(x_y_zCoordinate(-kaka.x,-kaka.y,-kaka.z));

    //light
    light.create(20);
    for(unsigned int i=0;i<light.Total_Points;i++)
    {
        light.Vertices[i] = LL*light.Vertices[i];
    }
    //light.draw();

    /*for(unsigned int i=0;i<o.face_size;i++)
    {
        o.vertices[i] =SCS*SCE*YYY*o.vertices[i];
    }*/
    for(unsigned int i=0;i<o.face_size;i++)
    {
        o.vertices[i] =rames*LLL*o.vertices[i];
    }
    for(unsigned int i=0;i<rem.face_size;i++)
    {
        rem.vertices[i] =rames*LLL*rem.vertices[i];
    }
    for(unsigned int i=0;i<boom.face_size;i++)
    {
        boom.vertices[i] =rames*LLL*boom.vertices[i];
    }
    for(unsigned int i=0;i<=hook.face_size;i++)
    {
        hook.vertices[i] =rames*LLL*hook.vertices[i];
    }
    hook.vertices[hook.face_size].display();
    glEnd();
    glFlush ();
    glutSwapBuffers();
    glutSpecialFunc(special_keyboard);
    glutKeyboardFunc(keyboard_event);
    glutDisplayFunc(display);
    //glutMouseFunc(mouse_event);
    glutMainLoop();
    return 0;
}

void keyboard_event(unsigned char key,int x,int y)
{

    glClear(GL_COLOR_BUFFER_BIT);
    r.clearZbuffer();

    x+=0;y+=0;
    DrawTriangle(x_y_zCoordinate(-450,0,3000),Color(1,1,0),x_y_zCoordinate(-600,-350,-1000),
                 Color(0,1,0),x_y_zCoordinate(600,-350,-1000),Color(0,1,1));
    DrawTriangle(x_y_zCoordinate(-450,0,3000),Color(1,1,0),x_y_zCoordinate(600,0,-1000),
                 Color(0,1,0),x_y_zCoordinate(600,-350,-1000),Color(0,1,1));
    light.draw();
    for(unsigned int i=0;i<hook.face_size;i++){
    if ((hook.vertices[i].x > ligh.x -10 && hook.vertices[i].x < ligh.x +10) && (hook.vertices[i].y > ligh.y -10
       && hook.vertices[i].y < ligh.y +10)&& (hook.vertices[i].z > ligh.z -10 && hook.vertices[i].z < ligh.z +10))
    {
        set = true;
    }}
    //c1.create();

    switch(key)
    {
    case 'o':
    {
        for(unsigned int i=0;i<hook.face_size;i++)
        {
            hook.vertices[i] =TTTT*hook.vertices[i];
        }
        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));

        break;
    }
    case'i':
    {
        if(set==true){
            for(unsigned int i=0;i<light.Total_Points;i++)
            {
                light.Vertices[i]=LLLL*light.Vertices[i];
            }}

            for(unsigned int i=0;i<hook.face_size;i++)
            {
                hook.vertices[i] =LLLL*hook.vertices[i];
            }

        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));
        break;
    }


    case 'q':
    {
        /* for(unsigned int i=0;i<sph.Total_Points;i++)
        {
            sph.Vertices[i] = IN*sph.Vertices[i];
        }
        //drawLine(-600,0,600,0);
        //drawLine(0,350,0,-350);
        sph.draw();*/
        for(unsigned int i=0;i<o.face_size;i++)
        {
            o.vertices[i] =IN*o.vertices[i];
        }
        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));

        break;
    }
    case 'e':
    {
        /*for(unsigned int i=0;i<sph.Total_Points;i++)
        {
            sph.Vertices[i] = OUT*sph.Vertices[i];
        }
        //drawLine(-600,0,600,0);
        //drawLine(0,350,0,-350);
        sph.draw();*/
        for(unsigned int i=0;i<o.face_size;i++)
        {
            o.vertices[i] =OUT*o.vertices[i];
        }

        break;
    }
    case 'x':
    {
        /*for(int i=0;i<sph.Total_Points;i++)
        {
            sph.Vertices[i] = XR*sph.Vertices[i];
        }
        sph.draw();*/

        for(unsigned int i=0;i<o.face_size;i++)
        {
            o.vertices[i] =XR*o.vertices[i];
        }
        for(unsigned int i=0;i<rem.face_size;i++)
        {
            rem.vertices[i] =XR*rem.vertices[i];
        }
        for(unsigned int i=0;i<boom.face_size;i++)
        {
            boom.vertices[i] =XR*boom.vertices[i];
        }
        for(unsigned int i=0;i<hook.face_size;i++)
        {
            hook.vertices[i] =XR*hook.vertices[i];
        }
        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));
        cout<<"\nx";
        break;
    }
    case 'y':
    {
        /* for(int i=0;i<sph.Total_Points;i++)
        {
            sph.Vertices[i] = YR*sph.Vertices[i];

        }
        sph.draw();*/

        for(unsigned int i=0;i<o.face_size;i++)
        {
            o.vertices[i] =YR*o.vertices[i];
        }
        for(unsigned int i=0;i<rem.face_size;i++)
        {
            rem.vertices[i] =YR*rem.vertices[i];
        }
        for(unsigned int i=0;i<boom.face_size;i++)
        {
            boom.vertices[i] =YR*boom.vertices[i];
        }
        for(unsigned int i=0;i<hook.face_size;i++)
        {
            hook.vertices[i] =YR*hook.vertices[i];
        }
        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));
        cout<<"\ny";
        break;
    }
    case 'z':
    {
        /* for(int i=0;i<sph.Total_Points;i++)
        {
            sph.Vertices[i] = ZR*sph.Vertices[i];
        }

        sph.draw();*/

        for(unsigned int i=0;i<o.face_size;i++)
        {
            o.vertices[i] =ZR*o.vertices[i];
        }
        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));
        cout<<"\nz";
        break;
    }
    case 'l':
    {
        //for(int i=0;i<sph.Total_Points;i++)
        //{
        //  sph.Vertices[i] = SCL*sph.Vertices[i];
        //}
        //sph.draw();
        for(unsigned int i=0;i<o.face_size;i++)
        {
            o.vertices[i] =SCL*o.vertices[i];
        }
        for(unsigned int i=0;i<rem.face_size;i++)
        {
            rem.vertices[i] =SCL*rem.vertices[i];
        }
        for(unsigned int i=0;i<boom.face_size;i++)
        {
            boom.vertices[i] =SCL*boom.vertices[i];
        }
        for(unsigned int i=0;i<hook.face_size;i++)
        {
            hook.vertices[i] =SCL*hook.vertices[i];
        }
        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));
        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));
        cout<<"\nl";
        break;
    }
    case 'h':
    {
        /*for(int i=0;i<sph.Total_Points;i++)
        {
            sph.Vertices[i] = SCH*sph.Vertices[i];
        }
        sph.draw();*/
        for(unsigned int i=0;i<o.face_size;i++)
        {
            o.vertices[i] =SCH*o.vertices[i];
        }
        for(unsigned int i=0;i<rem.face_size;i++)
        {
            rem.vertices[i] =SCH*rem.vertices[i];
        }
        for(unsigned int i=0;i<boom.face_size;i++)
        {
            boom.vertices[i] =SCH*boom.vertices[i];
        }
        for(unsigned int i=0;i<hook.face_size;i++)
        {
            hook.vertices[i] =SCH*hook.vertices[i];
        }
        //o.draw(Color(0.3,0.2,0.3));
        //rem.draw(Color(1.0,1.2,0.1));
        //boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));
        cout<<"\nh";
        break;
    }
    case 'm':
    {
        /*for(unsigned int i=0;i<sph.Total_Points;i++)
        {
            sph.Vertices[i] = RR*sph.Vertices[i];
        }
        sph.draw();*/
        for(unsigned int i=0;i<rem.face_size;i++)
        {
            rem.vertices[i] =NN*RR*MM*rem.vertices[i];
        }
        for(unsigned int i=0;i<boom.face_size;i++)
        {
            boom.vertices[i] =NN*RR*MM*boom.vertices[i];
        }
        for(unsigned int i=0;i<=hook.face_size;i++)
        {
            hook.vertices[i] =NN*RR*MM*hook.vertices[i];
        }

        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));
        break;
    }
    case 'c':
    {
        break;
    }

    case 'p':
    {
        x_y_zCoordinate cc111(-600,-310,10),cc222(-512,310,10),cc333(0,280,10);

        x_y_zCoordinate cc11(0,0,0),cc22(480,0,0),cc33(0,350,0);

        x_y_zCoordinate cc1(0,0,10),cc2(340,0,10),cc3(0,340,10);


        Color c1(1,0,0),c2(0,1,0),c3(0,0,1);
        DrawTriangle(cc1,c3,cc2,c3,cc3,c3);
        DrawTriangle(cc11,c1,cc22,c1,cc33,c1);
        DrawTriangle(cc111,c2,cc222,c2,cc333,c2);

        //DrawTriangle();
        break;
    }
    case 'b':
    {
        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));
        setPixel(0,0,Color(1,0,0));
        break;
    }
    default:
        //drawLine(-600,0,600,0);
        //drawLine(0,350,0,-350);
         exit(-1);//terminate the program
        break; // do nothing
    }

    glFlush();
    glutSwapBuffers();
}

void special_keyboard(int key,int ,int)
{
    glClear(GL_COLOR_BUFFER_BIT);
    r.clearZbuffer();
    DrawTriangle(x_y_zCoordinate(-450,0,3000),Color(1,1,0),x_y_zCoordinate(-600,-350,-1000),
                 Color(0,1,0),x_y_zCoordinate(600,-350,-1000),Color(0,1,1));
    DrawTriangle(x_y_zCoordinate(-450,0,3000),Color(1,1,0),x_y_zCoordinate(600,0,-1000),
                 Color(0,1,0),x_y_zCoordinate(600,-350,-1000),Color(0,1,1));
    light.draw();
    switch (key)
    {
    case GLUT_KEY_DOWN:
    {
        for(unsigned int i=0;i<o.face_size;i++)
        {
            o.vertices[i] =DOWN*o.vertices[i];
        }
        for(unsigned int i=0;i<rem.face_size;i++)
        {
            rem.vertices[i] =DOWN*rem.vertices[i];
        }
        for(unsigned int i=0;i<boom.face_size;i++)
        {
            boom.vertices[i] =DOWN*boom.vertices[i];
        }
        for(unsigned int i=0;i<hook.face_size;i++)
        {
            hook.vertices[i] =DOWN*hook.vertices[i];
        }
        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));

        break;
    }
    case GLUT_KEY_UP:
    {
        for(unsigned int i=0;i<o.face_size;i++)
        {
            o.vertices[i] =UP*o.vertices[i];
        }
        for(unsigned int i=0;i<rem.face_size;i++)
        {
            rem.vertices[i] =UP*rem.vertices[i];
        }
        for(unsigned int i=0;i<boom.face_size;i++)
        {
            boom.vertices[i] =UP*boom.vertices[i];
        }
        for(unsigned int i=0;i<hook.face_size;i++)
        {
            hook.vertices[i] =UP*hook.vertices[i];
        }
        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));
        break;
    }
    case GLUT_KEY_RIGHT:
    {
        for(unsigned int i=0;i<o.face_size;i++)
        {
            o.vertices[i] =T*o.vertices[i];
        }
        for(unsigned int i=0;i<rem.face_size;i++)
        {
            rem.vertices[i] =T*rem.vertices[i];
        }
        for(unsigned int i=0;i<boom.face_size;i++)
        {
            boom.vertices[i] =T*boom.vertices[i];
        }
        for(unsigned int i=0;i<hook.face_size;i++)
        {
            hook.vertices[i] =T*hook.vertices[i];
        }
        cout<<"rotation\n";
        RR.display();
        cout<<"NNpaxadi\n";
        NN.display();
        cout<<"agadi\n";
        MM.display();
        RR = RR*T;
        MM = MM*T;
        NN = NN*T;

        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));
        break;
    }
    case GLUT_KEY_LEFT:
    {
        for(unsigned int i=0;i<o.face_size;i++)
        {
            o.vertices[i] =T2*o.vertices[i];

        }
        for(unsigned int i=0;i<rem.face_size;i++)
        {
            rem.vertices[i] =T2*rem.vertices[i];

        }
        for(unsigned int i=0;i<boom.face_size;i++)
        {
            boom.vertices[i] =T2*boom.vertices[i];
        }
        for(unsigned int i=0;i<hook.face_size;i++)
        {
            hook.vertices[i] =T2*hook.vertices[i];
        }
        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));
        break;
    }
    case GLUT_KEY_F1:
    {

    }
    default:
        o.draw(Color(0.3,0.2,0.3));
        rem.draw(Color(1.0,1.2,0.1));
        boom.draw(Color(0.8,0.9,1));
        hook.draw(Color(0.1,0,1));
        break;
    }

    glFlush();
    glutSwapBuffers();
}

void mouse_event(int button, int state, int x, int y)
{
    glClear(GL_COLOR_BUFFER_BIT);
    light.draw();
    r.clearZbuffer();
    switch(button)
    {
    case GLUT_LEFT_BUTTON:
    {
        for(unsigned int i=0;i<o.face_size;i++)
        {
            o.vertices[i] =SCH*o.vertices[i];
        }
        o.draw(Color(0.3,0.2,0.3));
        break;
    }
    case GLUT_RIGHT_BUTTON:
    {
        for(unsigned int i=0;i<o.face_size;i++)
        {
            o.vertices[i] =SCL*o.vertices[i];
        }
        o.draw(Color(0.3,0.2,0.3));
        break;
    }
    }
    glFlush();
    glutSwapBuffers();

}

void rotatee()
{
    for(unsigned int i=0;i<rem.face_size;i++)
    {
        rem.vertices[i] =NN*RR*MM*rem.vertices[i];
    }
    for(unsigned int i=0;i<boom.face_size;i++)
    {
        boom.vertices[i] =NN*RR*MM*boom.vertices[i];
    }
    for(unsigned int i=0;i<hook.face_size;i++)
    {
        hook.vertices[i] =NN*RR*MM*hook.vertices[i];
    }

    o.draw(Color(0.3,0.2,0.3));
    rem.draw(Color(1.0,1.2,0.1));
    boom.draw(Color(0.8,0.9,1));
    hook.draw(Color(0.1,0,1));
}
