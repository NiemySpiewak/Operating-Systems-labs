CC = gcc
CFLAGS = -Wall -std=c17 
PATH_DIR_LOC = /home/user/SysOpy

.PHONY: all 

all: flipper

flipper:
	$(CC) $(CFLAGS) flipper.c -o flipper

run: flipper
	./flipper $(PATH_DIR_LOC)/art $(PATH_DIR_LOC)/art_o

clean:
	rm flipper
	rm -r ./art_o
