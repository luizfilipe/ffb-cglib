#ifndef CIRCLE_H
#define CIRCLE_H

#include "ffb_cglib.h"

typedef struct
{
    Point2di Center;
    GLfloat Radius;
    Colorf Color;
}Circle2d;

Circle2d initCircle2d(Point2di center, const GLfloat radius)
{
    Circle2d c;
    c.Center = center;
    c.Radius = radius;
    c.Color = initColorf(1,1,1,1);
    
    return c;
};

void circlePlotPoints(Point2di circCtr, Point2di circPt)
{
    glBegin(GL_POINTS);
    Point2di p;

    p = initPoint2di(circCtr.X + circPt.X, circCtr.Y + circPt.Y);
	setPixel(p);

    p = initPoint2di(circCtr.X - circPt.X, circCtr.Y + circPt.Y);
	setPixel(p);

    p = initPoint2di(circCtr.X + circPt.X, circCtr.Y - circPt.Y);
	setPixel(p);

    p = initPoint2di(circCtr.X - circPt.X, circCtr.Y - circPt.Y);
	setPixel(p);

    p = initPoint2di(circCtr.X + circPt.Y, circCtr.Y + circPt.X);
	setPixel(p);

    p = initPoint2di(circCtr.X - circPt.Y, circCtr.Y + circPt.X);
	setPixel(p);

    p = initPoint2di(circCtr.X + circPt.Y, circCtr.Y - circPt.X);
	setPixel(p);

    p = initPoint2di(circCtr.X - circPt.Y, circCtr.Y - circPt.X);
	setPixel(p);
	glEnd();
};

void drawCircle2d(const Circle2d* circle)
{
    Point2di center = circle->Center;
    GLfloat radius = circle->Radius;

    GLint p = 1 - radius;

    Point2di pAux = initPoint2di(0, radius);

    Colorf c = circle->Color;
    glColor3f(c.R, c.G, c.B);

	circlePlotPoints(center, pAux);

	while(pAux.X < pAux.Y)
	{
		pAux.X++;

		if(p<0)
		{
			p += 2 * pAux.X + 1;
        }
		else
		{
			pAux.Y--;
			p += 2 * (pAux.X - pAux.Y) + 1;
		}

		circlePlotPoints(center, pAux);
	}
};

#endif // CIRCLE_H
