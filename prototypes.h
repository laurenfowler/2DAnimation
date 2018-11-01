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
void check_spin();
using namespace std;
#endif
