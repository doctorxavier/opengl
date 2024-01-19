#include <stdio.h>
#include "funciones.h"

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_ALPHA);

  /* glutGameModeString("800x600:32@75");
   glutEnterGameMode();*/
   glutInitWindowSize (800, 600);
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


