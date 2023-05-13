#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <ctype.h>
#include <stddef.h>
#include "vector.h"

struct vector {
    int *root;
    int top;
    int size; 
};

typedef struct vector Vector;

// Create a new vector with indices 0..n-1
// and all values initialized to value.
Vector *vectorCreate(size_t n, int value) {
    Vector *new; 
    new = malloc(sizeof(Vector));
    new->root = malloc(n*sizeof(int *)); 
    new->size = n;
    new->top = n; 

    int tmp = n; 

    for (int i = 0; i < tmp; i++) {
        new->root[i] = value;
    }
    return new;
}


// Destroy a vector, freeing all space.
void vectorDestroy(Vector *h) { 
    free(h->root);
    free(h);
}

// Return the number of slots in a vector
size_t vectorSize(const Vector *h) {
    size_t answer;
    answer = (h->top);
    return answer;
}

// Return a pointer to position i in a vector.
// This is equivalent to a+i for an array.
//
// The pointer is only guaranteed to be valid
// until the next insert or delete operation.
//
// Return 0 if i is out of range.
int *vectorRef(Vector *h, size_t i) {
    if (i >= h->size) {
        return NULL;
    }
    int *ref;
    ref = &(h->root[i]);
    return ref;
}

// Insert a new slot at position i.
// Slots previously at positions i or
// higher will move up by 1.
//
// New slot is initialized to value.
void vectorInsert(Vector *h, size_t i, int value) {
    
    if (i <= vectorSize(h)) {
        if (h->top == (h->size - 1)) {
                h->size = h->size*2;
                h->root = realloc(h->root, h->size * sizeof(int *));
            }
            h->top++;
            if (i == h->top - 1) {
                h->root[i] = value;
            } else {
                int j = h->top;
                while (j > i ) {
                    h->root[j] = h->root[j-1];
                    j--;
                }
                h->root[i-1] = value; 
                
            }
    }
    
}