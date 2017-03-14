CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)
CC = clang

# .PHONEY: default
default: plot.gpi decay.out rosenbrock.out
	gnuplot $<
	firefox rosenbrock.pdf

decay.out: decay
	./$< > $@ 2> decay.log

rosenbrock.out: rosenbrock
	./$< > $@ 2> rosenbrock.log

.PHONEY: clean
clean:
	find . -type f -executable -delete
	$(RM) *.log *.out *.pdf