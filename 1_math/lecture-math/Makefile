CFLAGS = -Wall
LDLIBS = -lm

all: out.txt
	cat $<

out.txt: math
	./$< > $@

math: math.o hello.o

clean:
	$(RM) math.o hello.o math #out.txt