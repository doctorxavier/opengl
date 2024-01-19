#include "image.h"


timage *openImage (char * name, int width, int height)
{
	FILE *pf;
	timage *image = NULL;
	char car = '\0';
	int i = 0, j = 0, k = 0;
	unsigned char *iimage = NULL;

	if ((image = (timage *)malloc(sizeof(timage))) == NULL)
	{
		printf("Insuficiente espacio de memoria.\n");
		exit(1);
	}

	if ((pf = fopen(name, "rb")) == NULL)
	{
		printf("Error: el fichero %s no se puede abrir\n",name);
		exit(1);
	}

	if((iimage = (unsigned char *)malloc(width * height * 4 * sizeof(unsigned char))) == NULL)
	{
		printf("Insuficiente espacio de memoria.\n");
		exit(1);
	}
	memset(iimage, 0, width * height * 4 * sizeof(unsigned char));


	for( i = 0; i < height * width * 4; i++)  
			fread(&iimage[i], 1, 1, pf);

	fclose(pf);
	
	image->height = height;
	image->width = width;
	image->image = iimage;

	return image;
}
