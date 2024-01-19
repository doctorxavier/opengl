#include "fog.h"

void Fog(void)
{
	GLfloat fog_color[] = { 0.0, 1.0, 0.0, 1.0 };

	glEnable(GL_FOG);
	{
		glHint(GL_FOG_HINT,GL_NICEST);
		glFogi( GL_FOG_MODE, GL_EXP2 );
		glFogf( GL_FOG_DENSITY, 0.1);
		glFogf( GL_FOG_START, 0.1);
		glFogf( GL_FOG_END, 1000.0);
		glFogfv( GL_FOG_COLOR, fog_color);
	}
}