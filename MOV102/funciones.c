#include "funciones.h"

GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 10.0 };
GLfloat mat_emission[] = {0.0, 0.0, 0.0, 1.0};
GLfloat mat_color[] = {0.0, 0.0, 1.0};

char moveForward = 0 ;
char moveRewind = 0 ;
char moveLeft = 0 ;
char moveRight = 0;
char turnLeft = 0 ;
char turnRight = 0 ;

void rotatedx(GLdouble ang, GLdouble *vx, GLdouble *vy, GLdouble *vz)
{
	static double ang_ant = 0.0;
	double angle = 0.0;

	double Vector[] = { 0.0, 0.0, 0.0, 1.0};
	double VectorR[] = { 0.0, 0.0, 0.0, 0.0};

	double Rx[4][4] = {
		{1.0, 0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0, 0.0},
		{0.0, 0.0, 1.0, 0.0},
		{0.0, 0.0, 0.0, 1.0}};

		angle = ((ang * PI * 2.0) / 360.0);

		Vector[0]= *vx;
		Vector[1]= *vy;
		Vector[2]= *vz;

		Rx[1][1]= cos(angle);
		Rx[1][2]= sin(angle);
		Rx[2][1]= -sin(angle);
		Rx[2][2]= cos(angle);

		multM4x1(VectorR, Vector, Rx);
		*vx = VectorR[0];
		*vy = VectorR[1];
		*vz = VectorR[2];
}

void rotatedy(GLdouble ang, GLdouble *vx, GLdouble *vy, GLdouble *vz)
{
	static double ang_ant = 0.0;
	double angle = 0.0;

	double Vector[] = { 0.0, 0.0, 0.0, 1.0};
	double VectorR[] = { 0.0, 0.0, 0.0, 0.0};

	double Ry[4][4] = {
		{1.0, 0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0, 0.0},
		{0.0, 0.0, 1.0, 0.0},
		{0.0, 0.0, 0.0, 1.0}};

		angle = ((ang * PI * 2.0) / 360.0);

		Vector[0]= *vx;
		Vector[1]= *vy;
		Vector[2]= *vz;

		Ry[0][0]= cos(angle);
		Ry[0][2]= -sin(angle);
		Ry[2][0]= sin(angle);
		Ry[2][2]= cos(angle);

		multM4x1(VectorR, Vector, Ry);
		*vx = VectorR[0];
		*vy = VectorR[1];
		*vz = VectorR[2];
}

void rotatedz(GLdouble ang, GLdouble *vx, GLdouble *vy, GLdouble *vz)
{
	static double ang_ant = 0.0;
	double angle = 0.0;

	double Vector[] = { 0.0, 0.0, 0.0, 1.0};
	double VectorR[] = { 0.0, 0.0, 0.0, 0.0};

	double Rz[4][4] = {
		{1.0, 0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0, 0.0},
		{0.0, 0.0, 1.0, 0.0},
		{0.0, 0.0, 0.0, 1.0}};

		angle = ((ang * PI * 2.0) / 360.0);

		Vector[0]= *vx;
		Vector[1]= *vy;
		Vector[2]= *vz;

		Rz[0][0]= cos(angle);
		Rz[0][1]= sin(angle);
		Rz[1][0]= -sin(angle);
		Rz[1][1]= cos(angle);

		multM4x1(VectorR, Vector, Rz);
		*vx = VectorR[0];
		*vy = VectorR[1];
		*vz = VectorR[2];
}

void translated(GLdouble *vx, GLdouble *vy, GLdouble *vz, GLdouble transX, GLdouble transY, GLdouble transZ)
{
	double Vector[] = { *vx, *vy, *vz, 1.0};
	double VectorR[] = { 0.0, 0.0, 0.0, 0.0};
	static double transXant = 0.0, transYant = 0.0, transZant = 0.0;

	double Matrix[4][4] = {
		{1.0, 0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0, 0.0},
		{0.0, 0.0, 1.0, 0.0},
		{transX, transY , transZ, 1.0}};

	multM4x1(VectorR, Vector, Matrix);

	*vx = VectorR[0];
	*vy = VectorR[1];
	*vz = VectorR[2];
	transXant = transX;
	transYant = transY;
	transZant = transZ;
}

