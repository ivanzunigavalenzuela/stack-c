# Makefile del proyecto stack-c
# Cada regla dice: que archivo se produce, de que archivos depende y que comando lo crea.

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iinclude

OBJECTS = build/stack_create.o build/stack_push.o build/stack_pop.o \
          build/stack_peek.o build/stack_is_empty.o build/stack_destroy.o

all: build/stack_demo

build/stack_demo: $(OBJECTS) build/main.o
	$(CC) $(CFLAGS) $(OBJECTS) build/main.o -o build/stack_demo

build/test_stack: $(OBJECTS) build/test_stack.o
	$(CC) $(CFLAGS) $(OBJECTS) build/test_stack.o -o build/test_stack

build/stack_create.o: src/stack_create.c include/stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c src/stack_create.c -o build/stack_create.o

build/stack_push.o: src/stack_push.c include/stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c src/stack_push.c -o build/stack_push.o

build/stack_pop.o: src/stack_pop.c include/stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c src/stack_pop.c -o build/stack_pop.o

build/stack_peek.o: src/stack_peek.c include/stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c src/stack_peek.c -o build/stack_peek.o

build/stack_is_empty.o: src/stack_is_empty.c include/stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c src/stack_is_empty.c -o build/stack_is_empty.o

build/stack_destroy.o: src/stack_destroy.c include/stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c src/stack_destroy.c -o build/stack_destroy.o

build/main.o: src/main.c include/stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/test_stack.o: tests/test_stack.c include/stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c tests/test_stack.c -o build/test_stack.o

run: build/stack_demo
	./build/stack_demo

test: build/test_stack
	./build/test_stack

clean:
	rm -rf build

.PHONY: all run test clean
