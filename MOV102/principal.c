#include <stdio.h>
#include "funciones.h"

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

   /*glutGameModeString("1600x1200:32@75");
   glutEnterGameMode();*/
   glutInitWindowSize (600, 600); 
   glutInitWindowPosition (10, 200);
   glutCreateWindow ("Mi ventana");

   glutSetCursor(GLUT_CURSOR_NONE);

   Init ();

   glutDisplayFunc(Display); 
   glutReshapeFunc(Reshape);
   glutKeyboardFunc(Keyboard);
   glutKeyboardUpFunc(KeyboardUp);
   glutMouseFunc(Mouse);
   glutMotionFunc(Motion);
   glutPassiveMotionFunc(PassiveMotion);
   glutTimerFunc(1,Timer,1);

   glutMainLoop();
   return 0;
}


