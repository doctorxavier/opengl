#if !defined ( _FUNCIONES_H_ )
#define _FUNCIONES_H_

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "image.h"

#define FACTORVISTA 10.0
#define PI 3.1415926535897932384626433832795
//#define ACSIZE 8


static double FACTORGIRO = 0.0;
static double ACSIZE = 0;

static double factorX = 0.0;
static double factorY = 0.0;
static double factorZ = 0.0;

static double factorMovimiento = 0.05;
static double gravedad = 0.05;

static double factorEnemyX = 0.0;
static double factorEnemyY = 0.0;
static double factorEnemyZ = 0.0;
static double factorEnemyX2 = 0.0;
static double factorEnemyY2 = 0.0;
static double factorEnemyZ2 = 0.0;
static double factorEnemyX3 = 0.0;
static double factorEnemyY3 = 0.0;
static double factorEnemyZ3 = 0.0;
static double factorEnemyX4 = 0.0;
static double factorEnemyY4 = 0.0;
static double factorEnemyZ4 = 0.0;
static double factorEnemyX5 = 0.0;
static double factorEnemyY5 = 0.0;
static double factorEnemyZ5 = 0.0;

/*static double transX = 18.0;
static double transY = 6.0;
static double transZ = 12.0;*/

static double transX = 14.5;
static double transY = 6.0;
static double transZ = 12.5;

/*static double transX = -62.10;
static double transY = -3.72;
static double transZ = -57.37;*/

static double transEnemyX = 6.0;
static double transEnemyY = 2.3;
static double transEnemyZ = 14.0;
static double transEnemyX2 = 16.5;
static double transEnemyY2 = 5.3;
static double transEnemyZ2 = 1.0;
static double transEnemyX3 = 16.0;
static double transEnemyY3 = 5.3;
static double transEnemyZ3 = 7.0;
static double transEnemyX4 = 6.5;
static double transEnemyY4 = 5.3;
static double transEnemyZ4 = 1.0;
static double transEnemyX5 = 10.5;
static double transEnemyY5 = 5.3;
static double transEnemyZ5 = 6.0;

static double spinxface = 0.0 ;
static double spinyface = 90.0 ;

/*static double spinxface = 7.40 ;
static double spinyface = 125.40 ;*/

static double spinxEnemy = 0.0 ;
static double spinyEnemy = 0.0 ;
static double angleyEnemy = 0.0;

static double spinxEnemy2 = 0.0 ;
static double spinyEnemy2 = 0.0 ;

static double spinxEnemy3 = 0.0 ;
static double spinyEnemy3 = 0.0 ;

static double spinxEnemy4 = 0.0 ;
static double spinyEnemy4 = 0.0 ;

static double spinxEnemy5 = 0.0 ;
static double spinyEnemy5 = 0.0 ;

static double rotateSphere = 0.0;

static double d = 0.0;
static double angled = 0.0;

static double life = 100.0;

static char game = 0;
static char start = 1;
static char end = 0;
static char help = 0;
static float fstart = 1.0;
static float fend = 1.0;
static float fhelp = 1.0;

static double distance = 0.0001;

static char colision = 0;
static char colisionbool = 0;
static char salto = 0;

static double vx = 0.0;
static double vy = 0.0;

static double r = 0.0;

static double inter[3] = {0.0, 0.0, 0.0};

static float fBlood = 0.0;
static char cBlood = 0;

static int width = 0;
static int height = 0;

static int gwidth = 0;
static int gheight = 0;

static int nLists = 0;
static GLuint map;
//static GLuint sphere;

static GLUquadricObj *sphere;

static int i = 1;

static int g = 0;
static int h = 0;

static timage *image = NULL;
static timage *image2 = NULL;

static GLuint texmapname[10];
static GLuint texguyname;
static GLuint texguyname2;
static GLuint texguyname3;
static GLuint texguyname4;
static GLuint texguyname5;
static GLuint texskyname;
static GLuint texblood;
static GLuint texcaratula;
static GLuint texstart;
static GLuint texgameover;
static GLuint texcongratulations;
static GLuint texhelp;

static double origx, origy;

static GLuint room;
static GLuint rect;
static GLuint cylinder;
static GLuint map;
static GLuint guy;
static GLuint sky;

static double vectorD[3] = {0.0, 0.0, 0.0};

int	lastCount;      /* Timer count for last fps update */
int	frameCount;     /* Number of frames for timing */
int	fpsRate;        /* Current frames per second rate */

void rotatedx(GLdouble ang, GLdouble *vx, GLdouble *vy, GLdouble *vz);
void rotatedy(GLdouble ang, GLdouble *vx, GLdouble *vy, GLdouble *vz);
void rotatedz(GLdouble ang, GLdouble *vx, GLdouble *vy, GLdouble *vz);
void translated(GLdouble *vx, GLdouble *vy, GLdouble *vz, GLdouble transX, GLdouble transY, GLdouble transZ);
void colisiond(GLdouble *transX, GLdouble *transY, GLdouble *transZ, GLdouble *vx, GLdouble *vy, GLdouble *vz);
void colisiondEnemy(GLdouble *ang, GLdouble *transEnemyX, GLdouble *transEnemyY, GLdouble *transEnemyZ, GLdouble *factorEnemyX, GLdouble *factorEnemyY, GLdouble *factorEnemyZ);
void movimientoEnemy(GLdouble *angle, GLdouble *transEnemyX, GLdouble *transEnemyY, GLdouble *transEnemyZ, GLdouble *factorEnemyX, GLdouble *factorEnemyY, GLdouble *factorEnemyZ);
void distanced(GLdouble *distance, GLdouble *point, GLdouble *vector1, GLdouble *vector2, GLdouble *vector3);
char intersection(GLdouble *vectorO, GLdouble *vectorD, GLdouble *vector1, GLdouble *vector2, GLdouble *vector3, GLdouble *vx, GLdouble *vy, GLdouble *vz);
char intersectionEnemy(GLdouble *vectorO, GLdouble *vectorD, GLdouble *vector1, GLdouble *vector2, GLdouble *vector3);
void multM4x4(double Matrix[4][4], double Matrix1[4][4], double Matrix2[4][4]);
void multM4x1(double Matrix[4], const double Matrix1[4], const double Matrix2[4][4]);
void create_display_list(void);
void Display(void);
void Init(void);
void Reshape (int w, int h);
void Keyboard(unsigned char key, int x, int y);
void KeyboardUp(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void Motion(int x, int y);
void PassiveMotion( int x, int y);
void Timer(int value);
void AssignArray4f(float* material, float arg1, float arg2, float arg3, float arg4);
void AssignArray3f(float* material, float arg1, float arg2, float arg3);
double rnd(int x, int y);

GLdouble * createNormals(GLdouble * vector1, GLdouble * vector2,  GLdouble * vector3);
GLdouble * createNormals2(GLdouble * vector1, GLdouble * vector2);
GLdouble * Normalize(GLdouble * normalVector);

#endif
