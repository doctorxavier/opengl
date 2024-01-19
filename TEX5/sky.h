#if !defined ( _SKY_H_ )
#define _SKY_H_

#include <GL/glut.h>
#include "funciones.h"

static GLfloat skyVertex[4][3] = {
	{ -50.0, 8.0 ,-50.0},
	{ -50.0, 8.0, 50.0},
	{ 50.0, 8.0, 50.0},
	{ 50.0, 8.0, -50.0}
};

void createSky(int nList);

#endif
