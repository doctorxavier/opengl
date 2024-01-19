#include "rect.h"

void createRect(int nList)
{
	GLint i;
	glNewList(nList, GL_COMPILE);
		for(i=0; i < 8; i++) 
		{
			glBegin(GL_QUADS);
				glVertex3fv(&rectVertex[rectIndex[i][0]][0]);
				glVertex3fv(&rectVertex[rectIndex[i][1]][0]);
				glVertex3fv(&rectVertex[rectIndex[i][2]][0]);
				glVertex3fv(&rectVertex[rectIndex[i][3]][0]);
			glEnd();
		}
			

	glEndList(); 
}