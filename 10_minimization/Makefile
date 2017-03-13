CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)
CC = clang

default: rosenbrock
	./$<

.PHONEY: clean
clean:
	find . -type f -executable -delete
	$(RM) main