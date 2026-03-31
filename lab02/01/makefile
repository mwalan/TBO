# Compilador e flags de compilação
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Nome do executável final
TARGET = exec_bst

# Fontes do projeto
SRCS = main.c bst.c

# Regra principal
all: $(TARGET)

# Compilação direta para o executável
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Limpeza apenas do executável gerado
clean:
	rm -f $(TARGET)