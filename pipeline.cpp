#include "includes.h"
#include "constants.h"
#include "prototypes.h"

void pipeline(struct point * circ, int points){

	//cout << "in pipeline" << endl;
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

	//cout << "before clipping" << endl;

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
	int *new_length1, *new_length2, *new_length3;
	int pts;
	int a, b, c ,d;
	new_length = &a;
	new_length1 = &b;
	new_length2 = &c;
	new_length3 = &d;

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
	SutherlandHodgmanPolygonClip(in_array, out_array, points, new_length1, cb1);


	pts = *new_length1;
	//cout << pts << endl;

	tmp.x = (float) VIEWPORT_MIN;
	tmp.y = (float) VIEWPORT_MIN;
	*(cb2 + 0) = tmp;
	tmp.x = (float) VIEWPORT_MAX;
	tmp.y = (float) VIEWPORT_MIN;
	*(cb2 + 1) = tmp;
	SutherlandHodgmanPolygonClip(out_array, in_array, pts, new_length2, cb2);

	pts = *new_length2;
	//cout << pts<< endl;

	tmp.x = (float) VIEWPORT_MAX;
	tmp.y = (float) VIEWPORT_MIN;
	*(cb3 + 0) = tmp;
	tmp.x = (float) VIEWPORT_MAX;
	tmp.y = (float) VIEWPORT_MAX;
	*(cb3 + 1) = tmp;
	SutherlandHodgmanPolygonClip(in_array, out_array, pts, new_length3, cb3);

	pts = *new_length3;
	//cout << pts << endl;

	tmp.x = (float) VIEWPORT_MAX;
	tmp.y = (float) VIEWPORT_MAX;
	*(cb4 + 0) = tmp;
	tmp.x = (float) VIEWPORT_MIN;
	tmp.y = (float) VIEWPORT_MAX;
	*(cb4 + 1) = tmp;

	SutherlandHodgmanPolygonClip(out_array, in_array, pts, new_length, cb4);
	
	//cout << "after clipping" << endl;

	pts = *new_length;
	//cout << pts << endl;
	
	extern int length_from_clip;
	length_from_clip = pts;

	temp.x = 0;
	temp.y = 0;

	free(circ_points);
	circ_points = (struct point *) malloc(pts*sizeof(struct point));

	//move last output array back into circ_points
	for(int i=0; i<pts; i++){
		change = *(in_array + i);
		temp.x = (int) change.x;
		temp.y = (int) change.y;
		*(circ_points + i) = temp;
	}

/*	cout << "before check circ_points" << endl;
	//check circ_points
	for(int i=0; i<pts; i++){
		point hi = *(circ_points + i);
		cout << hi.x << " " << hi.y << endl;

	}*/

    //calculate tesselation points each loop
	extern bool fill;
	if(tesslat || fill){
		//cout << "calculate tesselation" << endl;
		tess(pts, circ_points);
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
