#ifndef GLOBALS_H
#define GLOBALS_H
#include "constants.h"
int points;
struct point * circ = (struct point *) malloc(NUM_POINTS * sizeof(struct point));
struct point * trunk = (struct point *) malloc(6 * sizeof(struct point));
struct point * circ_points = (struct point *) malloc(NUM_POINTS * sizeof(struct point));
struct point * trunk_points = (struct point *) malloc(6 * sizeof(struct point));

#endif
