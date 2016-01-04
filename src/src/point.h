#ifndef POINT_H
#define POINT_H

#include "ffb_cglib.h"

typedef struct
{
    GLint X;
    GLint Y;
}Point2di, Vector2di;

Point2di initPoint2di(const GLint x, const GLint y)
{
    Point2di p;
    p.X = x;
    p.Y = y;
    return p;
};

Vector2di initVector2di(const GLint x, const GLint y)
{
    return initPoint2di(x, y);
};

typedef struct
{
    GLfloat X;
    GLfloat Y;
}Point2df, Vector2df;

Point2df initPoint2df(const GLfloat x, const GLfloat y)
{
    Point2df p;
    p.X = x;
    p.Y = y;
    return p;
};

Vector2df initVector2df(const GLfloat x, const GLfloat y)
{
    return initPoint2df(x, y);
};

typedef struct
{
    GLint X;
    GLint Y;
    GLint Z;
}Point3di, Vector3di;

Point3di initPoint3di(const GLint x, const GLint y, const GLint z)
{
    Point3di point;
    point.X = x;
    point.Y = y;
    point.Z = z;

    return point;
}

Vector3di initVector3di(const GLint x, const GLint y, const GLint z)
{
    return initPoint3di(x, y, z);
}

typedef struct
{
    GLfloat X;
    GLfloat Y;
    GLfloat Z;
}Point3df, Vector3df;

Point3df initPoint3df(const GLfloat x, const GLfloat y, const GLfloat z)
{
    Point3df point;
    point.X = x;
    point.Y = y;
    point.Z = z;

    return point;
}

Vector3df initVector3df(const GLfloat x, const GLfloat y, const GLfloat z)
{
    return initPoint3df(x, y, z);
}

Vector3df addVector3df(const Vector3df v1, const Vector3df v2)
{
    return initVector3df(v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z);
};

Vector3df subtractVector3df(const Vector3df v1, const Vector3df v2)
{
    return initVector3df(v1.X - v2.X, v1.Y - v2.Y, v1.Z - v2.Z); 
};

GLfloat lengthVector3df(const Vector3df v)
{
    return sqrt((v.X * v.X) + (v.Y * v.Y) + (v.Z * v.Z));
};

#endif // POINT_H
