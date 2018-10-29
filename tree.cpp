#include "includes.h"
#include "constants.h"
#include "prototypes.h"
#include "globals.h"

using namespace std;

void init_tree(){
	point center, pixel;
	int radius, num_points;
	
	//center of circle
	center.x = 650;
	center.y = 500;
	radius = 180;

	//calculate circle points
	circle(radius, num_points, center, circ);
	pixel = *(circ + 606);
    *(trunk_points + 0) = pixel;

    pixel.x = 680;
    pixel.y = 470;
    pixel.w = 1;
    *(trunk + 1) = pixel;

    pixel.x = 200;
    pixel.y = 400;
    pixel.w = 1;
    *(trunk + 2) = pixel;

    pixel.x = 200;
    pixel.y = 600;
    pixel.w = 1;
    *(trunk + 3) = pixel;

    pixel.x = 680;
    pixel.y = 530;
    pixel.w = 1;
    *(trunk + 4) = pixel;

    pixel = *(circ + 930);
    *(trunk + 5) = pixel;

	points = num_points;	

	

}

void draw_tree(int &num_points, struct point * circ_points, struct point * trunk_points){

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
