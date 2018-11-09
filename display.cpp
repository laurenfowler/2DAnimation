#include "includes.h"
#include "constants.h"
#include "prototypes.h"
//#include "namespaces.h"

void display(void){

	cout << "in display" << endl;	

    extern int points;
    extern struct point *circ;
    extern struct point *circ_points;
    extern struct point *trunk;
    extern struct point *trunk_points;
	extern int *new_length;
	extern int length_from_clip;
//	extern struct list <triangles> *triangle_list;

    point pixel;

    // To insure that these got executed I pulled the malloc into main
    circ = (struct point *) malloc(NUM_POINTS * sizeof(struct point));
    trunk = (struct point *) malloc(6 * sizeof(struct point));
    circ_points = (struct point *) malloc(NUM_POINTS * sizeof(struct point));
    trunk_points = (struct point *) malloc(6 * sizeof(struct point));
//	triangle_list =(list <triangles> *) malloc(NUM_POINTS * sizeof(list<triangles>));

	cout << "malloced everything" << endl;

	glClear(GL_COLOR_BUFFER_BIT); //clear window

    glColor3f(1.0, 1.0, 1.0);
    glRecti(VIEWPORT_MIN, VIEWPORT_MIN, VIEWPORT_MAX, VIEWPORT_MAX);

    init_tree();
	cout << "after init tree" << endl;

    glColor3f(0.0,0.0,0.0);
	//cout << "going into pipeline" << endl;
    pipeline(circ, points);
	cout << "after pipeline" << endl;

	int pts = *new_length;
	//cout << pts << endl;
	extern bool tesslat;
	extern vector <triangles> triangle_vec;


	if(tesslat){
		cout << "trying to draw triangles" << endl;
		struct triangles tri;
		vector <int> p1, p2, p3;
	
		cout << triangle_vec.size() << endl;
		for(int i=0; i<triangle_vec.size(); i++){
			tri = triangle_vec.at(i);
				
			p1 = tri.p1;
			p2 = tri.p2;
			p3 = tri.p3;

			glBegin(GL_LINE_LOOP);
				glVertex2i(p1.at(0), p1.at(1));
				glVertex2i(p2.at(0), p2.at(1));
				glVertex2i(p3.at(0), p3.at(1));
			glEnd();
		}
		glFlush();
		triangle_vec.clear(); //remove all data from triangle_vec
		cout << triangle_vec.size() << endl;
		cout << "drew all triangles" << endl;
	}	
	else{
		cout << "drawing normal tree" << endl;
		glBegin(GL_LINE_LOOP);

		for(int i=0; i<length_from_clip; i++){
			pixel = *(circ_points + i);
			//cout << pixel.x << " " << pixel.y << endl;
			glVertex2i(pixel.x, pixel.y);
		}

		glEnd();
    	glFlush(); 
	}


	glutSwapBuffers();

    //free(circ);
    free(circ_points);
    //free(trunk);
    //free(trunk_points);
    cout << "freed everything" << endl;

}

//code taken from Polygon Tesselation Project
void draw_tess(){
	extern list <triangles> triangle_list;
	struct triangles tri;
	vector <int> p1, p2, p3;

	cout << "in draw tess" << endl;

    list <triangles> :: iterator it;

	glColor3f(0.0,0.0,0.0);

    for(it = triangle_list.begin(); it != triangle_list.end(); it++){
        tri = *it;
		
		p1 = tri.p1;
		p2 = tri.p2;
		p3 = tri.p3;

		cout << "before begin line loop" << endl;
		glBegin(GL_LINE_LOOP);
			glVertex2i(p1.at(0), p1.at(1));
			glVertex2i(p2.at(0), p2.at(1));
			glVertex2i(p3.at(0), p3.at(1));
		glEnd();
        advance(it,1);
    }
	glFlush();
	cout << "out of draw tess" << endl;
}

