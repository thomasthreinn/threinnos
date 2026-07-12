CC = gcc

CFLAGS = -O2 -Wall -Wextra -std=c11

OBJ = \
main.o \
image.o \
writer.o

asset-converter: $(OBJ)
	$(CC) $(OBJ) -o asset-converter

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o asset-converter
