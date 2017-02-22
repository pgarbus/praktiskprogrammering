CFLAGS = -Wall -std=c99 -O
LDLIBS = -lm

CC = clang
#ifeq ($(CC),clang)                        # don't copy this
#COMPILE.c = $(CC) $(CFLAGS) -c 2>$<.Wall  # it's only to collect
#endif                                     # clang warnings into a file

.PHONEY: all clean indent

all              : out.txt          ; cat $<           # "$<" is the first prerequisite
out.txt          : main             ; ./$< > $@        # "$@" is the target
main             : main.o komplex.o # built-in linking rule is used here         
main.o komplex.o : komplex.h        # built-in compilation rule is used here

clean            :                  ; $(RM) main out* *.o *~

STYLE = --linux-style
indent           :                  ; indent $(STYLE) main.c komplex.c; rm -f *.c~
