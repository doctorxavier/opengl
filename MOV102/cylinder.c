#include "cylinder.h"

void createCylinder(int nList)
{
	GLUquadricObj *cylinder;

	cylinder = gluNewQuadric();

	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluQuadricNormals(cylinder, GLU_NONE);

	glNewList(nList, GL_COMPILE);
	  gluCylinder(cylinder, 0.25, 0.25, 1.0, 10, 1);
	glEndList();
}