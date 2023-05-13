#include <stdio.h> 

struct word {
    size_t size;
    size_t n;
    char *name;
};

struct word *create(void);

void update(struct word *h);

void freeword(struct word *h);


