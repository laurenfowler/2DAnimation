#include "struct.h"
#include "includes.h"

using namespace std;

void circle(int radius, struct point center){

	int x, y;
	double d;
	
	//set inital values
	x = 0;
	y = radius;
	

	//cout << center.x << endl;
	//cout << center.y << endl;
	
	while (x < y){
	d = (5.0/4.0) - radius;
		if(d < 0){
			d = d + (2*x - 2) + 1;
			x = x + 1;
		}
		else{
			d = d + (2*x + 2) + 1 - (2*y - 2);
			x = x + 1;
			y = y + 1;
		}

		cout << "x: " << x << "y: " << y << endl;

		//cout << "xc: " << x + center.x << endl;
		//cout << "yc: " << y + center.y << endl;

	}

}
