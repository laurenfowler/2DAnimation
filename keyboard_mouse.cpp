#include "includes.h"
#include "constants.h"
#include "prototypes.h"


void mouse(int button, int state, int x, int y){

    extern double dspin;
	extern double dscale;
    int new_y = WINDOW_MAX - y;

    switch(button){
            
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN){
                if( (VIEWPORT_MIN < x) && (x < VIEWPORT_MAX) && (VIEWPORT_MIN < new_y) && (new_y < VIEWPORT_MAX)){
                    dspin = dspin - 1.0; 
                    //rotate_flag = 1;
                    glutIdleFunc(spin_tree);                  
                }
				else{
					dscale = dscale + 0.05;
					scale_tree();
					break;
				}
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_DOWN){
                if( (VIEWPORT_MIN < x) && (x < VIEWPORT_MAX) && (VIEWPORT_MIN < new_y) && (new_y < VIEWPORT_MAX)){
                    dspin = dspin + 1.0;
                    //rotate_flag = 1;
                    glutIdleFunc(spin_tree);
                }
				else{
					dscale = dscale -0.05;
					scale_tree();
					break;
				}
            }
            break;
        default:
            break;


    }

}

void keyboard(unsigned char key, int x, int y){

	extern double reflect;
	extern double spin;
	extern double dspin;
    //close program
    if (key=='q' || key=='Q'){
        exit(0);
    }
	//reflect tree
	if (key=='r' || key=='R'){
		reflect = PI;
		spin = spin + 180; //add 180 so reflected tree draws and spins correctly
		if(spin > 360.0){
			spin = spin - 360.0;
		}	
		glutPostRedisplay();
	}
	//stop animation
	if (key == 's' || key == 'S'){
		dspin = 0.0;
	}
	if(key == 'i' || key == 'I'){
		dspin = 0.0;
		spin = 0.0;
	}

}

void spin_tree(){
    extern double spin;
	extern double dspin;
	spin = spin + dspin;
    if(spin > 360.0){
        spin = spin - 360.0;
    }
    glutPostRedisplay();
}

void scale_tree(){
	extern double dscale;
	extern double scale;
	scale = 1.0 + dscale;
	if(scale < 0.0){
		scale = 0.0;
	}
	glutPostRedisplay();
}
