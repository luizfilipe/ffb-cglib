#ifndef MATERIAL_H
#define MATERIAL_H

#include "ffb_cglib.h"

typedef struct
{
    Colorf ambient;
    Colorf diffuse;
    Colorf specular;
    Colorf emissive;
    GLfloat shininess;
} Material;

Material initMaterial(const Colorf ambient, const Colorf diffuse, const Colorf specular, const Colorf emissive, const GLfloat shininess)
{
    Material m;
    m.ambient = ambient;
    m.diffuse = diffuse;
    m.specular = specular;
    m.emissive = emissive;
    m.shininess = shininess;
    
    return m;
}

Material* newMaterial()
{
    Material* m = (Material*) malloc(sizeof(Material));
    *m = initMaterial(initColorf(.2,.2,.2,1), initColorf(.8,.8,.8,1), initColorf(0,0,0,1), initColorf(0,0,0,1), 0);
    
    return m;
}
/*
Material* newMaterial(const Colorf ambient, const Colorf difusse, const Colorf specular, const Colorf emissive, const GLfloat shininess)
{
  Material* m = (Material*) malloc(sizeof(Material));
  *m = initMaterial(ambient, difusse, specular, emissive, shininess);
  
  return m;
};
*/

void applyMaterial(const Material* mat)
{
    GLfloat materialAmbient[] = {mat->ambient.R, mat->ambient.G, mat->ambient.B, mat->ambient.A};
	GLfloat materialDiffuse[] = {mat->diffuse.R, mat->diffuse.G, mat->diffuse.B, mat->diffuse.A};
	GLfloat materialSpecular[] = {mat->specular.R, mat->specular.G, mat->specular.B, mat->specular.A};
	GLfloat materialEmission[] = {mat->emissive.R, mat->emissive.G, mat->emissive.B, mat->emissive.A};;

    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
	glMaterialfv(GL_FRONT, GL_EMISSION, materialEmission);
	glMaterialf(GL_FRONT, GL_SHININESS, mat->shininess);
}

#endif
