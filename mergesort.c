#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

int int_cmp(const void *a, const void *b){
    if ( *(int *) a > *(int *) b ) {
        return 1;
    } else if ( *(int *) a < *(int *) b ) {
        return -1;
    } else {
        return 0;
    }
}

int dbl_cmp(const void *a, const void *b){
    if ( *(double *) a > *(double *) b ) {
        return 1;
    } else if ( *(double *) a < *(double *) b ) {
        return -1;
    } else {
        return 0;
    }
}

//Mergesort
