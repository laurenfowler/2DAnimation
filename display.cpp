#include "includes.h"
#include "constants.h"
#include "prototypes.h"


#include "namespaces.h"

void display(void){
	
    extern int points;
    extern struct point *circ;
    extern struct point *circ_points;
    extern struct point *trunk;
    extern struct point *trunk_points;

    // To insure that these got executed I pulled the malloc into main
    circ = (struct point *) malloc(NUM_POINTS * sizeof(struct point));
    trunk = (struct point *) malloc(6 * sizeof(struct point));
    circ_points = (struct point *) malloc(NUM_POINTS * sizeof(struct point));
    trunk_points = (struct point *) malloc(6 * sizeof(struct point));

	glClear(GL_COLOR_BUFFER_BIT); //clear window

    glColor3f(1.0, 1.0, 1.0);
    glRecti(VIEWPORT_MIN, VIEWPORT_MIN, VIEWPORT_MAX, VIEWPORT_MAX);

    init_tree();
	draw_tree(points, circ, trunk);
    free(circ);
    free(circ_points);
    free(trunk);
    free(trunk_points);

}
