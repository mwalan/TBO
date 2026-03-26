CC = gcc
CFLAGS = -Wall -O3

all: josefo_lista josefo_vetor

josefo_lista: main.c josefo_lista.c
	$(CC) $(CFLAGS) main.c josefo_lista.c -o josefo_lista

josefo_vetor: main.c josefo_vetor.c
	$(CC) $(CFLAGS) main.c josefo_vetor.c -o josefo_vetor

clean:
	rm -f josefo_lista josefo_vetor