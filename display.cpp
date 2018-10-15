#include "includes.h"
#include "constants.h"
#include "struct.h"
#include "prototypes.h"

void display(void){

	int radius = 400;
	center.x = 450;
	center.y = 450;

    glClear(GL_COLOR_BUFFER_BIT); //clear window

    glColor3f(1.0, 1.0, 1.0);
    glRecti(VIEWPORT_MIN, VIEWPORT_MIN, VIEWPORT_MAX, VIEWPORT_MAX);

	//draw circle
	circle(radius, center);

    glFlush();
 

}
