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

void mergesort_help(void* array, size_t len, size_t elem_sz, int (*comp)(const void*, const void*),int i,int j,void* other_array) { 
    if (j<=i){
        return;
    }
    int mid = (i+j) / 2;
    mergesort_help(array, len, elem_sz, comp, i, mid, other_array);
    mergesort_help(array, len, elem_sz, comp, mid+1, j, other_array);

    int lft = i;
    int rgt = mid+1;
    int counter;

    for(counter=i;counter<=j;counter++){
        if(lft == (mid+1)) {
            //other_array[counter]=array[rgt] rgt++
            if (elem_sz == 4) {
                *((int *)other_array + counter) = *((int *) array + rgt);
            } else if (elem_sz == 8) {
                *((double *)other_array + counter) = *((double *) array + rgt);
            }
            rgt++;
        } else if (rgt == (j+1)) {
            //other_array[counter]=array[lft] lft ++
            if (elem_sz == 4) {
                //int 
                *((int *)other_array + counter) = *((int *) array + lft);
            } else if (elem_sz == 8){
                *((double *)other_array + counter) = *((double *) array + lft);
            }
            lft++;
        } else if (comp((array+lft*elem_sz), array+rgt*elem_sz) == -1 ) {
            //other_array[counter] = array[rgt] rgt++
            
            if (elem_sz == 4) {
                //int 
                *((int *)other_array + counter) = *((int *) array + lft);
            } else if (elem_sz == 8){
                *((double *)other_array + counter) = *((double *) array + lft);
            }
            lft++;
        } else {
            //other_array[counter] = array[lft] lft++
            if (elem_sz == 4) {
                *((int *)other_array + counter) = *((int *) array + rgt);

            } else if (elem_sz == 8) {
                *((double *)other_array + counter) = *((double *) array + rgt);
            }
            rgt++;
        }
    }

//put other_array into array
    if (elem_sz == 4) {
        for (counter = i; counter <= j; counter++) {
            //array[counter] = other_array[counter]
            //int 
            *((int *)array + counter) = *((int *) other_array + counter);
        }
    } else if (elem_sz == 8){
        for (counter = i; counter <= j; counter++) {
            //double
            *((double *)array + counter) = *((double *) other_array + counter);
        }
    }
}


//Mergesort
void mergesort(void* array, size_t len, size_t elem_sz, int (*comp)(const void*, const void*)){
    //int other_array [1024];
    void* pointertoarray;
    if (elem_sz == 4) {
        pointertoarray = (int*)malloc(sizeof(int)*1024);
    } else if (elem_sz == 8){
        pointertoarray = (double*)malloc(sizeof(double)*1024);
    }
    mergesort_help(array,len,elem_sz,comp,0,(len-1),pointertoarray);
}
