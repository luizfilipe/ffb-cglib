#ifndef SKYBOX_H
#define SKYBOX_H

#include "ffb_cglib.h"

typedef struct
{
    Object3d* front;
    Object3d* back;
    Object3d* left;
    Object3d* right;
    Object3d* top;
    Object3d* bottom;
    Camera* camera;
}SkyBox;

SkyBox* newSkyBox(Camera* cam) {
    SkyBox* sk = (SkyBox*) malloc(sizeof(SkyBox));
    
    sk->camera = cam;
    sk->front = newObject3d(newModel3d(newMeshPlane(loadTexture("front.bmp")), newMaterial())); //0x, 0y, 500z
    sk->back = newObject3d(newModel3d(newMeshPlane(loadTexture("back.bmp")), newMaterial()));  //0x, 0y, -500z
    sk->left = newObject3d(newModel3d(newMeshPlane(loadTexture("left.bmp")), newMaterial()));  //rotaciona 90% em y, -500x
    sk->right = newObject3d(newModel3d(newMeshPlane(loadTexture("right.bmp")), newMaterial())); //rotaciona 90% em y, 500x
    sk->top = newObject3d(newModel3d(newMeshPlane(loadTexture("top.bmp")), newMaterial()));    //rotaciona 90% em x, 500y
    sk->bottom = newObject3d(newModel3d(newMeshPlane(loadTexture("bottom.bmp")), newMaterial()));//rotaciona 90% em x, -500y

    //ESCALONA TODOS PARA 1000
    sk->front->scale = initVector3df(1000, 1000, 1);
    sk->back->scale = initVector3df(1000, 1000, 1);
    sk->left->scale = initVector3df(1, 1000, 1000);
    sk->right->scale = initVector3df(1, 1000, 1000);
    sk->top->scale = initVector3df(1000, 1, 1000);
    sk->bottom->scale = initVector3df(1000, 1, 1000);

    //Executa as operações de rotação
    sk->left->rotation.Y = 270;
    sk->right->rotation.Y = 90;
    sk->top->rotation.X = -90;
    sk->back->rotation.Y = 180;
    sk->bottom->rotation.X = 90;

    return sk;
}

void drawSkyBox(SkyBox* sk) {
     
    //Executa as operações de translação
    sk->front->translation.X = sk->camera->translation.X;
    sk->front->translation.Y = sk->camera->translation.Y;
    sk->front->translation.Z = -499 + sk->camera->translation.Z;

    sk->back->translation.X = sk->camera->translation.X;
    sk->back->translation.Y = sk->camera->translation.Y;
    sk->back->translation.Z = 499 + sk->camera->translation.Z;
    
    sk->left->translation.X = -499 + sk->camera->translation.X;
    sk->left->translation.Y = sk->camera->translation.Y;
    sk->left->translation.Z = sk->camera->translation.Z;

    sk->right->translation.X = 499 + sk->camera->translation.X;
    sk->right->translation.Y = sk->camera->translation.Y;
    sk->right->translation.Z = sk->camera->translation.Z;

    sk->top->translation.X = sk->camera->translation.X;
    sk->top->translation.Y = 499 + sk->camera->translation.Y;
    sk->top->translation.Z = sk->camera->translation.Z;

    sk->bottom->translation.X = sk->camera->translation.X;
    sk->bottom->translation.Y = -499 + sk->camera->translation.Y;
    sk->bottom->translation.Z = sk->camera->translation.Z;

    glDisable(GL_LIGHTING);
    drawObject3d(sk->front);
    drawObject3d(sk->back);
    drawObject3d(sk->left);
    drawObject3d(sk->right);
    drawObject3d(sk->top);
    drawObject3d(sk->bottom);
    glEnable(GL_LIGHTING);
}

#endif

