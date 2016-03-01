#include "loader.h"

bool Object::loadOBJ(const char * path,int each_face)
{
    int i=0,j=0,count=0;each_face_size=each_face;
    x_y_zCoordinate sum(0,0,0);
    printf("Loading OBJ file %s...\n", path);

    FILE * file = fopen(path, "r");
    if( file == NULL ){
        printf("Cannot open file :) \n");
        getchar();
        return false;
    }

    while( 1 ){

        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        if ( strcmp( lineHeader, "v" ) == 0 ){
            x_y_zCoordinate vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
            vertices[i] = x_y_zCoordinate(vertex.x,vertex.y,vertex.z);
            sum = sum + vertices[i];
            i++;
        }
        else if (strcmp(lineHeader, "f") == 0){
            if(each_face_size==3){
                unsigned int vertexIndex[3];
                fscanf(file, "%d %d %d\n", &vertexIndex[0], &vertexIndex[1], &vertexIndex[2]);
                faces[j] = Faces((vertexIndex[0]-1),(vertexIndex[1]-1),(vertexIndex[2]-1));j++;}

            else if(each_face_size==4){
                unsigned int vertexIndex[4];
                fscanf(file, "%d %d %d %d\n", &vertexIndex[0], &vertexIndex[1], &vertexIndex[2],&vertexIndex[3]);
                faces[j] = Faces((vertexIndex[0]-1),(vertexIndex[1]-1),(vertexIndex[2]-1),(vertexIndex[3]-1));j++;
            }
        }
    }
    face_size = j;
    vertices_size=i;
    vertices[j]=x_y_zCoordinate(sum.x/i,sum.y/i,sum.z/i);
    return true;
}


void Object::draw(Color c)
{
    draw3D(vertices,face_size,faces,each_face_size,c);
}
//7925 - 21755
