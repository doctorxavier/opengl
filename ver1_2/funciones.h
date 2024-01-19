#if !defined ( _FUNCIONES_H_ )
#define _FUNCIONES_H_

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define FACTORVISTA 0.1
#define FACTORGIRO 3.0

static float transX = 0.0;
static float transY = 0.0;
static float transZ = 0.0;

static float rotateX = 0.0;
static float rotateY = 0.0;
static float rotateZ = 0.0;

static int spinxface = 0 ;
static int spinyface = 0 ;

static int nLists = 0;

static int origx, origy;

static int i = 1;

void create_display_list(void);
void Display(void);
void Init(void);
void Reshape (int w, int h);
void Keyboard(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void Motion(int x, int y);
void PassiveMotion( int x, int y);
void AssignArray4f(float* material, float arg1, float arg2, float arg3, float arg4);
void AssignArray3f(float* material, float arg1, float arg2, float arg3);
GLfloat * createNormals(GLfloat * vector1, GLfloat * vector2,  GLfloat * vector3);
GLfloat * Normalize(GLfloat * normalVector);
GLfloat * Average(GLfloat ** normalsVector, GLint size);
void drawtriangle(float *v1, float *v2, float *v3); 
void subdivide(float *v1, float *v2, float *v3, long depth);
void normalize(float v[3]);
void blend(int i);

#endif