void multM4x4(double Matrix[4][4], double Matrix1[4][4], double Matrix2[4][4])
{
	int i = 0,j = 0;
	for(j = 0; j < 4; j++)
		for(i = 0; i < 4; i++)
			Matrix[j][i] = ((Matrix1[j][0] * Matrix2[0][i]) + 
			(Matrix1[j][1] * Matrix2[1][i]) + 
			(Matrix1[j][2] * Matrix2[2][i]) + 
			(Matrix1[j][3] * Matrix2[3][i]));
}

void multM4x1(double Matrix[4], const double Matrix1[4], const double Matrix2[4][4])
{
	int i = 0;
	for(i = 0; i < 4; i++)
			Matrix[i] = ((Matrix1[0] * Matrix2[0][i]) + (Matrix1[1] * Matrix2[1][i]) + (Matrix1[2] * Matrix2[2][i]) + (Matrix1[3] * Matrix2[3][i]));
}


void Display(void)
{
	int   newCount;
    char    buf[20];
    int   i, len;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();  

	Light1();
	Light2();

	//glTranslatef( 0.0f, ((fabs(spinxface) - 90.0) / 90.0) , ((-spinxface / 90.0) - 1) * 4);

	glTranslated( 0.0f, 0.0f, -5.0f );

	glPushMatrix();
		glRotated(spinxface , 1.0, 0.0, 0.0 );
		glRotated( -90.0, 1.0, 0.0, 0.0);
		glDisable(GL_LIGHTING);
		glColor3d( 0.0f, 1.0f, 0.0f);
		glCallList(cylinder);
		glEnable(GL_LIGHTING);
	glPopMatrix();

 	glPushMatrix();

		glRotated( spinxface , 1.0, 0.0, 0.0 );
		glRotated( spinyface, 0.0, 1.0, 0.0 );

		glTranslated(-transX, -transY, -transZ);

		glPushMatrix();
			glTranslated( transEnemyX, transEnemyY, transEnemyZ);
			glRotated( -90.0, 1.0, 0.0, 0.0);
			glDisable(GL_LIGHTING);
			glColor3f( 1.0f, 1.0f, 0.0f);
			glCallList(cylinder);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glTranslated( transEnemyX2, transEnemyY2, transEnemyZ2);
			glRotated( -90.0, 1.0, 0.0, 0.0);
			glDisable(GL_LIGHTING);
			glColor3f( 0.0f, 1.0f, 1.0f);
			glCallList(cylinder);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glTranslated( transEnemyX3, transEnemyY3, transEnemyZ3);
			glRotated( -90.0, 1.0, 0.0, 0.0);
			glDisable(GL_LIGHTING);
			glColor3f( 1.0f, 0.0f, 1.0f);
			glCallList(cylinder);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glTranslated( transEnemyX4, transEnemyY4, transEnemyZ4);
			glRotated( -90.0, 1.0, 0.0, 0.0);
			glDisable(GL_LIGHTING);
			glColor3f( 1.0f, 1.0f, 1.0f);
			glCallList(cylinder);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glTranslated( transEnemyX5, transEnemyY5, transEnemyZ5);
			glRotated( -90.0, 1.0, 0.0, 0.0);
			glDisable(GL_LIGHTING);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glCallList(cylinder);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		AssignArray4f(mat_diffuse, 0.0, 1.0, 0.0, 1.0);
		AssignArray4f(mat_specular, 1.0, 1.0, 1.0, 1.0);
		AssignArray4f(mat_emission, 0.0, 0.0, 0.0, 1.0);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, 90.0);

		glBegin(GL_LINES);
			glVertex3f(10000.0, 0.0, 0.0);
			glVertex3f(-10000.0, 0.0, 0.0);
			glVertex3f(0.0, 10000.0, 0.0);
			glVertex3f(0.0, -10000.0, 0.0);
			glVertex3f(0.0, 0.0, 10000.0);
			glVertex3f(0.0, 0.0, -10000.0);
		glEnd();

		AssignArray4f(mat_diffuse, 1.0, 0.0, 0.0, 1.0);
		AssignArray4f(mat_specular, 1.0, 1.0, 1.0, 1.0);
		AssignArray4f(mat_emission, 0.0, 0.0, 0.0, 1.0);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, 90.0);

		glCallList(map);

	glPopMatrix();

    newCount = glutGet(GLUT_ELAPSED_TIME);
    frameCount++;
    if ((newCount - lastCount) > 1000) {
        fpsRate = (int) ((10000.0f / (newCount - lastCount)) * frameCount);
        lastCount = newCount;
        frameCount = 0;
    }


        glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);
        glDisable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_FOG);
        glDisable(GL_BLEND);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        glOrtho(0, 100, 0, 100, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

		sprintf(buf,"%3d.%d fps", fpsRate / 10, fpsRate % 10);
        glColor3f(1.0f, 1.0f, 0.0f);
        glRasterPos2i(10, 10);
        len = strlen(buf);
        for (i = 0; i < len; i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buf[i]);

		sprintf(buf,"X: %.2lf", transX);
		glRasterPos2i(30, 10);
        len = strlen(buf);
		for (i = 0; i < len; i++)
		    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buf[i]);


		sprintf(buf,"Y: %.2lf", transY);
		glRasterPos2i(50, 10);
        len = strlen(buf);
		for (i = 0; i < len; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buf[i]);

		sprintf(buf,"Z: %.2lf", transZ);
		glRasterPos2i(70, 10);
        len = strlen(buf);
		for (i = 0; i < len; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buf[i]);

		sprintf(buf,"dis: %.4lf", distance);
		glRasterPos2i(10, 30);
        len = strlen(buf);
		for (i = 0; i < len; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buf[i]);

		sprintf(buf,"x: %.2lf", inter[0]);
		glRasterPos2i(30, 30);
        len = strlen(buf);
		for (i = 0; i < len; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buf[i]);

		sprintf(buf,"y: %.2lf", inter[1]);
		glRasterPos2i(50, 30);
        len = strlen(buf);
		for (i = 0; i < len; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buf[i]);

		sprintf(buf,"z: %.2lf", inter[2]);
		glRasterPos2i(70, 30);
        len = strlen(buf);
		for (i = 0; i < len; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buf[i]);

		sprintf(buf,"col: %d", colision);
		glRasterPos2i(10, 50);
        len = strlen(buf);
		for (i = 0; i < len; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buf[i]);

		sprintf(buf,"spiny: %.4lf", spinyEnemy);
		glRasterPos2i(30, 50);
        len = strlen(buf);
		for (i = 0; i < len; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buf[i]);

		sprintf(buf,"vida: %.2lf", life);
		glRasterPos2i(10, 70);
        len = strlen(buf);
		for (i = 0; i < len; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buf[i]);

        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();
        glPopAttrib();

	glFlush();  
	glutSwapBuffers();
}

