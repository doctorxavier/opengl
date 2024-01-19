#include "sky.h"

void createSky(int nList){

	glNewList(nList, GL_COMPILE);
		glBegin(GL_QUADS);
			glNormal3fv(createNormals( skyVertex[0], skyVertex[1], skyVertex[2] ));
			glTexCoord2d(0.0,0.0);
			glVertex3fv( skyVertex[0]);
			glTexCoord2d(0.0,3.0);
			glVertex3fv( skyVertex[1]);
			glTexCoord2d(3.0,3.0);
			glVertex3fv( skyVertex[2]);
			glTexCoord2d(3.0,0.0);
			glVertex3fv( skyVertex[3]);
		glEnd();
	glEndList();
}