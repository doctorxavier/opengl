#include "funciones.h"
#include "cube.h"
#include "ground.h"
#include "lights.h"
#include "sphere.h"
#include "fog.h"

GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 10.0 };
GLfloat mat_emission[] = {0.0, 0.0, 0.0, 1.0};
GLfloat mat_color[] = {0.0, 0.0, 1.0};

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity ();  



	glTranslatef(0.0, 0.0, -5.0);

	Light1();
	Light2();
	//Fog();

	glPushMatrix();

		glTranslatef(transX, transY, transZ);

		glTranslatef(0.0,0.0,1.0);

		glRotatef ( -45, 1.0, 0.0, 0.0 ); 
		glRotatef ( 45, 0.0, 1.0, 0.0 );

		glRotated( (GLdouble) spinxface, 1.0, 0.0, 0.0 ) ;
		glRotated( (GLdouble) spinyface, 0.0, -1.0, 0.0 ) ;

		AssignArray4f(mat_diffuse, 1.0, 1.0, 1.0, 1.0);
		AssignArray4f(mat_specular, 1.0, 1.0, 1.0, 1.0);
		AssignArray4f(mat_emission, 0.0, 0.0, 0.0, 1.0);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, 50.0);

		glEnable( GL_TEXTURE_2D );
		//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
		glBindTexture(GL_TEXTURE_2D, texName);
		glBegin( GL_QUADS );
			glTexCoord2d(0.0,0.0); 
			glNormal3f(0.0,0.0,1.0);
			glVertex3f(-1.0,-1.0,0.0);
			glTexCoord2d(1.0,0.0); 
			glVertex3f(1.0,-1.0,0.0);
			glTexCoord2d(1.0,1.0); 
			glVertex3f(1.0,1.0,0.0); 
			glTexCoord2d(0.0,1.0); 
			glVertex3f(-1.0,1.0,0.0);
		glEnd();
		glDisable( GL_TEXTURE_2D );

	glPopMatrix();

	glPushMatrix();
		AssignArray4f(mat_emission, 1.0, 1.0, 1.0, 1.0);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		glTranslatef(1.0, 1.0, 3.0);
		glutSolidSphere(0.05 , 20.0, 20.0);
	glPopMatrix();

	glPushMatrix();
		AssignArray4f(mat_emission, 0.0, 0.0, 1.0, 1.0);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		glTranslatef(-2.0, 1.0, 1.0);
		glutSolidSphere(0.1 , 20.0, 20.0);
	glPopMatrix();

	//imprimir(image);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_TRUE);
	glRasterPos2i(-3,-3);
	//glDrawPixels(3, 3, GL_RGB, GL_INT, image->image);
	glDrawPixels(1024, 1024, GL_RGBA, GL_UNSIGNED_BYTE, image->image);
	glFlush ();
	glutSwapBuffers();
}

void Init(void) 
{
	int i = 0;
	glClearColor (0.0, 0.0, 0.0, 0.0);
	//glShadeModel (GL_FLAT);
	glEnable(GL_SMOOTH);
	glEnable( GL_LINE_SMOOTH );

	//glEnable(GL_BLEND); 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	/*glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);//GL_POINT_SMOOTH_HINT, 
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);*/
	//glHint(GL_POLYGON_SMOOTH_HINT,GL_NICEST); 
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);

	
	image = openImage("mifoto1024.raw", 1024, 1024);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &texName);
	glBindTexture(GL_TEXTURE_2D, texName);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->width, image->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->image);
	//gluBuild2DMipmaps( GL_TEXTURE_2D, 4, image->width, image->height, GL_RGBA, GL_UNSIGNED_BYTE, image->image );

	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPEAT);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	//glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, mat_color);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);

	/*currentCoeff = xequalzero;
	currentGenMode = GL_OBJECT_LINEAR;
	currentPlane = GL_OBJECT_PLANE;*/
	//glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	//glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	//glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	//glEnable(GL_TEXTURE_GEN_R);
	//glEnable(GL_TEXTURE_GEN_S);
	//glEnable(GL_TEXTURE_GEN_T);

	//glEnable(GL_AUTO_NORMAL);
	//glEnable(GL_NORMALIZE);



	//GLfloat light_model_ambient[] = { 0.0, 0.0, 0.0, 1.0 };

	//glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE );
	//glLightModelfv( GL_LIGHT_MODEL_AMBIENT, light_model_ambient );
	//glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE );

	createCube(1);
	//makeCheckImage();
	//createGround(1);
	//createSphere(1);

	Display();
}

void Reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w , (GLsizei) h ); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(70.0, (GLdouble) w / (GLdouble) h , 0.1, 1000.0); 
   //glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

void Keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 8:
		exit(0);
		break;
	case 71:
		rotateZ = rotateZ + FACTORGIRO;
		break;
	case 88:
		transX = transX + FACTORVISTA;
		break;
	case 89:
		transY = transY + FACTORVISTA;
		break;
	case 90:
		transZ = transZ + FACTORVISTA;
		break;
	case 100:
 		rotateY = rotateY + FACTORGIRO;
		break;
	case 103:
		rotateZ = rotateZ - FACTORGIRO;
		break;
	case 108:
		rotateX = rotateX - FACTORGIRO;
		break;
	case 'r': //
		i++;
		if(i == 55)
			i = 1;
		break;
	case 117:
		rotateY = rotateY - FACTORGIRO;
		break;
	case 120:
		transX = transX - FACTORVISTA;
		break;
	case 121:
		transY = transY - FACTORVISTA;
		break;
	case 122:
		transZ = transZ - FACTORVISTA;
		break;
	}
	glutPostRedisplay();
	//printf("%d",i);
}

void Mouse(int button, int state, int x, int y)
{

}

void Motion(int x, int y)
{
    spinyface = ( spinyface + (x - origx) ) % 360 ;
    spinxface = ( spinxface + (y - origy) ) % 360 ;
    origx = x;
    origy = y;
    glutPostRedisplay();

	//printf("x: %d\n",x);
	//printf("y: %d\n",y);
}

void PassiveMotion( int x, int y)
{	

}

void AssignArray4f(float* Array, float arg1, float arg2, float arg3, float arg4)
{
	Array[0] = arg1;
	Array[1] = arg2;
	Array[2] = arg3;
	Array[3] = arg4;
}

void AssignArray3f(float* Array, float arg1, float arg2, float arg3)
{
	Array[0] = arg1;
	Array[1] = arg2;
	Array[2] = arg3;
}

GLfloat * createNormals(GLfloat * vector1, GLfloat * vector2, GLfloat * vector3)
{
	GLfloat vectorA[3];
	GLfloat vectorB[3];
	GLfloat normalVector[3];
	GLfloat * pNormal;
	int i = 0;

	for(i = 0; i < 3; i++)
	{
		vectorA[i] = vector2[i] - vector1[i];
		vectorB[i] = vector3[i] - vector2[i];
	}

	normalVector[0] = ( (vectorA[1] * vectorB[2]) - (vectorA[2] * vectorB[1]) );
	normalVector[1] = ( (vectorA[2] * vectorB[0]) - (vectorA[0] * vectorB[2]) );
	normalVector[2] = ( (vectorA[0] * vectorB[1]) - (vectorA[1] * vectorB[0]) );

	pNormal = Normalize( normalVector );
	return pNormal;
}

GLfloat * Normalize(GLfloat * normalVector)
{
	int i = 0;
	GLfloat n = 0.0;
	GLfloat distance = ((normalVector[0] * normalVector[0]) +(normalVector[1] * normalVector[1]) +(normalVector[2] * normalVector[2]));
	if(distance >= 0)
		distance = sqrt( distance );
	for( i = 0; i < 3; i++)
	{
		n = normalVector[i];
		normalVector[i] = n / distance ;
	}
	return normalVector;
}

GLfloat * Average(GLfloat ** normalsVector, GLint size)
{
	int i = 0;

	GLfloat normal[3] = { 0.0, 0.0, 0.0 };

	i = sizeof(normalsVector);

	for( i = 0; i<size; i++)
	{
		normal[0] += normalsVector[i][0];
		normal[1] += normalsVector[i][1];
		normal[2] += normalsVector[i][2];
	}
	return Normalize(normal);

}

void drawtriangle(float *v1, float *v2, float *v3) 
{ 
   glBegin(GL_TRIANGLES); 
      glNormal3fv(v1); glVertex3fv(v1);    
      glNormal3fv(v2); glVertex3fv(v2);    
      glNormal3fv(v3); glVertex3fv(v3);    
   glEnd(); 
}

void subdivide(float *v1, float *v2, float *v3, long depth)
{
   GLfloat v12[3], v23[3], v31[3];
   GLint i;

   if (depth == 0) {
      drawtriangle(v1, v2, v3);
      return;
   }
   for (i = 0; i < 3; i++) {
      v12[i] = v1[i]+v2[i];
      v23[i] = v2[i]+v3[i];
      v31[i] = v3[i]+v1[i];
   }
   normalize(v12);
   normalize(v23);
   normalize(v31);
   subdivide(v1, v12, v31, depth-1);
   subdivide(v2, v23, v12, depth-1);
   subdivide(v3, v31, v23, depth-1);
   subdivide(v12, v23, v31, depth-1);
}

