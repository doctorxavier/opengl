#include "lights.h"

GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat light_diffuse[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat light_specular[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat light_position[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat spot_direction[] = { 0.0, 0.0, 0.0 };

void Light0(void)
{
	AssignArray4f(light_ambient, 0.0, 0.0, 0.0, 1.0 );
	AssignArray4f(light_diffuse, 1.0, 1.0, 1.0, 1.0 );
	AssignArray4f(light_specular, 1.0, 1.0, 1.0, 1.0 );
	AssignArray4f(light_position, 30.0, 30.0, 30.0, 1.0 );
	AssignArray3f(spot_direction, 0.0, 0.0, 0.0 );

	glEnable(GL_LIGHT0);
	{
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);	
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		/*glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);
		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
		glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0.5);*/

		/*glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5);
		glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0);
		glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.1);*/
	}
}

void Light1(void)
{
	AssignArray4f(light_ambient, 0.0, 0.0, 0.0, 1.0 );
	AssignArray4f(light_diffuse, 0.0, 0.0, 1.0, 1.0 );
	AssignArray4f(light_specular, 0.0, 0.0, 1.0, 1.0 );
	AssignArray4f(light_position, 0.0, 30.0, 30.0, 1.0 );

	glEnable(GL_LIGHT1);
	{
		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);	
		glLightfv(GL_LIGHT1, GL_POSITION, light_position);

		/*glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.5);
		glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.0);
		glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.1);*/
	}
}

void Light2(void)
{
	AssignArray4f(light_ambient, 0.0, 0.0, 0.0, 1.0 );
	AssignArray4f(light_diffuse, 0.5, 0.5, 0.5, 1.0 );
	AssignArray4f(light_specular, 0.5, 0.5, 0.5, 1.0 );
	AssignArray4f(light_position, 0.0, 0.0, 0.0, 1.0 );

	glEnable(GL_LIGHT2);
	{
		glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);	
		glLightfv(GL_LIGHT2, GL_POSITION, light_position);

		/*glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.5);
		glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.0);
		glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.1);*/
	}
}

void Light3(void)
{
	AssignArray4f(light_ambient, 0.0, 0.0, 0.0, 1.0 );
	AssignArray4f(light_diffuse, 1.0, 1.0, 1.0, 1.0 );
	AssignArray4f(light_specular, 1.0, 1.0, 1.0, 1.0 );
	AssignArray4f(light_position, 11.0, -17.0, 9.0, 1.0 );

	glEnable(GL_LIGHT3);
	{
		glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular);	
		glLightfv(GL_LIGHT3, GL_POSITION, light_position);

		/*glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 0.5);
		glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.0);
		glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.1);*/
	}
}

void Light4(void)
{
	AssignArray4f(light_ambient, 0.0, 0.0, 0.0, 1.0 );
	AssignArray4f(light_diffuse, 1.0, 1.0, 1.0, 1.0 );
	AssignArray4f(light_specular, 1.0, 1.0, 1.0, 1.0 );
	AssignArray4f(light_position, 0.0, 700.0, 10.0, 1.0 );

	glEnable(GL_LIGHT4);
	{
		glLightfv(GL_LIGHT4, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT4, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT4, GL_SPECULAR, light_specular);	
		glLightfv(GL_LIGHT4, GL_POSITION, light_position);

		/*glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 0.5);
		glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 0.0);
		glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 0.1);*/
	}
}