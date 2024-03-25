#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

#include "helper.h"


// struct word {
//     size_t size;
//     size_t n;
//     char *name;
// };

struct word *create(void) {
    struct word *h = malloc((sizeof(char *)) + (2*sizeof(size_t)));
    h->size = 1;
    h->n = 0;
    h->name = calloc(h->size, sizeof(char));
    return h;
}

void update(struct word *h) {
    if ((h->n) == (h->size) - 1) {
        h->size = (h->size)*2; 
        h->name = realloc(h->name, (h->size) *sizeof(char));
    }
    return;
}

void freeword(struct word *h) {
    free(h->name);
    free(h);
    return;
}


// void expand(FILE *f) {
//     int x;
//     int y;
//     while ((x = fgetc(f)) != EOF) {
//         if (x != '|') {
//             printf("%c", x);
//         } else {
//             struct word *myword = create();
//             while ((y = fgetc(f)) != '|') {
//                 update(myword);
//                 myword->name[myword->n] = y;
//                 myword->n++;
//             }
//             // maybe change the inner loop file name? idk man
//             FILE *f = fopen(myword->name, "w");
//             if (f == 0) {
//                 printf("|");
//                 printf("%s", myword->name);
//             } else {
//                 expand(f);
//                 freeword(myword);
//             }
//         }       
//     }
//     return;
// }



