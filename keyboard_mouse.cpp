#include "includes.h"
#include "constants.h"
#include "prototypes.h"


void mouse(int button, int state, int x, int y){


    extern double spin;
    int new_y = WINDOW_MAX - y;

    switch(button){
            
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN){
                if( (VIEWPORT_MIN < x) && (x < VIEWPORT_MAX) && (VIEWPORT_MIN < new_y) && (new_y < VIEWPORT_MAX)){
                    spin = spin + 10.0; 
                    check_spin();                  
                    //glutPostRedisplay();
                }
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_DOWN){
                if( (VIEWPORT_MIN < x) && (x < VIEWPORT_MAX) && (VIEWPORT_MIN < new_y) && (new_y < VIEWPORT_MAX)){
                    spin = spin - 10.0;
                    check_spin();
                    //glutPostRedisplay();
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

void check_spin(){
    extern double spin;

    if(spin > 360.0){
        spin = spin - 360.0;
    }
    cout << spin << endl;
}
