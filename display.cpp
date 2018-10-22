#include "includes.h"
#include "constants.h"
#include "struct.h"
#include "prototypes.h"

using namespace std;
void display(void){
	point center;
	int radius, num_points;
	double circumference;

	radius = 300;
	center.x = 450;
	center.y = 450;

	//point list array
	circumference = 2.0 * 3.14 * radius;
	cout << "circumference: " << circumference << endl;
	num_points = (int) floor(circumference);
	
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