void normalize(float v[3]) {    
   GLfloat d = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]); 
   if (d == 0.0) {    
      return;
   }
   v[0] /= d; v[1] /= d; v[2] /= d; 
}

void blend(int i)
{
		switch(i)
		{
		case 1:
			glBlendFunc(GL_ZERO, GL_ONE);
			break;
		case 2:
			glBlendFunc(GL_ZERO, GL_SRC_COLOR);
			break;
		case 3:
			glBlendFunc(GL_ZERO, GL_ONE_MINUS_SRC_COLOR);
			break;
		case 4:
			glBlendFunc(GL_ZERO, GL_SRC_ALPHA);
			break;
		case 5:
			glBlendFunc(GL_ZERO, GL_ONE_MINUS_SRC_ALPHA);
			break;
		case 6:
			glBlendFunc(GL_ZERO, GL_DST_ALPHA);
			break;
		case 7:
			glBlendFunc(GL_ZERO, GL_ONE_MINUS_DST_ALPHA);
			break;
		case 8:
			glBlendFunc(GL_ONE, GL_SRC_COLOR);
			break;
		case 9:
			glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_COLOR);
			break;
		case 10:
			glBlendFunc(GL_ONE, GL_SRC_ALPHA);
			break;
		case 11:
			glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
			break;
		case 12:
			glBlendFunc(GL_ONE, GL_DST_ALPHA);
			break;
		case 13:
			glBlendFunc(GL_ONE, GL_ONE_MINUS_DST_ALPHA);
			break;
		case 14:
			glBlendFunc(GL_DST_COLOR, GL_ZERO);
			break;
		case 15:
			glBlendFunc(GL_DST_COLOR, GL_ONE);
			break;
		case 16:
			glBlendFunc(GL_DST_COLOR, GL_SRC_COLOR);
			break;
		case 17:
			glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_COLOR);
			break;
		case 18:
			glBlendFunc(GL_DST_COLOR, GL_SRC_ALPHA);
			break;
		case 19:
			glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);
			break;
		case 20:
			glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_DST_ALPHA);
			break;
		case 21:
			glBlendFunc(GL_DST_COLOR, GL_DST_ALPHA);
			break;
		case 22:
			glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
			break;
		case 23:
			glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE);
			break;
		case 24:
			glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_SRC_COLOR);
			break;
		case 25:
			glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE_MINUS_SRC_COLOR);
			break;
		case 26:
			glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_SRC_ALPHA);
			break;
		case 27:
			glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);
			break;
		case 28:
			glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_DST_ALPHA);
			break;
		case 29:
			glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE_MINUS_DST_ALPHA);
			break;
		case 30:
			glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_DST_ALPHA);
			break;
		case 31:
			glBlendFunc(GL_SRC_ALPHA, GL_ZERO);
			break;
		case 32:
			glBlendFunc(GL_SRC_ALPHA, GL_ONE);
			break;
		case 33:
			glBlendFunc(GL_SRC_ALPHA, GL_SRC_COLOR);
			break;
		case 34:
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
			break;
		case 35:
			glBlendFunc(GL_SRC_ALPHA, GL_SRC_ALPHA);
			break;
		case 36:
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			break;
		case 37:
			glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
			break;
		case 38:
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
			break;
		case 39:
			glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ZERO);
			break;
		case 40:
			glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE);
			break;
		case 41:
			glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_COLOR);
			break;
		case 42:
			glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
			break;
		case 43:
			glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
			break;
		case 44:
			glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			break;
		case 45:
			glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_DST_ALPHA);
			break;
		case 46:
			glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
			break;
		case 47:
			glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_ZERO);
			break;
		case 48:
			glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_ONE);
			break;
		case 49:
			glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_SRC_COLOR);
			break;
		case 50:
			glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_ONE_MINUS_SRC_COLOR);
			break;
		case 51:
			glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_SRC_ALPHA);
			break;
		case 52:
			glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_ONE_MINUS_SRC_ALPHA);
			break;
		case 53:
			glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_DST_ALPHA);
			break;
		case 54:
			glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_ONE_MINUS_DST_ALPHA);
			break;
		}
}

