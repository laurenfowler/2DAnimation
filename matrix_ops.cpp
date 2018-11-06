#include "includes.h"
#include "constants.h"
#include "prototypes.h"

void translate_mat(double x, double y, double *tPtr){

	//create translation matrix
	tPtr[0] = 1.0; tPtr[1] = 0.0; tPtr[2] = x;
	tPtr[3] = 0.0; tPtr[4] = 1.0; tPtr[5] = y;
	tPtr[6] = 0.0; tPtr[7] = 0.0; tPtr[8] = 1.0;

	//cout << *(tPtr + 0) << endl;
}

void rotation_mat(double mSpin, double *tPtr){
	//degrees to radians	
	double rad;

	rad = mSpin * (PI/180.0);
	
	tPtr[0] = cos(rad); tPtr[1] = -sin(rad); tPtr[2] = 0.0;
	tPtr[3] = sin(rad); tPtr[4] = cos(rad); tPtr[5] = 0.0;
	tPtr[6] = 0.0; tPtr[7] = 0.0; tPtr[8] = 1.0;
}

void scale_mat(double scale, double *tPtr){
	tPtr[0] = scale; tPtr[1] = 0.0; tPtr[2] = 0.0;
	tPtr[3] = 0.0; tPtr[4] = scale; tPtr[5] = 0.0;
	tPtr[6] = 0.0; tPtr[7] = 0.0; tPtr[8] = 1.0;
}

void matrix_mult(int mSize, double pts[], double *tPtr){

	double tmp[3];

	//fill temporary matrix
	for(int i=0; i<mSize; i++){
		tmp[i] = 0.0;
	}
	//cout << "filled temp matrix" << endl;

	for(int i=0; i<mSize; i++){
		for(int j=0; j<mSize; j++){
	//		cout << i*mSize+j << endl;
	//		cout << *(tPtr + (i+mSize+j)) << endl;
			tmp[i] = tmp[i] + (pts[j] * *(tPtr + (i*mSize + j)));
		}
	}

	//cout << "did multiplication" << endl;

	//fill pts with tmp
	for(int i=0; i<mSize; i++){
		pts[i] = tmp[i];
	}

	//cout << "refilled pts" << endl;

}
