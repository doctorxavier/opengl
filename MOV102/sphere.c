#include "sphere.h"

void createSphere(GLint nList)
{
	GLint i;
	GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_diffuse[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_shininess[] = { 0.0 };
	GLfloat mat_emission[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat** normals = NULL;
	GLfloat* normal = NULL;

	normals = (GLfloat**)malloc(64 * sizeof(GLfloat*));
	normal = (GLfloat*)malloc(3 * sizeof(GLfloat));

	glNewList(nList, GL_COMPILE);

		//AssignArray4f(mat_ambient, 0.0, 0.0, 1.0, 1.0);
		AssignArray4f(mat_diffuse, 1.0, 0.0, 1.0, 1.0);
		AssignArray4f(mat_specular, 1.0, 1.0, 1.0, 1.0);
		AssignArray4f(mat_emission, 0.0, 0.0, 0.0, 1.0);

		//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		//glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
		
	/*for(i=0; i < 20; i++) 
		{
			normals[i] = createNormals(&sphereVertex[sphereIndices[i][0]][0], 
				&sphereVertex[sphereIndices[i][1]][0],
				&sphereVertex[sphereIndices[i][2]][0]);
		}

		normal = Average(normals, 20);*/
	
		/*glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);

		glBegin(GL_TRIANGLES);    
		for (i = 0; i < 20; i++) {    
		   glNormal3fv(createNormals(&sphereVertex[sphereIndices[i][0]][0], 
				&sphereVertex[sphereIndices[i][1]][0],
				&sphereVertex[sphereIndices[i][2]][0])); 
		   glVertex3fv(&sphereVertex[sphereIndices[i][0]][0]); 
		   glVertex3fv(&sphereVertex[sphereIndices[i][1]][0]); 
		   glVertex3fv(&sphereVertex[sphereIndices[i][2]][0]); 
		}
		glEnd();*/

	/*for (i = 0; i < 20; i++) 
	{ 
	   subdivide(&sphereVertex[sphereIndices[i][0]][0],       
				 &sphereVertex[sphereIndices[i][1]][0],       
				 &sphereVertex[sphereIndices[i][2]][0], 5 ); 
	}*/



	glEndList();
}
