#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

#include "helper.h"


void expand(FILE *f);

int main(int argc, char *argv[]){ 
    //check if we are using command line args or stdin
    FILE *f; 
    if (argc == 1) {
        expand(stdin);
    } else {
        int len = argc;
        for (int i = 1; i < len; i++) {
            //should i open the file now or in my expand? doing it here allows me to have error message ASAP
            f = fopen(argv[i], "r");
            // printf("%s", argv[i]);
            if (f == 0) {
                printf("invalid file");
                exit(1);
            } else {
                expand(f);
            }
            fclose(f);
            // printf("hello");
        }
    }

    return 0;
}

    //iterate through the arguments of command line

    //iterate via getchar through the arguments of stdin
     
    //when you hit pipe symbol, fopen everything in between the two pipe symbols

    //if fopen works on the chunk, then make a copy of the files contents and add them to stdout

    //if fopen doesnt work, just read it to stdout

    // 

void expand(FILE *f) {
    // printf("hello");
    int x;
    int y;
    int iseof = 0;
    int isnull = 0;
    while ((x = fgetc(f)) != EOF) {
        if (x != '|') {
            printf("%c", x);
        } else {
            struct word *myword = create();
            while ((y = fgetc(f)) != '|') {
                if ( y == '\0') {
                    isnull = 1;
                }
                else if (y == EOF) {
                    iseof = 1;
                    printf("|");
                    printf("%s", myword->name);
                    break;
                } 
                    iseof = 0;
                    update(myword);
                    (myword->name)[myword->n] = y;
                    myword->n++;
                
                // printf("hahah");
            }
            // maybe change the inner loop file name? idk man
            
            if (iseof == 0) {
                if (isnull == 1) {
                    printf("|");
                    printf("%s", myword->name);
                    printf("|");
                }
                else {
                    (myword->name)[myword->n] = '\0';
                    FILE *f = fopen(myword->name, "r");
                    // printf("%s", myword->name);
                    if ((f == 0)) {
                        printf("|");
                        printf("%s", myword->name);
                        printf("|");
                    } else {
                        expand(f);
                        freeword(myword);
                    }
                }
            }
        } 
    }
    return;
}