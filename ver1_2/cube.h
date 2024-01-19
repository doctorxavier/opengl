#if !defined ( _CUBE_H_ )
#define _CUBE_H

#include <GL/glut.h>
#include "funciones.h"

static GLfloat cubeVertex[8][3] = {
	{ -1.0f, -1.0f, 1.0f}, 
	{ -1.0f, 1.0f, 1.0f}, 
	{ 1.0f, 1.0f, 1.0f}, 
	{ 1.0f, -1.0f, 1.0f}, 
	{ 1.0f, -1.0f, -1.0f}, 
	{ 1.0f, 1.0f, -1.0f}, 
	{ -1.0f, 1.0f, -1.0f}, 
	{ -1.0f, -1.0f, -1.0f}
};


static GLint cubeIndices[12][3] = {
	{2, 1, 0}, 
	{0, 3, 2},
	{2, 3, 5},
	{5, 6, 2}, 
	{4, 5, 3},
	{3, 0, 4},
	{4, 7, 6},
	{6, 5, 4}, 
	{1, 2, 6},
	{6, 7, 1},
	{0, 1, 7}, 
	{7, 4, 0}, 
	 
	
};

void createCube(int nList);

#endif