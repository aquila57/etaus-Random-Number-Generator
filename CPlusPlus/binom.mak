OBJ=binom.o \
	etaus.o

CC=g++

CFLAGS=-c -Wall -O2

LDFLAGS=-lm

binom:				$(OBJ)
		$(CC) -Wall -O2 $(OBJ) -o binom $(LDFLAGS)

binom.o:			binom.cpp
		$(CC) $(CFLAGS) binom.cpp

etaus.o:			Etaus.cpp
		$(CC) $(CFLAGS) Etaus.cpp -o etaus.o

clean:
		rm -f $(OBJ) binom
