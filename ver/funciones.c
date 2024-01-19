#include "funciones.h"
#include "cube.h"
#include "ground.h"
#include "lights.h"
#include "sphere.h"

GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 10.0 };
GLfloat mat_emission[] = {0.0, 0.0, 0.0, 1.0};

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity ();  

	glTranslatef(0.0, 0.0, -5.0);

	Light1();
	Light2();

	glPushMatrix();
		AssignArray4f(mat_emission, 1.0, 1.0, 1.0, 0.0);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		glTranslatef(1.5, 1.5, 1.5);
		glutSolidSphere(0.1 , 20.0, 20.0);
	glPopMatrix();

	glPushMatrix();
		AssignArray4f(mat_emission, 0.0, 0.0, 1.0, 0.0);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		glTranslatef(-2.0, 1.0, 1.0);
		glutSolidSphere(0.1 , 20.0, 20.0);
	glPopMatrix();

	glPushMatrix();
		AssignArray4f(mat_diffuse, 0.0, 0.1, 0.0, 0.0);
		AssignArray4f(mat_emission, 0.0, 0.0, 0.0, 1.0 );
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		glTranslatef(1.0,1.0,-1.0);
		glutSolidSphere(1.0 , 200.0, 200.0);
	glPopMatrix();

	glPushMatrix();

		//glRotatef ( 45, 1.0, 0.0, 0.0 ); 
		//glRotatef ( -45, 0.0, 1.0, 0.0 );
		
		/*glTranslatef(0.0, 3.0, -10.0);
		glRotatef ( 45, 1.0, 0.0, 0.0 ); 
		glRotatef ( -45, 0.0, 1.0, 0.0 );*/
		//glRotatef ( 45, 0.0, 0.0, 1.0 );

		//glTranslatef(transX, transY, transZ);

		glRotated	( (GLdouble) spinxface, 1.0, 0.0, 0.0 ) ;
		glRotated	( (GLdouble) spinyface, 0.0, 1.0, 0.0 ) ;

		//glRotatef	( rotateZ, 0.0, 0.0, 0.1);

		//printf("%d", rotateZ);

		glCallList(1);

		//glutSolidCube(2.0);

	glPopMatrix();

	glFlush ();
	glutSwapBuffers();
}

void Init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glEnable(GL_DEPTH_TEST);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_LIGHT1);
   //glEnable(GL_LIGHT2);
   //glEnable(GL_LIGHT3);

   //GLfloat light_model_ambient[] = { 0.0, 0.0, 0.0, 1.0 };

   //glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE );
   //glLightModelfv( GL_LIGHT_MODEL_AMBIENT, light_model_ambient );
   //glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE );

   createCube(1);
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
	case 114:
		rotateX = rotateX + FACTORGIRO;
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
	//printf("%d",key);
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

