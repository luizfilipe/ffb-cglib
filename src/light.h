#ifndef LIGHT_H
#define LIGHT_H

#include "ffb_cglib.h"

typedef struct
{
    Point3df translation;
    Colorf ambient;
    Colorf diffuse;
    Colorf specular;
} Light;

Light initLight(const Point3df translation, const Colorf ambient, const Colorf diffuse, const Colorf specular)
{
    Light l;
    l.translation = translation;
    l.ambient = ambient;
    l.diffuse = diffuse;
    l.specular = specular;
    
    return l;
}

Light* newLight(const Point3df translation)
{
    Light* light = (Light*) malloc(sizeof(Light));
    *light = initLight(translation, initColorf(1,1,1,1), initColorf(1,1,1,1), initColorf(1,1,1,1));
    
    return light;
}

#endif