void Init(void) 
{
	glClearColor (0.0, 0.0, 0.5, 0.0);
	glShadeModel (GL_SMOOTH);

	glEnable(GL_SMOOTH);
	glEnable( GL_LINE_SMOOTH );

	glEnable(GL_BLEND); 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	glPolygonMode(GL_FRONT, GL_SMOOTH);
	glPolygonMode(GL_BACK, GL_LINE);

	cylinder = glGenLists(1);
	room = glGenLists(1);
	rect = glGenLists(1);
	map = glGenLists(1);

	createMap(map);
	//createRoom(room);
	createCylinder(cylinder);
	//createRect(rect);

	/*glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);*/

	Display();
}

void Reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w , (GLsizei) h ); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(70.0, (GLdouble) w / (GLdouble) h , 0.1, 1000.0); 

   glMatrixMode (GL_MODELVIEW);
}

void Timer(int value)
{
	if(game)
	{
		if(moveForward)
  			factorZ -= factorMovimiento;
		if(moveRewind)
			factorZ += factorMovimiento;
		if(moveLeft)
			factorX -= factorMovimiento;
		if(moveRight)
  			factorX += factorMovimiento;

		//rotatedx( -spinxface, &factorX, &factorY, &factorZ);
		rotatedy( -spinyface, &factorX, &factorY, &factorZ);

		factorY -= gravedad * 0.03 ;

 		if(turnRight && salto)
		{
			salto = 0.0;
				factorY += gravedad * 1.0;
		}

		colisiond( &transX, &transY, &transZ, &factorX, &factorY, &factorZ);

		factorX = 0.0;
		factorZ = 0.0;

		factorEnemyZ -= 0.05;
		factorEnemyY -= 0.05;
		factorEnemyZ2 -= 0.05;
		factorEnemyY2 -= 0.05;
		factorEnemyZ3 -= 0.05;
		factorEnemyY3 -= 0.05;
		factorEnemyZ4 -= 0.05;
		factorEnemyY4 -= 0.05;
		factorEnemyZ5 -= 0.05;
		factorEnemyY5 -= 0.05;
		
		movimientoEnemy(&spinyEnemy, &transEnemyX, &transEnemyY, &transEnemyZ, &factorEnemyX, &factorEnemyY, &factorEnemyZ);
		colisiondEnemy( &spinyEnemy, &transEnemyX, &transEnemyY, &transEnemyZ, &factorEnemyX, &factorEnemyY, &factorEnemyZ);
		movimientoEnemy(&spinyEnemy2, &transEnemyX2, &transEnemyY2, &transEnemyZ2, &factorEnemyX2, &factorEnemyY2, &factorEnemyZ2);
		colisiondEnemy( &spinyEnemy2, &transEnemyX2, &transEnemyY2, &transEnemyZ2, &factorEnemyX2, &factorEnemyY2, &factorEnemyZ2);
		movimientoEnemy(&spinyEnemy3, &transEnemyX3, &transEnemyY3, &transEnemyZ3, &factorEnemyX3, &factorEnemyY3, &factorEnemyZ3);
		colisiondEnemy( &spinyEnemy3, &transEnemyX3, &transEnemyY3, &transEnemyZ3, &factorEnemyX3, &factorEnemyY3, &factorEnemyZ3);
		movimientoEnemy(&spinyEnemy4, &transEnemyX4, &transEnemyY4, &transEnemyZ4, &factorEnemyX4, &factorEnemyY4, &factorEnemyZ4);
		colisiondEnemy( &spinyEnemy4, &transEnemyX4, &transEnemyY4, &transEnemyZ4, &factorEnemyX4, &factorEnemyY4, &factorEnemyZ4);
		movimientoEnemy(&spinyEnemy5, &transEnemyX5, &transEnemyY5, &transEnemyZ5, &factorEnemyX5, &factorEnemyY5, &factorEnemyZ5);
		colisiondEnemy( &spinyEnemy5, &transEnemyX5, &transEnemyY5, &transEnemyZ5, &factorEnemyX5, &factorEnemyY5, &factorEnemyZ5);

		factorEnemyX = 0.0;
		factorEnemyY = 0.0;
		factorEnemyZ = 0.0;
		factorEnemyX2 = 0.0;
		factorEnemyY2 = 0.0;
		factorEnemyZ2 = 0.0;
		factorEnemyX3 = 0.0;
		factorEnemyY3 = 0.0;
		factorEnemyZ3 = 0.0;
		factorEnemyY4 = 0.0;
		factorEnemyZ4 = 0.0;
		factorEnemyY5 = 0.0;
		factorEnemyZ5 = 0.0;
	}
	glutTimerFunc(value,Timer,value);
	glutPostRedisplay();
}

