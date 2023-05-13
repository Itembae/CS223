#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <ctype.h>

#include "vector.h"

#define N (20)

// print all elements of v
static void
vectorPrint(Vector *v)
{
    size_t n = vectorSize(v);

    if(n == 0) {
        puts("EMPTY");
    } else {
        printf("%d", *vectorRef(v, 0));
        for(size_t i = 1; i < n; i++) {
            printf(" %d", *vectorRef(v, i));
        }
        putchar('\n');
    }
}

static void 
fail(const char *s)
{
    fputs(s, stderr);
    putc('\n', stderr);
    exit(1);
}

int
main(int argc, char **argv)
{

    if(argc != 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    // always have a vector
    Vector *v = vectorCreate(0, 0);

    char command;
    size_t index;
    int value;
    int *ref;

    while(scanf("%c", &command) == 1) {
        switch(command) {

            case 'p':
                // print vector
                vectorPrint(v);
                break;

            case 'c':
                // destroy old vector, create new one
                if(scanf("%zu %d", &index, &value) != 2) {
                    fail("bad arguments to c");
                }

                vectorDestroy(v);
                v = vectorCreate(index, value);
                break;

            case 'z':
                // get size
                printf("%zu\n", vectorSize(v));
                break;

            case 'f':
                // fetch
                if(scanf("%zu", &index) != 1) {
                    fail("bad arguments to f");
                }
                ref = vectorRef(v, index);
                if(ref != 0) {
                    printf("%d\n", *ref);
                } else {
                    printf("index %zu out of bounds in f\n", index);
                }
                break;

            case 's':
                // store
                if(scanf("%zu %d", &index, &value) != 2) {
                    fail("bad arguments to s");
                }
                ref = vectorRef(v, index);
                if(ref != 0) {
                    *ref = value;
                } else {
                    printf("index %zu out of bounds in s\n", index);
                }
                break;

            case 'i':
                // insert
                if(scanf("%zu %d", &index, &value) != 2) {
                    fail("bad arguments to i");
                }
                vectorInsert(v, index, value);
                break;

            default:
                if(!isspace(command)) {
                    fprintf(stderr, "bad command '%c'\n", command);
                }
                break;
        }
    }

    vectorDestroy(v);
}