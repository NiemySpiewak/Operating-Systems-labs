CC = gcc
CFLAGS = -Wall -Wextra -std=c17
LIB_NAME = libcollatz

.PHONY: all clean

all: static_client shared_client dynamic_client

static_client: collatz.o client.o
	ar rcs $(LIB_NAME).a collatz.o
	$(CC) $(CFLAGS) -o static_client client.o -L. -lcollatz

shared_client: collatz.o client.o
	$(CC) $(CFLAGS) -fPIC -shared -o $(LIB_NAME).so collatz.c
	$(CC) $(CFLAGS) -o shared_client client.c -L. ./$(LIB_NAME).so 

dynamic_client: collatz.o dynamic_client.o
	$(CC) $(CFLAGS) -o dynamic_client dynamic_client.o -ldl

collatz.o: collatz.c collatz.h
	$(CC) $(CFLAGS) -fPIC -c collatz.c

client.o: client.c collatz.h
	$(CC) $(CFLAGS) -c client.c

dynamic_client.o: dynamic_client.c
	$(CC) $(CFLAGS) -c dynamic_client.c

clean:
	rm *.o *.a *.so static_client shared_client dynamic_client
