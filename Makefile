CC=gcc

CFLAGS=-Wall

TARGET=toolkit

SRC=src/main.c \
    src/conversions.c \
    src/arithmetic.c \
    src/bitwise.c \
	src/complements.c \
	src/bcd.c \
	src/graycode.c \
	src/utils.c \
	src/ieee754.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)