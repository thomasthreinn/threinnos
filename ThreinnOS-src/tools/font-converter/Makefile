CC = gcc

CFLAGS = -O2 -Wall -Wextra -std=c11

OBJ = main.o

font-converter: $(OBJ)
	$(CC) $(OBJ) -o font-converter

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) font-converter
