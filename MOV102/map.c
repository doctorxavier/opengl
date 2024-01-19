#include "map.h"

void createMap(int nList)
{
	GLint i;
	glNewList(nList, GL_COMPILE);
		for(i=0; i < 242; i++) 
		{
			glBegin(GL_POLYGON);
			glNormal3dv(createNormals(&mapVertex[mapIndex[i][0]][0], 
				&mapVertex[mapIndex[i][1]][0],
				&mapVertex[mapIndex[i][2]][0]));
				glVertex3dv(&mapVertex[mapIndex[i][0]][0]);
				glVertex3dv(&mapVertex[mapIndex[i][1]][0]);
				glVertex3dv(&mapVertex[mapIndex[i][2]][0]);
			glEnd();
		}
	glEndList(); 
}