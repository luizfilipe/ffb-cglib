#ifndef VERTEX_H
#define VERTEX_H

#include "ffb_cglib.h"

typedef struct
{
    GLfloat X;
    GLfloat Y;
    GLfloat Z;
    GLfloat U;
    GLfloat V;
} Vertex;

Vertex initVertex(GLfloat x, GLfloat y, GLfloat z, GLfloat u, GLfloat v)
{
    Vertex vertex;
    
    vertex.X = x;
    vertex.Y = y;
    vertex.Z = z;

    vertex.U = u;
    vertex.V = v;
    
    return vertex;
};

void drawVertex(const Vertex* vertex) 
{    
    if(vertex)
    {
        glTexCoord2f(vertex->U, vertex->V);
        glVertex3f(vertex->X, vertex->Y, vertex->Z);
    }
};

void redefineTextureMap(Vertex* vertex, const Point2df map) {
    vertex->U = map.X;
    vertex->V = map.Y;
};

void redefineVertexCoord(Vertex* vertex, const Point3df coord) {
    vertex->X = coord.X;
    vertex->Y = coord.Y;
    vertex->Z = coord.Z;
};

#endif
