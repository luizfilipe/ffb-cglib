#ifndef LINE_H
#define LINE_H

#include "ffb_cglib.h"

typedef struct
{
    Point2di Start;
    Point2di End;
    Colorf Color;
} Line2di;

Line2di initLine2di(const Point2di start, const Point2di end)
{
    Line2di line;
    line.Start = start;
    line.End = end;
    line.Color = initColorf(1,1,1,1);

    return line;
};

void drawLineDDA(const Line2di* line)
{
    Point2di start = line->Start;
    Point2di end = line->End;
    Vector2di delta = initVector2di(end.X - start.X, end.Y - start.Y);
    int steps;

    if(fabs(delta.X) > fabs(delta.Y))
        steps = fabs(delta.X);
    else
        steps = fabs(delta.Y);

    Vector2df increment = initVector2df((float)delta.X/(float)steps, (float)delta.Y/(float)steps);

    glBegin(GL_POINTS);
    Colorf c = line->Color;
    glColor3f(c.R, c.G, c.B);

    Point2df pAux = initPoint2df(start.X, start.Y);
    Point2di pixel = initPoint2di(rounds(pAux.X), rounds(pAux.Y));
    setPixel(pixel);

    int k = 0;
    for(; k<steps; k++)
    {
        pAux.X += increment.X;
        pAux.Y += increment.Y;

        pixel = initPoint2di(rounds(pAux.X), rounds(pAux.Y));
        setPixel(pixel);
    }
    
    glEnd();
};

void drawLineBreseham(const Line2di* line)
{
    Point2di start = line->Start;
    Point2di end = line->End;

    Vector2di delta = initVector2di(fabs(end.X - start.X), fabs(end.Y - start.Y));

    int p = 2 * delta.Y - delta.X;
    int twoDy = 2 * delta.Y;
    int twoDyMinusDx = 2 * (delta.Y - delta.X);

    Point2di pAux;

    if(start.X > end.X)
    {
        pAux.X = end.X;
        pAux.Y = end.Y;
        end.X = start.X;
    }
    else
    {
        pAux.X = start.X;
        pAux.Y = start.Y;
    }

    glBegin(GL_POINTS);
    Colorf c = line->Color;
    glColor3f(c.R, c.G, c.B);

    Point2di pixel = pAux;
    setPixel(pixel);

    while(pAux.X < end.X)
    {
        pAux.X++;

        if(p < 0)
        {
            p += twoDy;
        }
        else
        {
            pAux.Y++;
            p += twoDyMinusDx;
        }

        pixel = pAux;
        setPixel(pixel);
    }
    
    glBegin(GL_POINTS);
};

void drawLineStrip(const Line2di* line)
{
    glBegin(GL_LINE_STRIP);

    setPixel(line->Start);
    setPixel(line->End);

    glFlush();

    glEnd();
};

#endif // LINE_H
