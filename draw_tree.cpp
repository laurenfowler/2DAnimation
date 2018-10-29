#include "includes.h"
#include "constants.h"
#include "struct.h"

#include "namespaces.h"

void draw_tree(int num_points,  point *circ_points, point *trunk_points){

	point pixel;
	int cutoff;

	pixel = *(trunk_points + 0);
	cutoff = pixel.x;

	glColor3f(0.0,0.0,0.0);
    for(int i=0; i<num_points; i++){
        pixel = *(circ_points + i);
        glBegin(GL_POINTS);
			if(pixel.x > cutoff){
        		glVertex2i(pixel.x, pixel.y);
			}
        glEnd();
        glFlush();
    } 

	glBegin(GL_LINE_STRIP);
		for(int i=0; i<6; i++){
			pixel = *(trunk_points + i);
			glVertex2i(pixel.x, pixel.y);
		}	
	glEnd();
	glFlush();

}
