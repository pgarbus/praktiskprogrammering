CFLAGS := -Wall -std=gnu99
LDLIBS := -lm
CC = clang
CC = gcc
.PHONEY: all clean indent test

all: out.txt
	cat $^

out.txt : main
	./$< > $@
main : main.o nvector.o
main.o nvector.o : nvector.h
clean:
	$(RM) out.txt main

indent:
	indent --linux-style *.c; rm -f *.c~