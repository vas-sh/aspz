CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2

TARGET = task117
SRC = main.c insort.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

main.o: main.c insort.h
insort.o: insort.c insort.h

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)