CFLAGS = -Wall -std=gnu99 `gsl-config --cflags` #-DNDEBUG
LDLIBS = `gsl-config --libs`

all:log
	cat log

log:main
	./main 2> log

main: main.o Fe.o

.PHONEY:clean
clean:
	$(RM) main *.o log
