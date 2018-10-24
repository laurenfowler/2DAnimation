#include "includes.h"
#include "constants.h"
#include "prototypes.h"
#include "globals.h"

using namespace std;
void display(void){
	
	glClear(GL_COLOR_BUFFER_BIT); //clear window

    glColor3f(1.0, 1.0, 1.0);
    glRecti(VIEWPORT_MIN, VIEWPORT_MIN, VIEWPORT_MAX, VIEWPORT_MAX);

	draw_tree(points, circ, trunk);

}
