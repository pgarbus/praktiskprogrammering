CFLAGS = -Wall -Werror -std=gnu99
LDLIBS = -lm

all: main-cmdline main-stdio
main-cmdline : main-cmdline.c
main-stdio : main-stdio.c

.PHONEY: clean
clean:
	rm -f main-stdio.o main-stdio main-cmdline.o main-cmdline test.io.out.txt


