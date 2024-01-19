#include "cylinder.h"

void createCylinder(int nList)
{
	GLUquadricObj *cylinder;

	cylinder = gluNewQuadric();

	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluQuadricNormals(cylinder, GLU_NONE);

	glNewList(nList, GL_COMPILE);
	  gluCylinder(cylinder, 0.25f, 0.25f, 1.0f, 10, 1);
	glEndList();
}