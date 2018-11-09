#include "includes.h"
#include "constants.h"
#include "prototypes.h"

void tess(int pts){

	extern struct point * circ_points;
	extern list <triangles> triangle_list;

    list <vector <int> >:: iterator a, b, c, d, back, it;
    list <vector <int> > points, loc, points1;
    bool next_point, cross, stop, remove;
	point pixel;
	int counter = 1;
	next_point = 0;
	struct triangles tri;

	//cout << "in tesselation" << endl;


	//convert from array of structs to list of vectors of ints
	for(int i=0; i<pts; i++){
		vector <int> temp;
		pixel = *(circ_points + i);
		temp.push_back(pixel.x);
		temp.push_back(pixel.y);
		points1.push_back(temp);
	}

	for(it=points1.begin(); it != points1.end(); it++){
		vector <int> tmp = *it;
		points.push_front(tmp);
	}

	//points.push_back(points.front());

	while(points.size() != 3){
//		cout << points.size() << endl;
		vector <int> p1, p2, p3, p4;
		
		back = points.begin();
		advance(back, points.size()-1);

		if(next_point == 1){
			counter++;
			next_point = 0;
			stop = 0;
			//check if a is at end
			if(distance(points.begin(),a) == (points.size())-1){
				//cout << "a at end " << endl;
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
				//cout << "advancing a" << endl;
				advance(a,1);
				p1 = *a;
			}
			if(distance(points.begin(),b) == (points.size()-1)){
				//cout << "b at end" << endl;
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
				//cout << "advancing b" << endl;
				advance(b,1);
				p2 = *b;
			}
			if(distance(points.begin(),c) == (points.size()-1)){
				//cout << "c at end" << endl;
				c = points.begin();
				d = points.begin();
				advance(d,1);
				p3 = *c;
				p4 = *d;
				stop==1;
			}
			else if(!stop){
				//advance c
				//cout << "advancing c" << endl;
				advance(c,1);
				p3 = *c;
			}
			if(distance(points.begin(),d) == (points.size()-1)){
				//cout << "d at end" << endl;
				d = points.begin();
				p4 = *d;
			}
			else if(!stop){
				//cout << "advancing d" << endl;
				advance(d,1);
				p4 = *d;
				//cout << "advanced d" << endl;
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
		//cout << z << endl;
		if(z<0.0){
			cross = new_intersect(points, p3, p1);
			if(cross == 1){
	//			cout << "intersect" << endl;
				next_point = 1;
			}
			else{

				//check for CCW
				z = cross_prod2D(p2, p3, p4);
				if(z<0.0){
				
					double angle1 = angle_check(p2, p3, p4);
					double angle2 = angle_check(p2, p3, p1);

					double deg1 = angle1 * (180.0/PI);
					double deg2 = angle2 * (180.0/PI);

					if(deg1<deg2){
	//					cout << "bad angle" << endl;
						next_point = 1;
					}
					else{
	//					cout << "new triangle" << endl;
						//cout << "adding triangle" << endl;
						tri.p1 = p1;
						tri.p2 = p2;
						tri.p3 = p3;

						//add triangle to triangle list
						triangle_list.push_back(tri);
						b = points.erase(b);
						next_point = 0;
	//					cout << "erased point" << endl;
					}
				}
				else{
	//					cout << "new triangle" << endl;
						//cout << "adding triangle" << endl;
						tri.p1 = p1;
						tri.p2 = p2;
						tri.p3 = p3;

						//add triangle to triangle list
						triangle_list.push_back(tri);
						b = points.erase(b);
						next_point = 0;
	//					cout << "erased point" << endl;
				}
			}

		}
		else if(z>0.0){
	//		cout << "clockwise" << endl;
			next_point = 1;
		}
		else if(z==0.0){
	//		cout << "the same" << endl;
			b = points.erase(b);
		}
	}

	//add last triangle
	cout << "last triangle" << endl;
	a = points.begin();
	b = points.begin();
	c = points.begin();
	advance(b,1);
	advance(c,2);
	tri.p1 = *a;
	tri.p2 = *b;
	tri.p3 = *c;
	triangle_list.push_back(tri);
	cout << "done with tesselation" << endl;

}
