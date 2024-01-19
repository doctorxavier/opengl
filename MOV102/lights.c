#include "lights.h"

GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat light_diffuse[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat light_specular[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat light_position[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat spot_direction[] = { 0.0, 0.0, 0.0 };

void Light1(void)
{
	AssignArray4f(light_ambient, 0.0, 0.0, 0.0, 1.0 );
	AssignArray4f(light_diffuse, 1.0, 1.0, 1.0, 1.0 );
	AssignArray4f(light_specular, 1.0, 1.0, 1.0, 1.0 );
	AssignArray4f(light_position, 1.5, 1.5, 3.0, 1.0 );
	AssignArray3f(spot_direction, -0.8, -0.8, -1.0 );

	glEnable(GL_LIGHT1);
	{
		//glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);	
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		/*glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);
		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
		glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0.5);*/

		glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5);
		glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0);
		glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.1);
	}
}

void Light2(void)
{
	AssignArray4f(light_ambient, 1.0, 1.0, 1.0, 1.0 );
	AssignArray4f(light_diffuse, 1.0, 1.0, 1.0, 1.0 );
	AssignArray4f(light_specular, 1.0, 1.0, 1.0, 1.0 );
	AssignArray4f(light_position, -2.0, 1.0, 1.0, 1.0 );

	glEnable(GL_LIGHT0);
	{
		//glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);	
		glLightfv(GL_LIGHT1, GL_POSITION, light_position);

		/*glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.5);
		glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.0);
		glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.1);*/
	}

}