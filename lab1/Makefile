CC = gcc

CFLAGS = -Wall -std=c17 -g

all: countdown 

countdown: countdown.c
	$(CC) $(CFLAGS) countdown.c -o countdown

clean:
	rm countdown

.PHONY: all clean