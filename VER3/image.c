#include "image.h"


timage *openImage (char * name, int width, int height)
{
	FILE *pf;
	timage *image = NULL;
	char car = '\0';
	int i = 0, j = 0, k = 0;
	unsigned char *iimage = NULL;

	/*int ***iimage = NULL;

	if ((image = (timage *)malloc(sizeof(timage))) == NULL)
	{
		printf("Insuficiente espacio de memoria.\n");
		exit(1);
	}

	if ((pf = fopen(name, "rb")) == NULL)
	{
		printf("Error: el fichero no se puede abrir\n");
		exit(1);
	}

	if((iimage = (int ***)malloc(height * sizeof(int**))) == NULL)
	{
		printf("Insuficiente espacio de memoria.\n");
		exit(1);
	}
	memset(iimage, 0, height * sizeof(int**));

	for( i = 0 ; i <height; i++)
	{
		if((iimage[i] = (int **)malloc(width * sizeof(int*))) == NULL)
		{
			printf("Insuficiente espacio de memoria.\n");
			exit(1);
		}
		memset(iimage[i], 0, width * sizeof(int*));
		for( j = 0; j < width; j++)
		{
			if((iimage[i][j] = (int *)malloc(3 * sizeof(int))) == NULL)
			{
				printf("Insuficiente espacio de memoria.\n");
				exit(1);
			}
			memset(iimage[i][j], 0, 3 * sizeof(int));
			for( k = 0; k < 3; k++)
				fread(&iimage[i][j][k], 1, 1, pf);
		}
	}*/

	if ((image = (timage *)malloc(sizeof(timage))) == NULL)
	{
		printf("Insuficiente espacio de memoria.\n");
		exit(1);
	}

	if ((pf = fopen(name, "rb")) == NULL)
	{
		printf("Error: el fichero no se puede abrir\n");
		exit(1);
	}

	if((iimage = (unsigned char *)malloc(width * height * 4 * sizeof(unsigned char))) == NULL)
	{
		printf("Insuficiente espacio de memoria.\n");
		exit(1);
	}
	memset(iimage, 0, width * height * 4 * sizeof(unsigned char));

	/*for( i = 0; i < height * width * 3; i++)
			fread(&iimage[i], 1, 1, pf);*/

	for( i = 0; i < height * width * 4; i++)
	{
		//for( j = 0; j < 3; j++	)
			fread(&iimage[i], 1, 1, pf);
		//iimage[i + j] = 125;
	}

	fclose(pf);
	
	image->height = height;
	image->width = width;
	image->image = iimage;

	//imprimir(image);


	return image;
}

void imprimir(timage *image)
{
	int i = 0, j = 0, k = 0;

/*for( i = 0 ; i < image->height ; i++ )
		for( j = 0 ; j < image->width ; j++ )
			for( k = 0 ; k < 3 ; k++ )
				printf("%d\n",image->image[i][j][k]);*/
	for( i = 0; i < image->height * image->width * 4; i++)
	{
		printf("%d\n", image->image[i]);
		system("pause");
	}
} 
