//Modified from dot.c Fowler - Spring 2018
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

double dot_(int *N, double *vec1, double *vec2);

#ifdef __cplusplus
}
#endif

double dot_(int *N, double *vec1, double *vec2){
	
	int i, len;
	double sum;

	len = *N;
	sum = 0;

	for (i=0; i<len; i++){
		sum = sum + (*(vec1+1) * *(vec2+i));
	}

	return sum;
} 
