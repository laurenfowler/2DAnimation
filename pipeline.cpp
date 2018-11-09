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
	extern bool tesslat;

	//list <vector <int> > tess_points;
	//list <vector <int> > :: iterator it;
	//it = tess_points.begin(); 
//	point new_pt;
//	vector <int> struct_to_vec;
//	int t1, t2;

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
	struct vertex *in_array, *out_array, *cb1, *cb2, *cb3, *cb4;
	in_array = (struct vertex *) malloc(NUM_POINTS * sizeof(struct vertex));
	out_array = (struct vertex *) malloc(NUM_POINTS * sizeof(struct vertex));
	cb1 = (struct vertex *) malloc(2 * sizeof(struct vertex));
	cb2 = (struct vertex *) malloc(2 * sizeof(struct vertex));
	cb3 = (struct vertex *) malloc(2 * sizeof(struct vertex));
	cb4 = (struct vertex *) malloc(2 * sizeof(struct vertex));
	extern int *new_length;
	int pts;

	for(int i=0; i<points; i++){
		temp = *(circ_points + i);
		change.x = (float) temp.x;
		change.y = (float) temp.y;
		*(in_array + i) = change;
	}


    //call sutherland hodgman polygon clipping
	tmp.x = (float) VIEWPORT_MIN;
	tmp.y = (float) VIEWPORT_MAX;
	*(cb1 + 0) = tmp;
	tmp.x = (float) VIEWPORT_MIN;
	tmp.y = (float) VIEWPORT_MIN;
	*(cb1 + 1) = tmp;
	SutherlandHodgmanPolygonClip(in_array, out_array, points, new_length, cb1);


	pts = *new_length;

	tmp.x = (float) VIEWPORT_MIN;
	tmp.y = (float) VIEWPORT_MIN;
	*(cb2 + 0) = tmp;
	tmp.x = (float) VIEWPORT_MAX;
	tmp.y = (float) VIEWPORT_MIN;
	*(cb2 + 1) = tmp;
	SutherlandHodgmanPolygonClip(out_array, in_array, pts, new_length, cb2);

	pts = *new_length;

	tmp.x = (float) VIEWPORT_MAX;
	tmp.y = (float) VIEWPORT_MIN;
	*(cb3 + 0) = tmp;
	tmp.x = (float) VIEWPORT_MAX;
	tmp.y = (float) VIEWPORT_MAX;
	*(cb3 + 1) = tmp;
	SutherlandHodgmanPolygonClip(in_array, out_array, pts, new_length, cb3);

	pts = *new_length;

	tmp.x = (float) VIEWPORT_MAX;
	tmp.y = (float) VIEWPORT_MAX;
	*(cb4 + 0) = tmp;
	tmp.x = (float) VIEWPORT_MIN;
	tmp.y = (float) VIEWPORT_MAX;
	*(cb4 + 1) = tmp;

	SutherlandHodgmanPolygonClip(out_array, in_array, pts, new_length, cb4);
	

	pts = *new_length;

	temp.x = 0;
	temp.y = 0;

	//0 our circ_points;
	for(int i=0; i<points; i++){
		*(circ_points + i) = temp;
	}


	//move last output array back into circ_points
	for(int i=0; i<pts; i++){
		change = *(in_array + i);
		temp.x = (int) change.x;
		temp.y = (int) change.y;
		*(circ_points + i) = temp;
	}

    //calculate tesselation points each loop

	if(tesslat){
		tess(pts);
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
