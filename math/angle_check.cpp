#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

//check angle of triangle given points of triangle
double angle_check(vector <int> p1, vector <int> p2, vector <int> p3){

	double ax = (double) p1[0] - p2[0];
	//cout << "ax : " << ax << endl;
	double ay = (double) p1[1] - p2[1];
	//cout << "ay : " << ay << endl;

	//build line b
	double bx = (double) p3[0] - p2[0];
	//cout << "bx : " << bx << endl;
	double by = (double) p3[1] - p2[1];
	//cout << "by : " << by << endl;

	double magn_a = sqrt((ax*ax) + (ay*ay));
	//cout << "magn_a : " << magn_a << endl;
	double magn_b = sqrt((bx*bx) + (by*by));
	//cout << "magn_b : " << magn_b << endl;

	//calculate dot product
	double dot = (ax*bx) + (ay*by);
	//cout << "dot_prod : " << dot_prod << endl;

	//caculate angle
	double tmp = dot/(magn_a*magn_b);
	//cout << "tmp : " << tmp << endl;
	return acos(tmp);
	
} 


