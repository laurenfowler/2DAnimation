#include "includes.h"
#include "constants.h"
#include "prototypes.h"

void pipeline(struct point * circ, int points){

    extern double spin;
	extern struct point *circ_points;	
	double transform[9];
	double *tPtr;

	circ_points = circ;

	tPtr = &transform[0];
	//build translation to 0
	translate_mat(-WINDOW_MAX/2, -WINDOW_MAX/2, tPtr);
	cout << "out of translate mat" << endl;

	cout << transform[0] << endl;

	//apply to circ and store in circ_points
	cout << "in apply transformation" << endl;
	apply_transform(circ_points, points, tPtr);
	cout << "out of apply transformtaion" << endl;

	//build rotation matrix
	rotation_mat(spin, tPtr);
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
		cout << "going into matrix_mult" << endl;
		matrix_mult(3, pts, tPtr);
		pixel.x = pts[0];
		pixel.y = pts[1];
		pixel.w = pts[2];

		*(circ_points + i) = pixel;
	}

}
