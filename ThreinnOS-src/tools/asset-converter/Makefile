CC = gcc

CFLAGS = -O2 -Wall -Wextra -std=c11

LDFLAGS = -lm

OBJ = main.o image.o writer.o resize.o

asset-converter: $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o asset-converter

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) asset-converter
