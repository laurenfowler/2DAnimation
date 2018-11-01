#ifndef PROTOTYPES_H
#define PROTOTYPES_H
#include "struct.h"
void myglutInit(int argc, char** argv);
void myInit(void);
void display();
void circle(int , int* , point, point* );
int total_points(int , int );
void init_tree();
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);
void spin_tree();
void pipeline(point*, point*, int points);
void translate_mat(double x, double y, double * tPtr);
void apply_transform(point*, int pnts, double *tPtr);
void matrix_mult(int mSize, double pts[], double *tPtr);
void rotation_mat(double mSpin, double *tPtr);
using namespace std;
#endif
