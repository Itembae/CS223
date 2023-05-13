#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

#include "helper.h"


//should i make one more array struct for my neighbor list

//should i just use hashtable to simplify vertex refering? (s.t (0,1) corresponds to a hashvalue)

//(row* #number of columns + column)
//how the hell does this work if i am never creating a designation  between rows and columns

int main(int argc, char *argv[]){ 
    int steps;
    scanf("%d", &steps);

    int rows;
    int columns;
    scanf("%d %d", &rows, &columns); 
    getchar();

    //should this be a graph pointer
    Graph *graph = malloc(sizeof(Graph)); 
    //predeclare how many elements my graph array will have
    //should i maybe make another dumb boy for my struct 
    graph->list = malloc(rows * sizeof(Node **));
    
    //load babies into graph rows and columns 
    for (int i = 0; i < rows; i++) {
        //one more *? 
        graph->list[i] = malloc(columns * sizeof(Node));
        for (int j = 0; j < columns; j++) {
            char clr;
            //probably use getchar for any given one --scanf sketchy
            scanf("%c", &clr);
            //sus as hell-- node * 
            Node *tmp;
            tmp = malloc(sizeof(Node));
            tmp->length = 0; 
            tmp->size = 2;
            tmp->color = clr;
            tmp->majority = clr; 
            tmp->neighbors = malloc(2*sizeof(Node *));
            (graph)->list[i] = tmp;
            printf("%c", tmp->color);
            graph->vertex++;
        }
        getchar();
        printf("\n");
    }
    
    int sink1;
    int sink2;
    int source1;
    int source2;
    
    while (scanf("%d %d %d %d[^\n]", &source1, &source2, &sink1, &sink2) == 4) {
        printf("%d %d %d %d \n", source1, source2, sink1, sink2);
        //make it so that I am entering correct position on neighbor list 
        int key = (source1 * columns + source2);
        int keys = ((sink1 * columns) + sink2);

        if ((graph)->list[key]->length >= (graph)->list[key]->size) {
            (graph)->list[key]->size = 2 * (graph)->list[key]->size;
            (graph)->list[key]->neighbors = realloc((graph)->list[key]->neighbors, (graph)->list[key]->size * sizeof(Node *));
        }
        (graph)->list[key]->neighbors[(graph)->list[key]->length] = (graph)->list[keys];
        (graph)->list[key]->length++;
        graph->edges++;
        //add edges to sink 
        
        if ((graph)->list[keys]->length >= (graph)->list[keys]->size) {
            (graph)->list[keys]->size = 2 * (graph)->list[keys]->size;
            (graph)->list[keys]->neighbors = realloc((graph)->list[keys]->neighbors, (graph)->list[keys]->size * sizeof(Node *));
        }
        (graph)->list[keys]->neighbors[(graph)->list[keys]->length] = (graph)->list[key];
        (graph)->list[keys]->length++;
        graph->edges++;
    }


    // //loop for every step
    for (int i = 0; i < steps; i++) {
        //loop over every row
        printf("\n");
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < columns; k++) {
                //loop over every edge of a vertex and count up kids 
                int noughts = 0;
                int crosses = 0;
                int key = (j * columns + k); 
                for (int count = 0; count < graph->list[key]->length; count++) {
                    if ((graph)->list[key]->neighbors[count]->color == 'X') {
                        crosses++;
                    } else if ((graph)->list[key]->neighbors[count]->color == '.') {
                        noughts++;
                    }
                }
                if (noughts > crosses) {
                    (graph)->list[key]->majority = '.'; 
                } else if (crosses > noughts) {
                    (graph)->list[key]->majority = 'X'; 
                    //completely unnecessary right?
                } else {
                    (graph)->list[key]->majority = (graph)->list[key]->color;
                }
            }
        }
        //update colors to match their majorities
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < columns; k++) {
                int key = (j * columns + k); 
                (graph)->list[key]->color = (graph)->list[key]->majority;
                printf("%c", (graph)->list[key]->color);
            }        
            printf("\n");
        }
    }

    for (int j = 0; j < rows; j++) {
        for (int k = 0; k < columns; k++) {
            int key = (j * columns + k); 
            free((graph)->list[key]->neighbors);
            free((graph)->list[key]);
        }
    }
    free ((graph)->list);
    free(graph);
    return 0;
}