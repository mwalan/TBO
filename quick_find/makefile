CC = gcc
CFLAGS = -Wall -O3

all: quickfind

quickfind: main.c quick_find.c
	$(CC) $(CFLAGS) main.c quick_find.c -o quickfind

clean:
	rm -f quickfind