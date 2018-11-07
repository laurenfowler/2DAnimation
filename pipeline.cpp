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
	point pixel;


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

	//clip clip clip clip clip
	point temp;
	vertex change, tmp;
	struct vertex *in_array, *out_array, *clip_boundary;
	in_array = (struct vertex *) malloc(NUM_POINTS * sizeof(struct vertex));
	out_array = (struct vertex *) malloc(NUM_POINTS * sizeof(struct vertex));
	clip_boundary = (struct vertex *) malloc(2 * sizeof(struct vertex));
	extern int *new_length;
	int pts;

	for(int i=0; i<points; i++){
		temp = *(circ_points + i);
		change.x = (float) temp.x;
		change.y = (float) temp.y;
		*(in_array + i) = change;
	}


	//call left clip
	tmp.x = (float) VIEWPORT_MIN;
	tmp.y = (float) VIEWPORT_MAX;
	*(clip_boundary + 0) = tmp;
	tmp.x = (float) VIEWPORT_MIN;
	tmp.y = (float) VIEWPORT_MIN;
	*(clip_boundary + 1) = tmp;
	SutherlandHodgmanPolygonClip(in_array, out_array, points, new_length, clip_boundary);


	pts = *new_length;

/*
	tmp.x = (float) VIEWPORT_MIN;
	tmp.y = (float) VIEWPORT_MIN;
	*(clip_boundary + 0) = tmp;
	tmp.x = (float) VIEWPORT_MAX;
	tmp.y = (float) VIEWPORT_MIN;
	*(clip_boundary + 1) = tmp;
	SutherlandHodgmanPolygonClip(out_array, in_array, pts, new_length, clip_boundary);

	pts = *new_length;

	tmp.x = (float) VIEWPORT_MAX;
	tmp.y = (float) VIEWPORT_MIN;
	*(clip_boundary + 0) = tmp;
	tmp.x = (float) VIEWPORT_MAX;
	tmp.y = (float) VIEWPORT_MAX;
	*(clip_boundary + 1) = tmp;
	SutherlandHodgmanPolygonClip(in_array, out_array, pts, new_length, clip_boundary);

	pts = *new_length;

	tmp.x = (float) VIEWPORT_MAX;
	tmp.y = (float) VIEWPORT_MAX;
	*(clip_boundary + 0) = tmp;
	tmp.x = (float) VIEWPORT_MIN;
	tmp.y = (float) VIEWPORT_MAX;
	*(clip_boundary + 1) = tmp;

	SutherlandHodgmanPolygonClip(out_array, in_array, pts, new_length, clip_boundary);
	
*/
	pts = *new_length;

	temp.x = 0;
	temp.y = 0;

	//0 our circ_points;
	for(int i=0; i<points; i++){
		*(circ_points + i) = temp;
	}

	for(int i=0; i<pts; i++){
		change = *(out_array + i);
		temp.x = (int) change.x;
		temp.y = (int) change.y;
		*(circ_points + i) = temp;
	}


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
