#include "includes.h"
#include "constants.h"
#include "prototypes.h"


void mouse(int button, int state, int x, int y){


    extern double spin;
    extern double dspin;
    int new_y = WINDOW_MAX - y;

    switch(button){
            
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN){
                if( (VIEWPORT_MIN < x) && (x < VIEWPORT_MAX) && (VIEWPORT_MIN < new_y) && (new_y < VIEWPORT_MAX)){
                    dspin = dspin - 10.0; 
                    spin_tree();
                    //rotate_flag = 1;
                    glutIdleFunc(spin_tree);                  
                }
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_DOWN){
                if( (VIEWPORT_MIN < x) && (x < VIEWPORT_MAX) && (VIEWPORT_MIN < new_y) && (new_y < VIEWPORT_MAX)){
                    dspin = dspin + 10.0;
                    spin_tree();
                    //rotate_flag = 1;
                    glutIdleFunc(spin_tree);
                }
            }
            break;
        default:
            break;


    }

}

void keyboard(unsigned char key, int x, int y){

    //close program
    if (key=='q' || key=='Q'){
        exit(0);
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
