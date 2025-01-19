CC = gcc
CFLAGS = -std=c99 -Wall -Wextra  -Wvla -pedantic -Iinclude
LDFLAGS = 

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
TARGET = build/wc

all: $(TARGET)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

clean:
	rm -rf build/*.o $(TARGET)