void movimientoEnemy(GLdouble *angle, GLdouble *transEnemyX, GLdouble *transEnemyY, GLdouble *transEnemyZ, GLdouble *factorEnemyX, GLdouble *factorEnemyY, GLdouble *factorEnemyZ)
{
	int i = 0;
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double vectorO[3] = { *transEnemyX, *transEnemyY, *transEnemyZ };
	double vectorD[3] = { transX, transY, transZ };

	for(i = 0; i< 242; i++)
	{
		colision = intersectionEnemy( vectorO, vectorD, mapVertex[mapIndex[i][0]], mapVertex[mapIndex[i][1]], mapVertex[mapIndex[i][2]] );
		if(colision)
		{
			colision = 1;
			rotatedy( *angle, factorEnemyX, factorEnemyY, factorEnemyZ);
			return;
		}
	}
	*factorEnemyX = 0.025 * ( transX - *transEnemyX );
	*factorEnemyY = 0.025 * ( transY - *transEnemyY );
	*factorEnemyZ = 0.025 * ( transZ - *transEnemyZ );
}

void colisiondEnemy(GLdouble *ang, GLdouble *transEnemyX, GLdouble *transEnemyY, GLdouble *transEnemyZ, GLdouble *factorEnemyX, GLdouble *factorEnemyY, GLdouble *factorEnemyZ)
{
	GLint i = 0, j = 0, colision =0;
	GLdouble angle = 0.0;
	GLdouble angled = 0.0;
	GLdouble vector[3] = { *transEnemyX, *transEnemyY, *transEnemyZ };
	GLdouble vectord[3] = { *transEnemyX, *transEnemyY, *transEnemyZ };
	GLdouble vdirector[3] = { *factorEnemyX, *factorEnemyY, *factorEnemyZ };
	GLdouble vneutro[3] = { 0.0, 0.0, 0.0 };
	GLdouble normal1[3] = { 0.0, 0.0, 0.0 };
	GLdouble normal2[3] = { 0.0, 0.0, 0.0 };

	GLdouble *vectorn;

	if(!(*factorEnemyX==0.0 && *factorEnemyY==0.0 && *factorEnemyZ==0.0))
	{
		translated( &vectord[0], &vectord[1], &vectord[2], *factorEnemyX, *factorEnemyY, *factorEnemyZ);

		for(i=0; i < 242; i++)
		{
			distance = sqrt( ((transX - *transEnemyX)*(transX - *transEnemyX)) + 
				((transY - *transEnemyY)*(transY - *transEnemyY)) + 
				((transZ - *transEnemyZ)*(transZ - *transEnemyZ)) );

			if(distance < 0.4)
			{
				//life -= 0.01;
				if(life < 0.0)
					game = 0;
			}

			colision = intersection( vector, vectord, mapVertex[mapIndex[i][0]], mapVertex[mapIndex[i][1]], mapVertex[mapIndex[i][2]], factorEnemyX, factorEnemyY, factorEnemyZ );
			if(colision)
			{
				vectorn = createNormals(&mapVertex[mapIndex[i][0]][0], 
						&mapVertex[mapIndex[i][1]][0],
						&mapVertex[mapIndex[i][2]][0]);
				
				if(colision == 2)
				{
					*ang = rnd(360, 1);
					rotatedy( spinyEnemy, factorEnemyX, factorEnemyY, factorEnemyZ );
				}
				else
				{
					for( i = 0; i < 3 ; i++ )
						normal1[i] = vectorn[i];

					vectorn = createNormals2( vdirector, normal1 );

					for( i = 0; i < 3 ; i++ )
						normal2[i] = vectorn[i];

					vectorn = createNormals2( normal2, normal1  );

					*factorEnemyX = -vectorn[0];
					*factorEnemyY = -vectorn[1];
					*factorEnemyZ = -vectorn[2];
				}
				colisiondEnemy( ang, transEnemyX, transEnemyY, transEnemyZ, factorEnemyX, factorEnemyY, factorEnemyZ);
				break;
			}
			else if(!colision && i == 241)
			{
				translated( transEnemyX, transEnemyY, transEnemyZ, *factorEnemyX, *factorEnemyY, *factorEnemyZ );
				return;
			}
		}
	}	
}

