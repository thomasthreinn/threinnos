CC = gcc

CFLAGS = -O2 -Wall -Wextra -std=c11

LDFLAGS = -lm

OBJ = main.o font.o glyph.o writer.o

font-converter: $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o font-converter

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) font-converter
