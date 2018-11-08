#include <iostream>
#include <vector>

using namespace std;

double triangle_area2D(vector<int> p1, vector <int> p2, vector<int> p3){
	double area, pt1, pt2;

	pt1 = (p1[0]*p2[1]) + (p2[0]*p3[1]) + (p3[1]*p1[1]);
	pt2 = -(p1[0]*p3[1]) - (p2[0]*p1[1]) - (p3[0]*p2[1]);

	area = .5 *(pt2 + pt1);

	return area;
	

}