void colisiond(GLdouble *transX, GLdouble *transY, GLdouble *transZ, GLdouble *factorX, GLdouble *factorY, GLdouble *factorZ)
{
	GLint i = 0, j = 0, colision = 0;
	GLdouble vector[3] = { *transX, *transY, *transZ };
	GLdouble vectord[3] = { *transX, *transY, *transZ };
	GLdouble vdirector[3] = { *factorX, *factorY, *factorZ };
	GLdouble vneutro[3] = { 0.0, 0.0, 0.0 };
	GLdouble normal1[3] = { 0.0, 0.0, 0.0 };
	GLdouble normal2[3] = { 0.0, 0.0, 0.0 };

	GLdouble *vectorn;

	if(!(*factorX==0.0 && *factorY==0.0 && *factorZ==0.0))
	{
		translated( &vectord[0], &vectord[1], &vectord[2], *factorX, *factorY, *factorZ);

		for(i=0; i < 242; i++)
		{
			colision = intersection( vector, vectord, mapVertex[mapIndex[i][0]], mapVertex[mapIndex[i][1]], mapVertex[mapIndex[i][2]], factorX, factorY, factorZ );
			if(colision)
			{
				if(colision == 1)
				{
					*factorY = 0.0;
					factorMovimiento = 0.05;
					salto = 1;
				}

				vectorn = createNormals(&mapVertex[mapIndex[i][0]][0], 
						&mapVertex[mapIndex[i][1]][0],
						&mapVertex[mapIndex[i][2]][0]);

				for( i = 0; i < 3 ; i++ )
					normal1[i] = vectorn[i];

				vectorn = createNormals2( vdirector, normal1 );

				for( i = 0; i < 3 ; i++ )
					normal2[i] = vectorn[i];
				
				vectorn = createNormals2( normal2, normal1  );

				*factorX = -vectorn[0];
				*factorY = -vectorn[1];
				*factorZ = -vectorn[2];

				colisiond( transX, transY, transZ, factorX, factorY, factorZ);
				break;
			}
			else if(!colision && i == 241)
			{
				translated( transX, transY, transZ, *factorX, *factorY, *factorZ );
				return;
			}
		}
	}
}

