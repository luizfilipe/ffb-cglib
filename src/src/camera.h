#ifndef CAMERA_H
#define CAMERA_H

#include "ffb_cglib.h"

typedef struct
{
    Point3df translation;
    Vector3df rotation;
    GLdouble fov;
    GLdouble aspect;
    GLdouble zNear;
    GLdouble zFar;
} Camera;

Camera initCamera(const Point3df translation, const Vector3df rotation)
{
    Camera cam;
    cam.translation = translation;
    cam.rotation = rotation;
    cam.fov = 45;
    cam.aspect = 4/3;
    cam.zNear = 0.1;
    cam.zFar = 100;
    
    return cam;
};

Camera* newCamera(const Point3df translation, const Vector3df rotation)
{
    Camera* camera = (Camera*) malloc(sizeof(Camera));
    *camera = initCamera(translation, rotation);

    return camera;
};

void drawCamera(const Camera* camera)
{
    glRotatef(-camera->rotation.X, 1, 0, 0);
    glRotatef(180 - camera->rotation.Y, 0, 1, 0);
    glRotatef(-camera->rotation.Z, 0, 0, 1);
    glTranslatef(-camera->translation.X, -camera->translation.Y, -camera->translation.Z);
};

//extras
void moveFoward(Camera* camera, const GLfloat speed)
{
    camera->translation.X -= cos(degToRad(camera->rotation.Y + 90)) * speed;
    camera->translation.Z += sin(degToRad(camera->rotation.Y + 90)) * speed;
};

void moveBackward(Camera* camera, const GLfloat speed)
{
    camera->translation.X += cos(degToRad(camera->rotation.Y + 90)) * speed;
    camera->translation.Z -= sin(degToRad(camera->rotation.Y + 90)) * speed;
};


void noseUp(Camera* camera, const GLfloat speed)
{
    Vector3df rot = camera->rotation;
     
    camera->rotation.X += sin( degToRad(rot.Y) + 90 ) * speed;
    //camera->rotation.Y += 0;
    camera->rotation.Z += cos( degToRad(rot.Y) + 90 ) * speed;
};
/*
void noseDown(Camera* camera, const GLfloat speed)
{
    camera->rotation.X += 0;
    camera->rotation.Y += 0;
    camera->rotation.Z += 0;  
};

void rollRight(Camera* camera, const GLfloat speed)
{
    camera->rotation.X += 0;
    camera->rotation.Y += 0;
    camera->rotation.Z += 0;  
};

void rollLeft(Camera* camera, const GLfloat speed)
{
    camera->rotation.X += 0;
    camera->rotation.Y += 0;
    camera->rotation.Z += 0;
};
*/

#endif
