CFLAGS = -Wall -std=gnu99
CFLAGS += `gsl-config --cflags`
LDLIBS += `gsl-config --libs`


PLOTTER = gnuplot

PLOTS = plot.png plot.jpeg plot.svg plot.pdf

.PHONEY: default
default: $(PLOTS)

$(PLOTS): plot.gpi data
	cat $< \
	| sed 's/TERM/$(subst .,,$(suffix $@))/; s/OUT/"$@"/' \
	| tee log$(suffix $@).txt | $(PLOTTER)

data: main Makefile
	./main -p -0.8 -e 0.02 > $@
#	./main --epsilon 0.02 --uprime -0.8 > $@

.PHONEY:clean
clean: ; $(RM) $(PLOTS) log* data main *.o plot.gpi

plot.gpi: Makefile
	echo 'set term   TERM' > $@
	echo 'set out    OUT' >> $@
	echo 'set title  "equatorial motion of a planet around a star"' >> $@
	echo 'set xlabel "x"' >> $@
	echo 'set ylabel "y"' >> $@
	echo 'set grid' >> $@
	echo 'plot "data" using (1/$$2)*sin($$1):(1/$$2)*cos($$1) with lines notitle ' >> $@