char intersection(GLdouble *vectorO, GLdouble *vectorD, GLdouble *vector1, GLdouble *vector2, GLdouble *vector3, GLdouble *transX, GLdouble *transY, GLdouble *transZ)
{
	GLdouble *normal;
	GLdouble angle = 0.0;
	GLdouble distance = 0.0;
	GLdouble angle2 = 0.0;
	GLdouble d[3] = { 0.0, 0.0, 0.0 };
	GLdouble base = 0.0;
	GLdouble vectorn[3] = { 0.0, 0.0, 0.0 };
	GLdouble vector11[3] = { 0.0, 0.0, 0.0 };
	GLdouble vector22[3] = { 0.0, 0.0, 0.0 };
	GLdouble vector33[3] = { 0.0, 0.0, 0.0 };

	int i = 0;

	normal = createNormals(vector1, vector2, vector3);

	for( i = 0; i < 3; i ++)
	{
		vector11[i] = vector1[i] + normal[i];
		vector22[i] = vector2[i] + normal[i];
		vector33[i] = vector3[i] + normal[i];

		vectorn[i] = normal[i];
	}

  	base = ((vectorn[0] * (*transX)) + (vectorn[1] * (*transY)) + (vectorn[2] * (*transZ)));
	if(base)
	{	
		distanced(&distance, vectorO, vector1, vector2, vector3);

		angle = (( (*transX * vectorn[0]) + (*transY * vectorn[1]) + (*transZ * vectorn[2])  ) 
			/ (sqrt((*transX * *transX) + (*transY * *transY) + (*transZ * *transZ)) * 
 			sqrt((vectorn[0] * vectorn[0]) + (vectorn[1] * vectorn[1]) + (vectorn[2] * vectorn[2]))) );

		if((distance > 0.0 && angle < 0.0)||(distance<0.0 && angle > 0.0))
		{
			r = ( - ( (-((vectorn[0] * (vector2[0])) + (vectorn[1] * (vector2[1])) + (vectorn[2] * (vector2[2])))) 
				+ ( vectorn[0] * vectorO[0] ) + ( vectorn[1] * vectorO[1]) + (vectorn[2] * vectorO[2] ) ) ) / base ;
		
			inter[0] = vectorO[0] + r * ( *transX );
			inter[1] = vectorO[1] + r * ( *transY );
			inter[2] = vectorO[2] + r * ( *transZ );

			angled = vectorn[1] / sqrt((vectorn[0] * vectorn[0])+(vectorn[1] * vectorn[1])+(vectorn[2] * vectorn[2]));		

			distanced(&d[0], inter, vector33, vector3, vector2 );
			distanced(&d[1], inter, vector22, vector2, vector1 );
			distanced(&d[2], inter, vector11, vector1, vector3 ); 

			if( (d[0]>0 && d[1]>0 && d[2]>0) && ((distance < 0.4 ) && (distance > -0.4)) && angled < 0.7)
				return 2;
			if( (d[0]>0 && d[1]>0 && d[2]>0) && ((distance < 0.1 ) && (distance > -0.1)) && angled >= 0.7) 
				return 1;
		}
	}

	return 0;
}

