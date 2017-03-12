CFLAGS = -Wall -std=gnu99 `gsl-config --cflags`
LDLIBS = `gsl-config --libs`

all:log
	cat log

log: main
	./main 2>&1 | tee log

main: main.o E.o

clean:
	$(RM) main *.o log
