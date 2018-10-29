//main program
#include "includes.h"
#include "constants.h"
#include "struct.h"
#include "prototypes.h"
#include "globals.h"

int main(int argc, char** argv){
    myglutInit(argc, argv); //set the window
    myInit(); //declare attributes
    //mouse and keyboard shit here
    
	//fill tree arrays
		

    glutDisplayFunc(display);
    glutMainLoop();
    
}

void myglutInit(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //glut_double later
    glutInitWindowSize(WINDOW_MAX, WINDOW_MAX); 
    glutInitWindowPosition(0,0); //starts in upper left corner
    glutCreateWindow("Tree Animation");
}

void myInit(void){
    glClearColor(0.0, 0.0, 0.0, 1.0); //black background
    glPointSize(1.0);

    //viewing
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (float) WINDOW_MAX, 0.0, (float) WINDOW_MAX);
    glMatrixMode(GL_MODELVIEW);
}
