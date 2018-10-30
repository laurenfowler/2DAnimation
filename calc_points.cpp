#include "includes.h"

//#include "namespaces.h"

int total_points(int radius, int counter){
	int x, y;
	double d;

	x = 0;
	y = radius;

	d = (5.0/4.0) - radius;
	while(x<y){
		if (d<=0){
			d = d + (2*x - 2) +1;
			x = x+1;
		}	
		else{
			d = d + (2*x + 2) + 1 - (2*y -2);
			x = x + 1;
			y = y - 1;
		}

		counter++;
	}


	//determine total # of points
	counter = counter * 8;
	return counter;
	
}
