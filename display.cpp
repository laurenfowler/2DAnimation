#include "includes.h"
#include "constants.h"
#include "struct.h"
#include "prototypes.h"

using namespace std;
void display(void){
	point center;
	int radius, num_points;
	double circumference;

	radius = 150;
	center.x = 300;
	center.y = 400;

	//declare array
	struct point* circ_points = (struct point *) malloc(NUM_POINTS * sizeof(struct point));
	//struct point *ptr = circ_points;

    glClear(GL_COLOR_BUFFER_BIT); //clear window

    glColor3f(1.0, 1.0, 1.0);
    glRecti(VIEWPORT_MIN, VIEWPORT_MIN, VIEWPORT_MAX, VIEWPORT_MAX);

	//draw circle
	circle(radius, center, circ_points);

//    sin();
    glFlush();
 
}
