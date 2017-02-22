CFLAGS = -Wall -std=gnu99 -O `gsl-config --cflags`
LDLIBS = $$(gsl-config --libs)

plot.png: plot.gpi data
	gnuplot $<

data: main
	./$< > $@

plot.gpi: Makefile
	echo 'set term png' > $@
	echo 'set out "plot.png"' >> $@
	echo 'set xlabel "x"' >> $@
	echo 'set ylabel "f(x)"' >> $@
	echo 'plot \' >> $@
	echo ' "data" using "x":"J0" with lines title "J_0" \' >> $@
	echo ',"data" using "x":"J1" with lines title "J_1" ' >> $@

.PHONEY: test
test:
	echo $(CFLAGS)
	echo $(LDLIBS)

.PHONEY: clean
clean:
	$(RM) main plot* *.png data
