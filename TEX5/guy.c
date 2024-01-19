#include "guy.h"

void createGuy(int nList)
{
	GLint i;
	glNewList(nList, GL_COMPILE);
		for(i=0; i < 1698; i++) {
			glBegin(GL_POLYGON);
			/*glNormal3fv(createNormals(&vdata[OBJ_1_indices[i][0]][0], 
				&vdata[OBJ_1_indices[i][1]][0],
				&vdata[OBJ_1_indices[i][2]][0]));*/
			/*glNormal3f(-ndata[OBJ_1_indices[i][0]][0],-ndata[OBJ_1_indices[i][0]][1],-ndata[OBJ_1_indices[i][0]][2]);
			glVertex3fv(&vdata[OBJ_1_indices[i][0]][0]);
			glNormal3f(-ndata[OBJ_1_indices[i][1]][0],-ndata[OBJ_1_indices[i][1]][1],-ndata[OBJ_1_indices[i][1]][2]);
			glVertex3fv(&vdata[OBJ_1_indices[i][1]][0]);
			glNormal3f(-ndata[OBJ_1_indices[i][2]][0],-ndata[OBJ_1_indices[i][2]][1],-ndata[OBJ_1_indices[i][2]][2]);
			glVertex3fv(&vdata[OBJ_1_indices[i][2]][0]);*/
			glNormal3fv(&vdata[OBJ_1_indices[i][0]][0]);
			glVertex3fv(&vdata[OBJ_1_indices[i][0]][0]);
			glNormal3fv(&vdata[OBJ_1_indices[i][1]][0]);
			glVertex3fv(&vdata[OBJ_1_indices[i][1]][0]);
			glNormal3fv(&vdata[OBJ_1_indices[i][2]][0]);
			glVertex3fv(&vdata[OBJ_1_indices[i][2]][0]);
			glEnd();
		}

	glEndList();

}

