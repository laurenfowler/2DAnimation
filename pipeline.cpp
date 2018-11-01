#include "includes.h"
#include "constants.h"
#include "prototypes.h"

void pipeline(struct point * circ, struct point * circ_points, int points){

    extern bool rotate_flag;
    extern double spin;

    if(spin == 0.0){
        rotate_flag == 0;
        cout << "turning flag off bc spin is 0" << endl;
    }
    
    if(rotate_flag == 1){
        cout << "in rotate" << endl;    
    }

}
