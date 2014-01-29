#ifndef MESH_H
#define MESH_H

#include "ffb_cglib.h"

typedef struct
{
    GLuint vertexAmount;
    Vertex* vertexes;
    Texture* texture;
} Mesh;

Mesh* loadMesh(const char* meshFileName)
{
    Mesh* m = (Mesh*)malloc(sizeof(Mesh));
    
    float x, y, z, u, v;
    int numtriangles;
    FILE *filein;        // file to load the world from
    char oneline[255];

    filein = fopen(meshFileName, "rt");
    readstr(filein, oneline);
    sscanf(oneline, "NUMPOLLIES %d\n", &numtriangles);
    
    m->vertexAmount = numtriangles * 3;
    m->vertexes = (Vertex*)malloc(sizeof(Vertex) * m->vertexAmount);

    int i;

    for (i = 0; i < m->vertexAmount; i++) {
	    readstr(filein,oneline);
	    sscanf(oneline, "%f %f %f %f %f", &x, &y, &z, &u, &v);
	    m->vertexes[i] = initVertex(x, y, z, u, v);
    }

    fclose(filein);
    
    return m;
};

Mesh* newMeshCube(Texture* texture)
{
    Mesh* m = (Mesh*) malloc(sizeof(Mesh));
    m->vertexAmount = 24;
    m->vertexes = (Vertex*) malloc(sizeof(Vertex) * m->vertexAmount);
    m->texture = texture;

    // Front
    m->vertexes[0] = initVertex(-.5,  .5,  .5,  0,  1);
    m->vertexes[1] = initVertex( .5,  .5,  .5,  1,  1);
    m->vertexes[2] = initVertex( .5, -.5,  .5,  1,  0);
    m->vertexes[3] = initVertex(-.5, -.5,  .5,  0,  0);

    //Back
    m->vertexes[4] = initVertex(-.5,  .5, -.5,  0,  1);
    m->vertexes[5] = initVertex( .5,  .5, -.5,  1,  1);
    m->vertexes[6] = initVertex( .5, -.5, -.5,  1,  0);
    m->vertexes[7] = initVertex(-.5, -.5, -.5,  0,  0);
    
    //Top
    m->vertexes[8]  = initVertex(-.5,  .5,  .5,  0,  1);
    m->vertexes[9]  = initVertex( .5,  .5,  .5,  1,  1);
    m->vertexes[10] = initVertex( .5,  .5, -.5,  1,  0);
    m->vertexes[11] = initVertex(-.5,  .5, -.5,  0,  0);

    //Bottom
    m->vertexes[12] = initVertex(-.5, -.5,  .5,  0,  1);
    m->vertexes[13] = initVertex( .5, -.5,  .5,  1,  1);
    m->vertexes[14] = initVertex( .5, -.5, -.5,  1,  0);
    m->vertexes[15] = initVertex(-.5, -.5, -.5,  0,  0);

    //Left
    m->vertexes[16] = initVertex(-.5,  .5, -.5,  0,  1);
    m->vertexes[17] = initVertex(-.5,  .5,  .5,  1,  1);
    m->vertexes[18] = initVertex(-.5, -.5,  .5,  1,  0);
    m->vertexes[19] = initVertex(-.5, -.5, -.5,  0,  0);

    //Right
    m->vertexes[20] = initVertex( .5,  .5,  .5,  0,  1);
    m->vertexes[21] = initVertex( .5,  .5, -.5,  1,  1);
    m->vertexes[22] = initVertex( .5, -.5, -.5,  1,  0);
    m->vertexes[23] = initVertex( .5, -.5,  .5,  0,  0);

    return m;
};

Mesh* newMeshPlane(Texture* texture)
{
    Mesh* m = (Mesh*) malloc(sizeof(Mesh));  
    m->vertexAmount = 4;
    m->vertexes = (Vertex*) malloc(sizeof(Vertex) * m->vertexAmount);
    m->texture = texture;

    m->vertexes[0] = initVertex(-.5,  .5,  .5,  0,  1);
    m->vertexes[1] = initVertex( .5,  .5,  .5,  1,  1);
    m->vertexes[2] = initVertex( .5, -.5,  .5,  1,  0);
    m->vertexes[3] = initVertex(-.5, -.5,  .5,  0,  0);
    
    return m;
};

void drawMesh(const Mesh* mesh)
{
    if(mesh->texture)
    {
        glBindTexture(GL_TEXTURE_2D, mesh->texture->id);
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    
    Vector3df normals[6] = {initVector3df( 0, 0, 1),
                            initVector3df( 0, 0,-1),
                            initVector3df( 0, 1, 0),
                            initVector3df( 0,-1, 0),
                            initVector3df(-1, 0, 0),
                            initVector3df( 1, 0, 0)};
    
    glBegin(GL_QUADS);

    int i;
    for(i=0; i<mesh->vertexAmount; i++)
    {
        setNormal(normals[(i/4)%6]);
        drawVertex(&mesh->vertexes[i]);
    }
     
    glEnd();
};

#endif
