#ifndef MODEL3D_H
#define MODEL3D_H

#include "ffb_cglib.h"

typedef struct
{
    Mesh* mesh;
    Material* material;
} Model3d;

Model3d initModel3d(Mesh* mesh, Material* material)
{
    Model3d model;
    model.mesh = mesh;
    model.material = material;
    
    return model;
};

Model3d* newModel3d(Mesh* mesh, Material* material)
{
    Model3d* model = (Model3d*) malloc(sizeof(Model3d));
    *model = initModel3d(mesh, material);
    
    return model;
};

void drawModel3d(const Model3d* model)
{
    applyMaterial(model->material);
    drawMesh(model->mesh);
};

#endif
