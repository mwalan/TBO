CC = gcc
CFLAGS = -Wall -O3

# Adicionamos crivo_char na regra principal
all: crivo_int crivo_char crivo_bit

crivo_int: main.c crivo_int.c
	$(CC) $(CFLAGS) main.c crivo_int.c -o crivo_int

# Nova regra para compilar a versão char
crivo_char: main.c crivo_char.c
	$(CC) $(CFLAGS) main.c crivo_char.c -o crivo_char

crivo_bit: main.c crivo_bit.c
	$(CC) $(CFLAGS) main.c crivo_bit.c -o crivo_bit

clean:
	rm -f crivo_int crivo_char crivo_bit