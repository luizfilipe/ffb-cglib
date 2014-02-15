#ifndef COLOR_H
#define COLOR_H

#include "ffb_cglib.h"

typedef struct
{
    GLfloat R;
    GLfloat G;
    GLfloat B;
    GLfloat A;
}Colorf;

Colorf initColorf(const GLfloat red, const GLfloat green, const GLfloat blue, const GLfloat alpha)
{
    Colorf color;
    color.R = red;
    color.G = green;
    color.B = blue;
    color.A = alpha;

    return color;
};

typedef struct
{
    GLbyte R;
    GLbyte G;
    GLbyte B;
    GLbyte A;
}Colorb;

Colorb initColorb(const GLbyte red, const GLbyte green, const GLbyte blue, const GLbyte alpha)
{
    Colorb color;
    color.R = red;
    color.G = green;
    color.B = blue;
    color.A = alpha;

    return color;
};

Colorb toColorb(const Colorf color)
{
    Colorb c;
    c.R = (GLbyte)(color.R * 255);
    c.G = (GLbyte)(color.G * 255);
    c.B = (GLbyte)(color.B * 255);
    c.A = (GLbyte)(color.A * 255);

    return c;
};

Colorf toColorf(const Colorb color)
{
    Colorf c;
    c.R = (GLfloat)color.R / 255;
    c.G = (GLfloat)color.G / 255;
    c.B = (GLfloat)color.B / 255;
    c.A = (GLfloat)color.A / 255;

    return c;
};

GLfloat* toGLColorv(const Colorf color)
{
    GLfloat* c = (GLfloat*) malloc(sizeof(GLfloat) * 4);

    c[0] = color.R;
    c[1] = color.G;
    c[2] = color.B;
    c[3] = color.A;

    return c;
};

#endif // COLOR_H