char intersectionEnemy(GLdouble *vectorO, GLdouble *vectorD, GLdouble *vector1, GLdouble *vector2, GLdouble *vector3)
{
	GLdouble *normal;
	GLdouble angle = 0.0;
	GLdouble distanceO = 0.0;
	GLdouble distanceD = 0.0;
	GLdouble angle2 = 0.0;
	GLdouble d[3] = { 0.0, 0.0, 0.0 };
	GLdouble base = 0.0;
	GLdouble vectorn[3] = { 0.0, 0.0, 0.0 };
	GLdouble vectord[3] = { 0.0, 0.0, 0.0 };
	GLdouble vector11[3] = { 0.0, 0.0, 0.0 };
	GLdouble vector22[3] = { 0.0, 0.0, 0.0 };
	GLdouble vector33[3] = { 0.0, 0.0, 0.0 };

	int i = 0;

	normal = createNormals(vector1, vector2, vector3);

	for( i = 0; i < 3; i ++)
	{
		vector11[i] = vector1[i] + normal[i];
		vector22[i] = vector2[i] + normal[i];
		vector33[i] = vector3[i] + normal[i];
		vectord[i] = vectorD[i] - vectorO[i];
		vectorn[i] = normal[i];
	}

  	base = ((vectorn[0] * (vectord[0])) + (vectorn[1] * (vectord[1])) + (vectorn[2] * (vectord[2])));
	if(base)
	{	
		distanced(&distanceO, vectorO, vector1, vector2, vector3);
		distanced(&distanceD, vectorD, vector1, vector2, vector3);

		if( (distanceO > 0.0 && distanceD < 0.0) || (distanceO < 0.0 && distanceD > 0.0) )
		{
		angle = (( (vectord[0] * vectorn[0]) + (vectord[1] * vectorn[1]) + (vectord[2] * vectorn[2])  ) 
			/ (sqrt((vectord[0] * vectord[0]) + (vectord[1] * vectord[1]) + (vectord[2] * vectord[2])) * 
 			sqrt((vectorn[0] * vectorn[0]) + (vectorn[1] * vectorn[1]) + (vectorn[2] * vectorn[2]))) );

			r = ( - ( (-((vectorn[0] * (vector2[0])) + (vectorn[1] * (vector2[1])) + (vectorn[2] * (vector2[2])))) 
				+ ( vectorn[0] * vectorO[0] ) + ( vectorn[1] * vectorO[1]) + (vectorn[2] * vectorO[2] ) ) ) / base ;
		
			for( i=0; i< 3; i++)
				inter[i] = vectorO[i] + r * ( vectord[i] );

			angled = vectorn[1] / sqrt((vectorn[0] * vectorn[0])+(vectorn[1] * vectorn[1])+(vectorn[2] * vectorn[2]));		

			distanced(&d[0], inter, vector33, vector3, vector2 );
			distanced(&d[1], inter, vector22, vector2, vector1 );
			distanced(&d[2], inter, vector11, vector1, vector3 ); 

			if( (d[0]>0 && d[1]>0 && d[2]>0) )
				return 1;
		}
	}
	return 0;
}

void distanced(GLdouble *d, GLdouble *point, GLdouble *vector1, GLdouble *vector2, GLdouble *vector3)
{
	GLdouble *normal;
	normal = createNormals(vector1, vector2, vector3);
	*d = ( ((normal[0] * (point[0])) + (normal[1] * (point[1])) + (normal[2] * (point[2])) + 
		-((normal[0] * (vector2[0])) + (normal[1] * (vector2[1])) + (normal[2] * (vector2[2]))))
			/ (sqrt( (normal[0] * normal[0]) + (normal[1] * normal[1]) + ( normal[2] * normal[2]))) );
}

void KeyboardUp(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 8:
		exit(0);
		break;
	case 'a':
	case 'A':
		turnLeft = 0;
		break;
	case 'k':
	case 'K':
		moveLeft = 0;
		break;
	case 'l':
	case 'L':
		moveRewind = 0;
		break;
	case 209://'�':
	case 241://'�'
		moveRight = 0;
		break;
	case 'o':
	case 'O':
		moveForward = 0;
		break;
	case 's':
	case 'S':
		turnRight = 0;
		break;
	}
}

void Keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 8:
		exit(0);
		break;
	case 32: //spacebar
		factorX = 0.0;
		factorY = 0.0;
		factorZ = 0.0;

		factorMovimiento = 0.05;
		gravedad = 0.05;

		factorEnemyX = 0.0;
		factorEnemyY = 0.0;
		factorEnemyZ = 0.0;
		factorEnemyX2 = 0.0;
		factorEnemyY2 = 0.0;
		factorEnemyZ2 = 0.0;
		factorEnemyX3 = 0.0;
		factorEnemyY3 = 0.0;
		factorEnemyZ3 = 0.0;
		factorEnemyX4 = 0.0;
		factorEnemyY4 = 0.0;
		factorEnemyZ4 = 0.0;
		factorEnemyX5 = 0.0;
		factorEnemyY5 = 0.0;
		factorEnemyZ5 = 0.0;

		transX = 14.5;
		transY = 6.0;
		transZ = 7.5;

		transEnemyX = 6.0;
		transEnemyY = 3.0;
		transEnemyZ = 14.0;
		transEnemyX2 = 16.5;
		transEnemyY2 = 6.0;
		transEnemyZ2 = 1.0;
		transEnemyX3 = 16.0;
		transEnemyY3 = 6.0;
		transEnemyZ3 = 7.0;
		transEnemyX4 = 6.5;
		transEnemyY4 = 6.0;
		transEnemyZ4 = 1.0;
		transEnemyX5 = 10.5;
		transEnemyY5 = 6.0;
		transEnemyZ5 = 6.0;

		spinxface = 90.0 ;
		spinyface = 0.0 ;

		spinxEnemy = 0.0 ;
		spinyEnemy = 0.0 ;

		spinxEnemy2 = 0.0 ;
		spinyEnemy2 = 0.0 ;

		spinxEnemy3 = 0.0 ;
		spinyEnemy3 = 0.0 ;

		spinxEnemy4 = 0.0 ;
		spinyEnemy4 = 0.0 ;

		spinxEnemy5 = 0.0 ;
		spinyEnemy5 = 0.0 ;

		life = 100.0;

		game = 1;
		break;
	case 'a':
	case 'A':
		turnLeft = 1;
		break;
	case 'k':
	case 'K':
		moveLeft = 1;
		break;
	case 'l':
	case 'L':
		moveRewind = 1;
		break;
	case 209://'�':
	case 241://'�'
		moveRight = 1;
		break;
	case 'o':
	case 'O':
		moveForward = 1;
		break;
	case 's':
	case 'S':
		turnRight = 1;
		break;
	}
}

void Mouse(int button, int state, int x, int y)
{
	/*if(button == GLUT_LEFT_BUTTON)
		PassiveMotion(x,y);*/
}

void Motion(int x, int y)
{
	vx = vx / 5.0;
	vy = vy / 5.0;

    spinyface = ( spinyface + (vx - origx) ) ;
    spinxface = ( spinxface + (vy - origy) ) ;

    origx = vx;
    origy = vy;

    glutPostRedisplay();
}

void PassiveMotion( int x, int y)
{
	vx = x;
	vy = y;
	
	width = glutGet(GLUT_WINDOW_WIDTH);
	height = glutGet(GLUT_WINDOW_HEIGHT);

	vx = vx / 5.0;
	vy = vy / 5.0;

	if( (x != (width / 2)) || (y != (height / 2 )) )
	{
		spinyface =  spinyface + (vx - origx) ;
		spinxface =  spinxface + (vy - origy) ;

  		if(spinxface > 90.0)
 			spinxface = 90.0;

		if(spinxface < -90.0)
			spinxface = -90.0;

		if(spinyface > 360.0)
 			spinyface = -360.0;

		if(spinyface < -360.0)
			spinyface = 360.0;
	}

    origx = vx;
    origy = vy;

	if(!((x > (width / 2) - 5) && (x <(width / 2) + 5)))
		glutWarpPointer(width / 2, height / 2);
	else if(!((y > (height / 2) - 5) && (y <(height / 2) + 5)))
		glutWarpPointer(width / 2, height / 2);

    glutPostRedisplay();
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

GLdouble * createNormals(GLdouble * vector1, GLdouble * vector2, GLdouble * vector3)
{
	GLdouble vectorA[3];
	GLdouble vectorB[3];
	GLdouble normalVector[3];
	GLdouble * pNormal;
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

	normalVector[0] = pNormal[0];
	normalVector[1] = pNormal[1];
	normalVector[2] = pNormal[2];

	return pNormal;
}

GLdouble * createNormals2(GLdouble * vector1, GLdouble * vector2)
{
	GLdouble normalVector[3];
	GLdouble * pNormal;

	normalVector[0] = ( (vector1[1] * vector2[2]) - (vector2[1] * vector1[2]) );
	normalVector[1] = ( (vector1[2] * vector2[0]) - (vector1[0] * vector2[2]) );
	normalVector[2] = ( (vector1[0] * vector2[1]) - (vector2[0] * vector1[1]) );

	return pNormal = normalVector;
}

GLdouble * Normalize(GLdouble * normalVector)
{
	int i = 0;
	GLdouble n = 0.0;
	GLdouble distance = ((normalVector[0] * normalVector[0]) +(normalVector[1] * normalVector[1]) +(normalVector[2] * normalVector[2]));
	if(distance >= 0)
		distance = sqrt( distance );
	for( i = 0; i < 3; i++)
	{
		n = normalVector[i];
		normalVector[i] = n / distance ;
	}

	return normalVector;
}

double rnd(int x, int y)
{
	return (double)(rand() % (x * 100) + y) / 100.0;
}




