#include "includes.h"
#include "constants.h"
#include "struct.h"
#include "prototypes.h"

using namespace std;
void display(void){
	point center, pixel;
	int radius, num_points;
	double circumference;

	num_points = 0;
	radius = 150;
	center.x = 700;
	center.y = 500;

	//declare array of structs for points
	struct point* circ_points = (struct point *) malloc(NUM_POINTS * sizeof(struct point));
	struct point * trunk_points = (struct point *) malloc(4 * sizeof(struct point));
    
	glClear(GL_COLOR_BUFFER_BIT); //clear window

    glColor3f(1.0, 1.0, 1.0);
    glRecti(VIEWPORT_MIN, VIEWPORT_MIN, VIEWPORT_MAX, VIEWPORT_MAX);


	//calculate circle points
	circle(radius,num_points, center, circ_points);

	//fill array with trunk points
	pixel.x = 600;
	pixel.y = 400;
	pixel.w = 1;
	*(trunk_points + 0) = pixel;

	pixel.x = 300;
	pixel.y = 350;
	pixel.w = 1;
	*(trunk_points + 1) = pixel;

	pixel.x = 300;
	pixel.y = 650;
	pixel.w = 1;
	*(trunk_points + 2) = pixel;

	pixel.x = 600;
	pixel.y = 600;
	pixel.w = 1;
	*(trunk_points + 3) = pixel;


	draw_tree(num_points, circ_points, trunk_points);

}
