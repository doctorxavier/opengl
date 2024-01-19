#if !defined ( _IMAGE_H_ )
#define _IMAGE_H_

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct
{
	int width;
	int height;
	unsigned char *image;
}timage;

timage *openImage (char * name, int width, int height);

#endif