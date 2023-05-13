CC=gcc
CFLAGS=-g3 -Wall

PROGRAMS = vectorTest

vectorTest : vectorTest.o vector.o
vectorTest.o : vectorTest.c vector.h

clean:
	$(RM) *.o $(PROGRAMS)