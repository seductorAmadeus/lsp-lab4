CC=gcc
IDIR=./include
CFLAGS= -pedantic -Wall -std=c89 -I$(IDIR)
BDIR=./build
TARGET=main
SRC=$(wildcard src/*.c)
build=$(SRC:src/%.c=build/%.o)
FILES = main.c

make: $(build)
	$(CC) -o $(TARGET) $(build)

build/%.o: src/%.c 
	$(CC) -c -g -o $@ $< $(CFLAGS)

clean:
	rm -rf $(TARGET) build/
	mkdir build
