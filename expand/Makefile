CC=gcc
CFLAGS=-g3 -Wall

PROGRAMS = expand 

all: $(PROGRAMS)

expand : expand.o helper.o
expand.o : expand.c helper.h
helper.o : helper.c helper.h

clean:
	$(RM) *.o $(PROGRAMS)