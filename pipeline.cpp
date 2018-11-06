#include "includes.h"
#include "constants.h"
#include "prototypes.h"

void pipeline(struct point * circ, int points){

    extern double spin;
	extern double scale;
	extern double reflect;
	extern struct point *circ_points;	
	double transform[9];
	double *tPtr;

	circ_points = circ;

	tPtr = &transform[0];
	//build translation to 0
	translate_mat(-WINDOW_MAX/2, -WINDOW_MAX/2, tPtr);

	//apply to circ and store in circ_points
	apply_transform(circ_points, points, tPtr);

	//build reflection matrix
	reflection_mat(reflect, tPtr);
	apply_transform(circ_points, points, tPtr);
	reflect = 0.0;

	//build rotation matrix
	rotation_mat(spin, tPtr);
	apply_transform(circ_points, points, tPtr);

	//build scaling matrix
	scale_mat(scale, tPtr);
	apply_transform(circ_points, points, tPtr);

	//translate back
	translate_mat(WINDOW_MAX/2, WINDOW_MAX/2, tPtr);
	apply_transform(circ_points, points, tPtr);

}

void apply_transform(struct point * circ_points, int points, double * tPtr){

	point pixel;
	double pts[3];
	int pt = points;

	for (int i=0; i<pt; i++){
		pixel = *(circ_points + i);
		pts[0] = pixel.x;
		pts[1] = pixel.y;
		pts[2] = pixel.w;
		matrix_mult(3, pts, tPtr);
		pixel.x = pts[0];
		pixel.y = pts[1];
		pixel.w = pts[2];

		*(circ_points + i) = pixel;
	}

}
