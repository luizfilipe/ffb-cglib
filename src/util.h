#ifndef UTIL_H
#define UTIL_H

#include "ffb_cglib.h"

#define PI 3.14159265

void setPixel(Point2di p)
{
    glVertex2i(p.X, p.Y);
};

void setPixelf(Point2df p)
{
    glVertex2f(p.X, p.Y);
};

void plotVertex(const Point3df vertex, const Point2di uv)
{
    glTexCoord2f(uv.X, uv.Y);
    glVertex3f(vertex.X, vertex.Y, vertex.Z);
};

void setNormal(const Vector3df normal)
{
    glNormal3f(normal.X, normal.Y, normal.Z);
};

int rounds(const float x)
{
    return (int)(x + 0.5f);
};

void readstr(FILE *f, char *string)
{
    do {
	fgets(string, 255, f); // read the line
    } while ((string[0] == '/') || (string[0] == '\n'));
    return;
};


GLfloat toRadians(const GLfloat degrees)
{
    return degrees * (float)PI / 180;
};

GLfloat toDegress(const GLfloat radians) {
	return radians * 180 / (float)PI;
}

void drop(void* pointer)
{
    free(pointer);
    pointer = NULL;
};

void clamp(GLfloat* var, GLfloat min, GLfloat max)
{
    if (*var > max) {
        *var = max;
    } else if (*var < min) {
        *var = min;
    }
};

char* concat(char* str1, char* str2) {
	int i, j;
	char* result = (char*)calloc(strlen(str1) + strlen(str2), sizeof(char));
	for (i = 0; str1[i]; result[i] = str1[i], i++);
	for (j = i; str2[j-i]; result[j] = str2[j-i], j++);
	result[j] = '\0';
	return result;
}

#endif // UTIL_H
