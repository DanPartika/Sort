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
void mergesort_help(void* array, size_t len, size_t elem_sz, int (*comp)(const void*, const void*),i,j,int aux[])){ 
    if (j<=i){
        return;
    }
    int mid = (i+j) / 2;
    mergesort_help(array, len, elem_sz, *comp,i,mid,aux[]);
    mergesort_help(array, len, elem_sz, *comp,mid+1,j,aux[]);

    int poi_l = i;
    int poi_r = mid+1;
    int counter;

    for(counter=i;counter<=j;counter++){
        if(poi_l == mid+1){
            
        }
    }
}


//Mergesort
void mergesort(void* array, size_t len, size_t elem_sz, int (*comp)(const void*, const void*)){

    mergesort_help(array,len,elem_sz,*comp,0,len-1,aux[]);
}
