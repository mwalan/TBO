CC = gcc
CFLAGS = -Wall -O3

all: dijkstra

dijkstra: main.c pilha.c
	$(CC) $(CFLAGS) main.c pilha.c -o dijkstra

clean:
	rm -f dijkstra