#include <unistd.h>  
#include "prototypes.h"
#include "struct.h"
#include "includes.h"
#define PI 3.14159265

using namespace std;

void circle(int radius, struct point center, struct point * circ_points){

	//general variables
	int x, y, xc, yc, num_points, counter, i, new_spot; 
	double d;
	point pixel;

	//point placement in array vars
	//seg is # of points in one 1/8th of circle
	int seg, seg1, seg2, seg3, seg4, seg5, seg6, seg7, seg8;

	i = 0;
	num_points = 0;
	counter = 1;

	num_points = total_points(radius, num_points);
	
	seg = num_points/8;
	seg1 = num_points/8;
	seg2 = seg * 2;
	seg3 = seg * 3;
	seg4 = seg * 4;
	seg5 = seg * 5;
	seg6 = seg * 6;
	seg7 = seg * 7;

	//set inital values
	x = 0;
	y = radius;

	//set center values
    xc = center.x;
    yc = center.y;

	//fill in 4 starting pixels
	pixel.x = x + xc;
	pixel.y = y + yc;
	pixel.w = 1;
	*(circ_points + 0) = pixel;

	pixel.x = xc + y;
	pixel.y = yc - x;
	pixel.w = 1;
	*(circ_points + seg2) = pixel;

	pixel.x = xc - x;
	pixel.y = yc - y;
	pixel.w = 1;
	*(circ_points + seg4) = pixel;


	pixel.x = xc - y;
	pixel.y = yc + x;
	pixel.w = 1;
	*(circ_points + seg6) = pixel;


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

		point curr;
		curr.x = xc + x;
		curr.y = yc + y;
		curr.w = 1;
		*(circ_points + counter) = curr;

		point curr1;
		curr1.x = xc+y;
		curr1.y = yc+x;
		curr1.w = 1;
		new_spot = seg1 + (seg-counter);
		//cout << "next spot: " << new_spot << endl;
		*(circ_points + new_spot) = curr1;

		point curr2;
		curr2.x = xc+y;
		curr2.y = yc-x;
		curr2.w = 1;
		new_spot = seg2 + counter;
		*(circ_points + new_spot) = curr2; 

		point curr3;
		curr3.x = xc + x;
		curr3.y = yc - y;
		curr3.w = 1;
		new_spot = seg3 + (seg-counter);
		*(circ_points + new_spot) = curr3;

		point curr4;
		curr4.x = xc - x;
		curr4.y = yc - y;
		curr4.w = 1;
		new_spot = seg4 + counter;
		*(circ_points + new_spot) = curr4;

		point curr5;
		curr5.x = xc - y;
		curr5.y = yc - x;
		curr5.w = 1;
		new_spot = seg5 + (seg-counter);
		*(circ_points + new_spot) = curr5;

		point curr6;
		curr6.x = xc - y;
		curr6.y = yc + x;
		curr6.w = 1;
		new_spot = seg6 + counter;
		*(circ_points + new_spot) = curr6;

		point curr7;
		curr7.x = xc - x;
		curr7.y = yc + y;
		curr7.w = 1;
		new_spot = seg7 + (seg-counter);
		*(circ_points + new_spot) = curr7;

		counter++; 

    	/*glColor3f(0.0,0.0,0.0);
        glBegin(GL_POINTS);
            glVertex2i(xc+x, yc+y); //curr
            glVertex2i(xc+y, yc+x); //curr1
            glVertex2i(xc+y, yc-x); //curr2
            glVertex2i(xc+x, yc-y); //curr3
            glVertex2i(xc-x, yc-y); //curr4
            glVertex2i(xc-y, yc-x); //curr5
            glVertex2i(xc-y, yc+x); //curr6
            glVertex2i(xc-x, yc+y); //curr7
        glEnd();
        glFlush(); */
	} 



	glColor3f(0.0,0.0,0.0);
	for (int i =0; i<num_points; i++){
		pixel = *(circ_points + i);
		
		cout << i << " : " << pixel.x << " " << pixel.y << endl;
		glBegin(GL_POINTS);
		glVertex2i(pixel.x, pixel.y);
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









