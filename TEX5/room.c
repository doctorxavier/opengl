#include "room.h"

void createRoom(int nList)
{
	GLint i;
	glNewList(nList, GL_COMPILE);


		for(i=0; i < 32; i++) 
		{
			glBegin(GL_POLYGON);
			glNormal3fv(createNormals(&roomVertex[roomIndex[i][0]][0], 
				&roomVertex[roomIndex[i][1]][0],
				&roomVertex[roomIndex[i][2]][0]));
				glVertex3fv(&roomVertex[roomIndex[i][0]][0]);
				glVertex3fv(&roomVertex[roomIndex[i][1]][0]);
				glVertex3fv(&roomVertex[roomIndex[i][2]][0]);
			glEnd();
		}
			
	glEndList(); 
}