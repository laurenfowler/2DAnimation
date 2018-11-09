#ifndef GLOBALS_H
#define GLOBALS_H

#include "struct.h"
#include "constants.h"
int points;
struct point *circ;
struct point *trunk;
struct point *circ_points;
struct point *trunk_points;
double spin;
double dspin;
double scale = 1.0;
double dscale;
double reflect;
int length_from_clip;
int *new_length;
list <triangles> triangle_list;
bool tesslat = 0;
vector<triangles> triangle_vec;
bool fill = 0.0;

#endif
