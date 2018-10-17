#include "struct.h"
#include "includes.h"

using namespace std;

void circle(int radius, struct point center){

	int x, y, xc, yc;
	double d;
	
	//set inital values
	x = 0;
	y = radius;
	

	//cout << center.x << endl;
	//cout << center.y << endl;
	
	d = (5.0/4.0) - radius;
	while (x < y){
		if(d <= 0){
			d = d + (2*x - 2) + 1;
			x = x + 1;
		}
		else{
			d = d + (2*x + 2) + 1 - (2*y - 2);
			x = x + 1;
			y = y - 1;
		}

		//cout << "x: " << x << "y: " << y << endl;

		//cout << "xc: " << x + center.x << endl;
		//cout << "yc: " << y + center.y << endl;

        xc = center.x;
        yc = center.y;

        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POINTS);
            glVertex2i(xc+x, yc+y);
            glVertex2i(xc+y, yc+x);
            glVertex2i(xc+y, yc-x);
            glVertex2i(xc+x, yc-y);
            glVertex2i(xc-x, yc-y);
            glVertex2i(xc-y, yc-x);
            glVertex2i(xc-y, yc+x);
            glVertex2i(xc-x, yc+y);
            
        glEnd();
        glFlush();


	}

}
