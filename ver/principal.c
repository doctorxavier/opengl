#include <GL/glut.h>
#include <stdio.h>
#include "funciones.h"

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

   /*glutGameModeString("2048x1536:16@60");
   glutEnterGameMode();*/
   glutInitWindowSize (600, 600); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Mi ventana");

   Init ();

   glutDisplayFunc(Display); 
   glutReshapeFunc(Reshape);
   glutKeyboardFunc(Keyboard);
   glutMouseFunc(Mouse);
   glutMotionFunc(Motion);
   glutPassiveMotionFunc(PassiveMotion);

   glutMainLoop();
   return 0;
}


