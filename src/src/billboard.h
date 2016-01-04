#ifndef BILLBOARD_H
#define BILLBOARD_H

#include "ffb_cglib.h"

#define PERPENDICULAR 0
#define CYLINDRICAL 1

typedef struct
{
    GLint type;
    Object3d* object;
    Camera* camera;
} Billboard;

Billboard initBillboard(const GLint type, Camera* camera, Texture* texture)
{
    Billboard billboard;
    billboard.type = type;     
    billboard.camera = camera;   
    Object3d* object = newObject3d( newModel3d(newMeshPlane(texture), newMaterial()));
    billboard.object = object;
    
    return billboard;
};

Billboard* newBillboard(const GLint type, Camera* camera, Texture* texture)
{
    Billboard* billboard = (Billboard*) malloc(sizeof(Billboard));
    *billboard = initBillboard(type, camera, texture);

    return billboard;
};

void drawBillboardPerpendicular(const Billboard* billboard)
{   
   billboard->object->rotation.X = -billboard->camera->rotation.X;
   billboard->object->rotation.Y = -billboard->camera->rotation.Y;
//   billboard->object->rotation.Z = billboard->camera->rotation.Z;
   drawObject3d(billboard->object);
};

void drawBillboardCylindrical(const Billboard* billboard)
{
    
};

void drawBillboard(const Billboard* billboard)
{
    switch(billboard->type)
    {
        case PERPENDICULAR:
            drawBillboardPerpendicular(billboard);
            break;
        
        case CYLINDRICAL:
            drawBillboardCylindrical(billboard);
            break;     
    }
};

#endif

