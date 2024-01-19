#include "map.h"

void createMap(int nList)
{
	//GLint i, j;
/*	glNewList(nList, GL_COMPILE);

		for(i=0, j = 0; i <5; i+=2, j++) 
		{
			glEnable( GL_TEXTURE_2D );
			glBindTexture(GL_TEXTURE_2D, texName2);
			glBegin(GL_POLYGON);
				
				glNormal3fv(createNormals(&mapVertex[mapIndex[i][0]][0], &mapVertex[mapIndex[i][1]][0],&mapVertex[mapIndex[i][2]][0]));
				
				glTexCoord2d( mapTexVertex[j][0][0], mapTexVertex[j][0][1]);
				glVertex3fv(&mapVertex[mapIndex[i][0]][0]);
				glTexCoord2d( mapTexVertex[j][1][0], mapTexVertex[j][1][1] );
				glVertex3fv(&mapVertex[mapIndex[i][1]][0]);
				glTexCoord2d( mapTexVertex[j][2][0], mapTexVertex[j][2][1] );
				glVertex3fv(&mapVertex[mapIndex[i][2]][0]);

				glTexCoord2d( mapTexVertex[j][2][0], mapTexVertex[j][2][1] );
				glVertex3fv(&mapVertex[mapIndex[i + 1][0]][0]);
				glTexCoord2d( mapTexVertex[j][3][0], mapTexVertex[j][3][1] );
				glVertex3fv(&mapVertex[mapIndex[i + 1][1]][0]);
				glTexCoord2d( mapTexVertex[j][0][0], mapTexVertex[j][0][1] );
				glVertex3fv(&mapVertex[mapIndex[i + 1][2]][0]);

			glEnd();
			glDisable( GL_TEXTURE_2D );
		}
	glEndList();*/ 
}