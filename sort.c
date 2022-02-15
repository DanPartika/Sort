#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <mergesort.h>

void readfile(){

}

void usage(){
    printf("Usage: ./sort [-i][-d] filename\n");
    printf("-i: Specifies the file containing ints.\n");
    printf("-d: Specifies the file contains doubles.\n");
    printf("filename: The file to sort.\n");
}

int main(int argc, char *argv[]) {
//160,533
    if (argc == 1){
        usage();
        return EXIT_FAILURE;

    } else if(argv[1] != '-' && argc == 2) {
        readfile();

    } else {
        int opt;
        while ((opt = getopt(argc, argv, "id")) != -1) {
            switch (opt) {
            case 'i':
                if (argc == 2){
                    usage();
                } else {
                    readfile();
                }
                break;
        
            case 'd':
                if (argc == 2){
                    usage();
                } else {
                    readfile();
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
    return 0;
}