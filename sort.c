#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "mergesort.c"

//usage function that just prints the usage.
void usage(){
    printf("Usage: ./sort [-i|-d] filename\n");
    printf("-i: Specifies the file contains ints.\n");
    printf("-d: Specifies the file contains doubles.\n");
    printf("filename: The file to sort.\n");
}

int main(int argc, char *argv[]) {
    int mode = 0; //used to see if file has ints or doubles
    int check = 0; //used to error check for too many valid flags
    
    if (argc == 1){ //no arguements
        usage();
        return EXIT_FAILURE;
    } else {
        int opt; //used for getopt loop
        while ((opt = getopt(argc, argv, ":id")) != -1) {
            switch (opt) {
                case 'i':
                    if (argc == 2){ // checks to see if there is a file after the flag
                        printf("Error: No input file specified.\n");
                        return EXIT_FAILURE;
                    } 
                    mode = 1; //mode = ints
                    check++;
                    break;
                case 'd':
                    if (argc == 2){ // checks to see if there is a file after the flag
                        printf("Error: No input file specified.\n");
                        return EXIT_FAILURE;
                    } 
                    mode = 2; //mode = doubles
                    check++;
                    break;
                default:
                    fprintf(stderr, "Error: Uknown option '-%c' recieved.\n", optopt);
                    usage();
                    return EXIT_FAILURE;
                    break;
            }

        }
    }
    if (check > 1){ //checks to see if there is only one valid flag
        printf("Error: Too many flags specified.\n");
        return EXIT_FAILURE;
    }
    //at this point no errors in flags so check to see if theres only one file
    if (argc > 3){ 
        printf("Error: Too many files specified.\n");
        return EXIT_FAILURE;
    }
    //Opening the file
    FILE* file = fopen(argv[2], "r");
    if (file == NULL) { //checks to see if it is empty
        printf("Error: Cannot open '%s'. No such file or directory.\n", argv[2]);
        return EXIT_FAILURE;
    }
    void* ptr; //points to int array to pass to mergesort
    size_t len = 0;//len
    size_t elem_sz=0;//elemsz
    int (*pintr)(const void*, const void*); //pointer to int/dbl_cmp
    
    if (mode == 1) {  //ints
        //declare int array and count
        
        int* array = (int*)malloc(sizeof(int)*1024);

        while( fscanf(file, "%d\n",&array[len]) != EOF){
            len++;
            //set up mergesort parameters for int
        }
        ptr = array;
        elem_sz = 4; 
        pintr = &int_cmp;
    } else if (mode == 2) { //doubles
        double* array = (double*)malloc(sizeof(double)*1024); 

        while( fscanf(file, "%lf\n",&array[len]) != EOF){
            len++;
            //set up mergesort parameters for int
            
        }
        ptr = array;
        elem_sz = 8;
        pintr=&dbl_cmp;
    }
    //for(size_t i = 0; i < len; i++){
    //    printf("%d\n", *((int*)ptr+i));
    //}
    mergesort(ptr,len,elem_sz,pintr);
    //print the sorted array
    if (mode == 1) { //print int array
        for(size_t i = 0; i < len; i++){
            printf("%d\n", *((int*)ptr+i));
        }
    } else if (mode == 2) { //print double array
        for(size_t i = 0; i < len; i++){
            printf("%lf\n", *((double*)ptr+i));
        }
    }

    free(ptr);  //free dynamically allocated memory
    fclose(file); //close the file
    return EXIT_SUCCESS; //EXIT SUCCESS!
}
