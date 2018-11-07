#include "includes.h"
#include "constants.h"
#include "prototypes.h"

//#include "namespaces.h"

void init_tree(){
	point center, pixel;
	int radius, num_points;

    extern int points;
    extern struct point *circ;
    extern struct point *trunk;
    extern struct point *trunk_points;    
	extern int *new_length;


	//center of circle
	center.x = 650;
	center.y = 500;
	radius = 180;

	//calculate circle points
	circle(radius, &num_points, center, circ);
	pixel = *(circ + 606);
    *(trunk + 0) = pixel;

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

	new_length = &num_points;

    pixel.x = 0.0;
    pixel.y = 0.0;
    pixel.w = 0.0;

    //weird code to remove unecessary points
    for(int i=606; i<=930; i++){
        *(circ + i) = pixel;          
    }

    //fill in trunk points
    int count = 0;
    for(int i = 606; i<=611; i++){
        *(circ + i) = *(trunk + count);
        count++;
    }
    
    count = 0;
    for(int i=612; i<=705; i++){
        *(circ + i) = *(circ + (931 + count));
        count++;
        //*(circ + 930 + count) = pixel;
    }

    points = points - 324 + 6 -1; // -1 is bc there was a weird extra 0,0


}


