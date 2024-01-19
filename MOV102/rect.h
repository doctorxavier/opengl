#if !defined( _RECT_H_ )
#define _RECT_H_

#include <GL/glut.h>

static GLfloat rectVertex[8][3] = {
	{ 0.0f, 0.0f, 0.0f },
	{ 0.0f, 4.0f, 0.0f },
	{ 0.0f, 0.0f, 1.0f },
	{ 0.0f, 4.0f, 1.0f },
	{ 2.0f, 0.0f, 0.0f },
	{ 2.0f, 4.0f, 0.0f },
	{ 2.0f, 0.0f, 1.0f },
	{ 2.0f, 4.0f, 1.0f },
};

static GLint rectIndex[6][4] = {
	{0,2,3,1},
	{2,6,7,3},
	{6,4,5,7},
	{4,0,1,5},
	{0,4,6,2},
	{1,3,7,5},
};

void createRect(int nList);
#endif