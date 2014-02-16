#ifndef TEXTURE_H
#define TEXTURE_H

#include "ffb_cglib.h"

typedef struct
{
    GLuint width;
    GLuint height;
    char* data;
    GLuint id;
} Texture;

Texture* loadTexture(char* fileName)
{
    Texture* tex = (Texture *) malloc(sizeof(Texture));
    FILE *file;
    unsigned long size;                 // size of the image in bytes.
    unsigned long i;                    // standard counter.
    unsigned short int planes;          // number of planes in image (must be 1) 
    unsigned short int bpp;             // number of bits per pixel (must be 24)
    char temp;
    // make sure the file is there.
    if ((file = fopen(fileName, "rb"))==NULL)
    {
    	printf("File Not Found : %s\n",fileName);
    	return NULL;
    }
    
    // seek through the bmp header, up to the width/height:
    fseek(file, 18, SEEK_CUR);

    // read the width
    if ((i = fread(&tex->width, 4, 1, file)) != 1) 
    {
    	printf("Error reading width from %s.\n", fileName);
    	return NULL;
    }
    
    printf("Width of %s: %u\n", fileName, tex->width);
    
    // read the height 
    if ((i = fread(&tex->height, 4, 1, file)) != 1) 
    {
    	printf("Error reading height from %s.\n", fileName);
    	return NULL;
    }
    
    printf("Height of %s: %u\n", fileName, tex->height);
    
    // calculate the size (assuming 24 bits or 3 bytes per pixel).
    size = tex->width * tex->height * 3;

    // read the planes
    if ((fread(&planes, 2, 1, file)) != 1) 
    {
    	printf("Error reading planes from %s.\n", fileName);
    	return NULL;
    }
    
    if (planes != 1) 
    {
    	printf("Planes from %s is not 1: %u\n", fileName, planes);
    	return NULL;
    }

    // read the bpp
    if ((i = fread(&bpp, 2, 1, file)) != 1) 
    {
    	printf("Error reading bpp from %s.\n", fileName);
    	return NULL;
    }
    
    if (bpp != 24) 
    {
    	printf("Bpp from %s is not 24: %u\n", fileName, bpp);
    	return NULL;
    }
	
    // seek past the rest of the bitmap header.
    fseek(file, 24, SEEK_CUR);

    // read the data. 
    tex->data = (char*) malloc(size);
    
    if (tex->data == NULL) 
    {
    	printf("Error allocating memory for color-corrected image data");
    	return NULL;	
    }

    if ((i = fread(tex->data, size, 1, file)) != 1) 
    {
    	printf("Error reading image data from %s.\n", fileName);
    	return NULL;
    }

    for(i=0; i<size; i+=3) 
    { // reverse all of the colors. (bgr -> rgb)
    	temp = tex->data[i];
    	tex->data[i] = tex->data[i+2];
    	tex->data[i+2] = temp;
    }
    
    glGenTextures(1, &tex->id);
    glBindTexture(GL_TEXTURE_2D, tex->id);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, tex->width, tex->height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex->data);
    
    // we're done.
    return tex;
}

#endif
