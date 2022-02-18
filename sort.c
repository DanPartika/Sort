#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "mergesort.h"


void usage(){
    printf("Usage: ./sort [-i][-d] filename\n");
    printf("-i: Specifies the file containing ints.\n");
    printf("-d: Specifies the file contains doubles.\n");
    printf("filename: The file to sort.\n");
}

int main(int argc, char *argv[]) {
//216940
//160757'
    
    if (argc == 1){
        usage();
        return EXIT_FAILURE;
    } else if(*(argv[1]) == '-' && argc == 2) {
        printf("Error: No input file specified.");
        return EXIT_FAILURE;

    } else {
        int opt;
        int mode = 0;
        while ((opt = getopt(argc, argv, "id")) != -1) {
            switch (opt) {
            case 'i':
                mode =1;
                if (argc == 2){
                    usage();
                } 
                break;
            case 'd':
            mode=2;
                if (argc == 2){
                    usage();
                } 
                break;
            default:
                fprintf(stderr, "Error: Uknown option '-%s' recieved\n", argv[1]);
                usage();
                return EXIT_FAILURE;
                break;
            }

        }
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error: Cannot open '%s'. No such file or directory.\n", file);
        return EXIT_FAILURE;
    }
    void* ptr; //points to int array to pass to mergesort
    size_t c = 0;//len
    size_t elem_sz=0;//elemsz
    int (pintr*)(const void*, const void*); //pointer to int/dbl_cmp
    
    if (mode == 1) {  //ints
        //declare int array and count
        
        int* array = (int*)malloc(sizeof(int)*1024);

        while( fscanf(file, "%d",array[c]) != EOF){
            c++;
            //set up mergesort parameters for int
            
        }
        ptr = array;
        elem_sz = 4; 
        pintr = &int_cmp;
    } else if (mode == 2){ //doubles
        double array[1024];

        while( fscanf(file, "%lf",array[c]) != EOF){
            c++;
            //set up mergesort parameters for int
            
        }
        ptr = array;
        elem_sz = 8;
        pintr=&dbl_cmp;
    }
    mergesort(ptr,c,elem_sz,pintr);
    //print the sorted array

    if (mode == 1) {
        for(size_t i = 0; i < c; i++){
            printf("%d", *((int*)ptr+i);
        }
    } else if (mode == 2) {
        for(size_t i = 0; i < c; i++){
            printf("%lf", *((double*)ptr+i);
        }
    }
    free(array);
    fclose(file);
    return EXIT_SUCCESS;
}
