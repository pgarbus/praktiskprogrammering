CFLAGS = -Wall -std=gnu99
LDLIBS = -lm
CC = gcc
CC = clang

.PHONEY: all
all: out.txt error.txt
	for f in $^; do echo --- $$f ---; cat $$f; done

out.txt error.txt : io
	echo 1.23 2.34 3.45 | ./io 6.78 1> out.txt 2> error.txt

io: io.o f.o

clean:
	find . -type f -executable -delete
	$(RM) *.o *.txt
