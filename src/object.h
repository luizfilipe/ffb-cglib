#ifndef OBJECT_H
#define OBJECT_H

#include "ffb_cglib.h"

typedef struct
{
    Model3d* model;
    Point3df translation;
    Vector3df rotation;
    Vector3df scale;
} Object3d;

Object3d initObject3d(Model3d* model, const Point3df translation, const Vector3df rotation, const Vector3df scale)
{
    Object3d object;
    object.model = model;
    object.translation = translation;
    object.rotation = rotation;
    object.scale = scale;
    
    return object;
}

Object3d* newObject3d(Model3d* model)
{
    Object3d* object = (Object3d*) malloc(sizeof(Object3d));
    *object = initObject3d(model, initPoint3df(0,0,0), initVector3df(0,0,0), initVector3df(1,1,1));
    
    return object;
}

void drawObject3d(const Object3d* object)
{
    glPushMatrix();
    
    glTranslatef(object->translation.X, object->translation.Y, object->translation.Z);
    glScalef(object->scale.X, object->scale.Y, object->scale.Z);
    glRotatef(-object->rotation.X, 1.0f, 0.0f, 0.0f);
    glRotatef(-object->rotation.Y, 0.0f, 1.0f, 0.0f);
    glRotatef( object->rotation.Z, 0.0f, 0.0f, 1.0f);

    drawModel3d(object->model);
    
    glPopMatrix();
}

/*
        switch((int)i/4) {
            case 0:
            case 1:
                c.R = 1;
                c.G = 0;
                c.B = 0;
                break;
            case 2:
            case 3:
                c.R = 0;
                c.G = 1;
                c.B = 0;
                break;

            case 4:
            default:
                c.R = 0;
                c.G = 0;
                c.B = 1;
                break;
        }
*/

#endif // OBJECT_H
