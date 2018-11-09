#include "includes.h"
#include "constants.h"
#include "prototypes.h"

void tess(int pts, point *circ_points){

	extern vector <triangles> triangle_vec;

    list <vector <int> >:: iterator a, b, c, d, back, it;
    list <vector <int> > loc, points1;
    bool next_point, cross, stop, remove;
	point pixel;
	int counter = 1;
	next_point = 0;
	struct triangles tri;
	int iterations = 0;

	//convert from array of structs to list of vectors of ints
//	cout << "converting" << endl;
	for(int i=0; i<pts; i++){
		vector <int> temp;
		pixel = *(circ_points + i);
		temp.push_back(pixel.x);
		temp.push_back(pixel.y);
		points1.push_back(temp);
	}
//	cout << "done converting" << endl;

	points1.reverse(); //reverse the points
//	points1.push_front(points1.back());
//	points1.pop_back();
//	cout << "reversed point" << endl;

	while(points1.size() != 3){
//		cout<< points1.size() << endl;
		vector <int> p1, p2, p3, p4;
		
		back = points1.begin();
		advance(back, points1.size()-1);

		if(next_point == 1){
			//cout << "moving to next points" << endl;
			counter++;
			next_point = 0;
			stop = 0;
			//check if a is at end
			if(a==back){
				//cout << "a at end " << endl;
				a = points1.begin();
				b = points1.begin();
				c = points1.begin();
				d = points1.begin();
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
			if(b==back){
				//cout << "b at end" << endl;
				b = points1.begin();
				c = points1.begin();
				d = points1.begin();
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
			if(c==back){
				//cout << "c at end" << endl;
				c = points1.begin();
				d = points1.begin();
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
			if(d==back){
				//cout << "d at end" << endl;
				d = points1.begin();
				p4 = *d;
			}
			else if(!stop){
				//cout << "advancing d" << endl;
				advance(d,1);
				p4 = *d;
				//cout << "advanced d" << endl;
			}
			//cout << "moved to next points" << endl;
		}
		else{
			counter = 1;
			a = points1.begin();
			b = points1.begin();
			c = points1.begin();
			d = points1.begin();
			advance(b,1);
			advance(c,2);
			advance(d,3);
			p1 = *a;
			p2 = *b;
			p3 = *c;
			p4 = *d;
			//cout << "started at beginning" << endl;
		}

		double z = cross_prod2D(p1, p2, p3);
		//cout << z << endl;
		if(z<0.0){
			cross = new_intersect(points1, p3, p1);
			if(cross == 1){
	//			cout << "intersect" << endl;
				next_point = 1;
	//			cout << "next poit from intersectin" << endl;
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
						triangle_vec.push_back(tri);
						b = points1.erase(b);
						next_point = 0;
	//					cout << "erased point" << endl;
					}
				}
				else if(z>0.0){
	//					cout << "new triangle" << endl;
						//cout << "adding triangle" << endl;
						tri.p1 = p1;
						tri.p2 = p2;
						tri.p3 = p3;

						//add triangle to triangle list
						triangle_vec.push_back(tri);
						b = points1.erase(b);
						next_point = 0;
	//					cout << "erased point" << endl; */
				}
				else if(z==0){
					d = points1.erase(d);
					d = c;
					advance(d,1);
					//next_point = 1;	
				}
				
			}

		}
		else if(z>0.0){
	//		cout << "clockwise" << endl;
	//		cout << z << endl;
			next_point = 1;
		}
		else if(z==0.0){
	//		cout << "the same" << endl;
			b = points1.erase(b);
		}
	}

	//add last triangle
//	cout << "last triangle" << endl;
	a = points1.begin();
	b = points1.begin();
	c = points1.begin();
	advance(b,1);
	advance(c,2);
	tri.p1 = *a;
	tri.p2 = *b;
	tri.p3 = *c;
	triangle_vec.push_back(tri);
	cout << "done with tesselation" << endl;

}
