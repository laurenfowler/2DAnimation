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
//void sh_clip(list <point> in_list, list <point> out_list);
//void clip(list <point> in_list, list <point> out_list, char clipper, void(*func)());
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
void SutherlandHodgmanPolygonClip(vertex *inVertexArray, vertex *outVertexArray, int inLength, int *outLength, vertex *clip_boundary);
void Output(vertex newVertex, int *outLength, vertex *outVertexArray);
bool Inside(vertex testVertex, vertex *clipBoundary);
void Intersect(vertex first, vertex second, vertex *clipBoundary, vertex *intersectPt);
void tess(int pts, struct point *);
bool new_intersect(list <vector <int> > point_list, vector <int> prev_point, vector <int> new_point);
double cross_prod2D( vector <int> p1, vector <int> p2, vector <int> p3);
double angle_check(vector <int> p1, vector <int> p2, vector <int> p3);
double triangle_area2D(vector<int>p1, vector<int> p2, vector<int>p3);
void draw_tess();
//void draw_line(vector<int> previous, vector<int> current)

#endif
