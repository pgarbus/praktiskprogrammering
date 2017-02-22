CFLAGS = -Wall -std=gnu99 `gsl-config --cflags`
LDLIBS = `gsl-config --libs`
CC = clang

plot.pdf: plot.ps
	ps2pdf plot.ps

plot.ps: plot.gpi data
	gnuplot plot.gpi

data: main
	./main > data

plot.gpi:Makefile
	echo 'set term postscript enhanced color' > $@
	echo 'set out "plot.ps"' >> $@
	echo 'plot \' >> $@
	echo ' "data" using 1:2 with lines title "calculated" \' >> $@
	echo ',"data" using 1:3 with points title "exact" \' >> $@

.PHONEY:clean
clean:
	$(RM) main data plot*
