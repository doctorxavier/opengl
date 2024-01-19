#include "cube.h"

void createCube(int nList)
{
	GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_diffuse[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_shininess[] = { 0.0 };
	GLfloat mat_emission[] = {0.0, 0.0, 0.0, 1.0};
	GLint i;
	glNewList(nList, GL_COMPILE);

		/*//glPushAttrib(GL_ALL_ATTRIB_BITS);
		
		//AssignArray4f(mat_ambient, 0.0, 0.0, 1.0, 1.0);
		AssignArray4f(mat_diffuse, 1.0, 0.0, 0.0, 1.0);
		AssignArray4f(mat_specular, 1.0, 1.0, 1.0, 1.0);
		AssignArray4f(mat_emission, 0.0, 0.0, 0.0, 1.0);

		//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, 50.0);*/

		//glBlendFunction(GL_ONE, GL_ZERO);

		for(i=0; i < 12; i++) 
		{
			glBegin(GL_POLYGON);
			glNormal3fv(createNormals(&cubeVertex[cubeIndices[i][0]][0], 
				&cubeVertex[cubeIndices[i][1]][0],
				&cubeVertex[cubeIndices[i][2]][0]));
				glVertex3fv(&cubeVertex[cubeIndices[i][0]][0]);
				glVertex3fv(&cubeVertex[cubeIndices[i][1]][0]);
				glVertex3fv(&cubeVertex[cubeIndices[i][2]][0]);
			glEnd();
		}
			
		//glPopAttrib();

	glEndList(); 
}