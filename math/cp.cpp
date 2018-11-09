#include <vector>
#include <iostream>

using namespace std;

double cross_prod3D(vector <int> p1, vector <int> p2, vector <int> p3){
	//insert code for 3D cross product
}

double cross_prod2D(vector <int> p1, vector <int> p2, vector <int> p3){

	cout << "1 :" << p1[0] << " " << p1[1] << endl;
	cout << "2 :" << p2[0] << " " << p2[1] << endl;
	cout << "3 :" << p3[0] << " " << p3[1] << endl;

	//build line a vars
	double ax = (double) p1[0] - p2[0];
	double ay = (double) p1[1] - p2[1];

	//build line b vars
	double bx = (double) p3[0] - p2[0];
	double by = (double) p3[1] - p2[1];

	//calculate z component
	double z = (ax*by) - (bx*ay);

	return z;
	

}
