#include "includes.h"
#include "constants.h"
#include "prototypes.h"

#include "namespaces.h"

void init_tree(){
	point center, pixel;
	int radius, num_points;

    extern int points;
    extern struct point *circ;
    extern struct point *trunk;
    extern struct point *trunk_points;    

	//center of circle
	center.x = 650;
	center.y = 500;
	radius = 180;

	//calculate circle points
	circle(radius, &num_points, center, circ);
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


