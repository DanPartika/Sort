#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "mergesort.h"

void readfile(char *fileX, char *ftype){
    FILE *file = fopen(fileX, "r");
    if (file == NULL) {
        printf("Error: Cannot open '%s'. No such file or directory.\n", fileX);
        return EXIT_FAILURE;
    }
    char *buffer[1024];
    for (int i = 0; i < 1024; i++) {
        buffer[i] = (char*)calloc(66, sizeof(char));
    }
    

    int c = 0;
    while (fgets(buffer[c], 66, file)) {
        
    }
    
    
    
    char *inttp = "i";
    char *dbltp = "d";

}

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
        while ((opt = getopt(argc, argv, "id")) != -1) {
            switch (opt) {
            case 'i':
                if (argc == 2){
                    usage();
                } else {
                    readfile(argv[2],"i");
                }
                break;
        
            case 'd':
                if (argc == 2){
                    usage();
                } else {
                    readfile(argv[2], "d");
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
    return EXIT_SUCCESS;
}
