#include <unistd.h>  
#include "prototypes.h"
#include "struct.h"
#include "includes.h"
#define PI 3.14159265

using namespace std;

void circle(int radius, struct point center, struct point * circ_points){

	int x, y, xc, yc, num_points, counter, i;
	double d;
	point curr;

	i = 0;
	num_points = 0;
	counter = 0;

	num_points = total_points(radius, num_points);
	cout << num_points << endl;

	//set inital values
	x = 0;
	y = radius;

	//set center values
    xc = center.x;
    yc = center.y;
	
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


		curr.x = xc + x;
		curr.y = yc + y;
		curr.w = 1;
		*(circ_points + counter) = curr;
		counter++;


    	/*glColor3f(0.0,0.0,0.0);
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
        glFlush(); */
	} 


	glColor3f(0.0,0.0,0.0);
	for (int i =0; i<counter; i++){
		curr = *(circ_points + i);
		
		glBegin(GL_POINTS);
		glVertex2i(curr.x, curr.y);
		usleep(10000);
		glEnd();
		glFlush();
	}

}

void sin(){

    int x, y, cx, cy;
    double tmp, rad;

    cx = 450;
    cy = 450;
    
    glColor3f(0.0,0.0,0.0);

    for(int i=0; i<180; i++){
       x = i;
       rad = i * (PI/180.0);
       tmp = sin(rad);
       tmp = (tmp*180)/PI;
       y = (int) floor(tmp);



       glBegin(GL_POINTS);
        glVertex2i(cx+x, cy+y);
        glVertex2i(cx+x+180, cy-y);               
       glEnd();
       glFlush();
        
    }
    
}









