#include "includes.h"
#include "constants.h"
#include "prototypes.h"

void tess(int pts){

	extern struct point * circ_points;
	extern list <triangles> triangle_list;

    list <vector <int> >:: iterator a, b, c, d, back, it;
    list <vector <int> > points, loc;
    bool next_point, cross, stop, remove;
	vector <int> temp;
	point pixel;
	int counter = 1;
	next_point = 0;
	struct triangles tri;


	//convert from array of structs to list of vectors of ints
	for(int i=0; i<pts; i++){
		pixel = *(circ_points + i);
		temp.push_back(pixel.x);
		temp.push_back(pixel.y);
		points.push_back(temp);
	}

	while(points.size() != 3){
		vector <int> p1, p2, p3, p4;
		
		back = points.begin();
		advance(back, points.size()-1);

		if(next_point == 1){
			counter++;
			next_point = 0;
			stop = 0;
			//check if a is at end
			if(a==back){
				a = points.begin();
				b = points.begin();
				c = points.begin();
				d = points.begin();
				advance(b,1);
				advance(c,2);
				advance(d,3);
				p1 = *a;
				p2 = *b;
				p3 = *c;
				p4 = *d;
				stop=1;
			}
			else{
				//advance a
				advance(a,1);
				p1 = *a;
			}
			if(b == back && !stop){
				b = points.begin();
				c = points.begin();
				d = points.begin();
				advance(c,1);
				advance(d,1);
				p2 = *b;
				p3 = *c;
				p4 = *d;
				stop = 1;
			}
			else if(!stop){
				//advance b
				advance(b,1);
				p2 = *b;
			}
			if(c==back && !stop){
				c = points.begin();
				d = points.begin();
				advance(d,1);
				p3 = *c;
				p4 = *d;
				stop==1;
			}
			else if(!stop){
				//advance c
				advance(c,1);
				p3 = *c;
			}
			if(d==back && !stop){
				d = points.begin();
				p4 = *d;
			}
			else if(!stop){
				advance(d,1);
				p4 = *d;
			}
		}
		else{
			counter = 1;
			a = points.begin();
			b = points.begin();
			c = points.begin();
			d = points.begin();
			advance(b,1);
			advance(c,2);
			advance(d,3);
			p1 = *a;
			p2 = *b;
			p3 = *c;
			p4 = *d;
		}

		
		double z = cross_prod2D(p1, p2, p3);
		if(z<0.0){
			cross = new_intersect(points, p3, p1);
			if(cross == 1){
				next_point = 1;
			}
			else{
				double angle1 = angle_check(p2, p3, p4);
				double angle2 = angle_check(p2, p3, p1);

				if(angle1<angle2){
					next_point = 1;
				}
				else{
					tri.p1 = p1;
					tri.p2 = p2;
					tri.p3 = p3;

					//add triangle to triangle list
					triangle_list.push_back(tri);
					b = points.erase(b);
					next_point = 0;
				}
			}

		}
		else if(z>0.0){
			next_point = 1;
		}
		else if(z==0.0){
			b = points.erase(b);
		}
	}

	//add last triangle
	a = points.begin();
	b = points.begin();
	c = points.begin();
	advance(b,1);
	advance(c,2);
	tri.p1 = *a;
	tri.p2 = *b;
	tri.p3 = *c;
	triangle_list.push_back(tri);

}
