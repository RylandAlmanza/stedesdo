CC=gcc
DEPS=*.h
main: $(DEPS) *.c
	$(CC) *.c -o main -g
