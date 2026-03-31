CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

TARGET = exec_bst
SRCS = main.c bst.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)