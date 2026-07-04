CC=gcc

CFLAGS=-Wall

TARGET=toolkit

SRC=src/main.c \
    src/conversions.c \
    src/arithmetic.c \
    src/bitwise.c \
	src/complements.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)