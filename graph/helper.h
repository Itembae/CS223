#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>



typedef struct node {
        char color;
        char majority;
        int length;  
        int size;     
        struct node **neighbors;
    } Node;

typedef struct _graph {
    int vertex;              /* number of vertices */
    int edges;              /* number of edges */
    Node **list;       //node 
} Graph;