#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_ALPHA);

   /*glutGameModeString("1024x768:32@75");
   glutEnterGameMode();*/

   glutInitWindowSize (1024, 768);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Mi ventana");

   srand(time(NULL));

   glutSetCursor(GLUT_CURSOR_NONE);

   Init ();

   glutDisplayFunc(Display); 
   glutReshapeFunc(Reshape);
   glutKeyboardFunc(Keyboard);
   glutKeyboardUpFunc(KeyboardUp);
   glutPassiveMotionFunc(PassiveMotion);
   glutTimerFunc(1,Timer,1);

   glutMainLoop();
   return 0;
}


