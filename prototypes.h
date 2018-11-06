#ifndef PROTOTYPES_H
#define PROTOTYPES_H
#include "struct.h"

using namespace std;
void myglutInit(int argc, char** argv);
void myInit(void);
void display();
void circle(int , int* , point, point* );
int total_points(int , int );
void init_tree();
void sh_clip(list <point> in_list, list <point> out_list);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);
void spin_tree();
void pipeline(point*,int points);
void translate_mat(double x, double y, double * tPtr);
void apply_transform(point*, int pnts, double *tPtr);
void matrix_mult(int mSize, double pts[], double *tPtr);
void rotation_mat(double mSpin, double *tPtr);
void scale_tree();
void scale_mat(double scale, double *tPtr);
void reflection_mat(double reflect, double *tPtr);

#endif
