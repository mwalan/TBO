CC = gcc
CFLAGS = -Wall -O3

all: quickunion

quickunion: main.c quick_union.c
	$(CC) $(CFLAGS) main.c quick_union.c -o quickunion

clean:
	rm -f quickunion