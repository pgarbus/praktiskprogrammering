CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)
CC = clang	

PLOTTER = gnuplot
PLOTS = integration.pdf oscillation.pdf
DATA = integration.out oscillation.out

.PHONEY: default clean

default : integration.pdf oscillation.pdf
	firefox $<
	firefox oscillation.pdf

# tried long and hard to make for-loops in the makefile... 
# and execute the different arguments from $^
$(PLOTS): plot.gpi $(DATA) oscillation.out
	cat $< \
	| sed 's/TERM/$(subst .,,$(suffix $@))/; s/TITLE/$(basename $@)/ ; s/OUT/$@/' \
	| tee $(basename $@).gpi | $(PLOTTER)

$(DATA): integration
	./$< > $@

oscillation.out : main
	./$< > $@


main : oscillation.o
# %.o : %.h

clean:
	find . -type f -executable -delete
	$(RM) *.pdf *.out *.gpi *.o

plot.gpi: Makefile
	echo "set term TERM" > $@
	echo "set out 'OUT'" >> $@
	echo "set title 'TITLE'" >> $@
	echo "set xlabel 'x'" >> $@
	echo "set ylabel 'y'" >> $@
	echo "set key bottom right" >> $@
	echo "set xrange [-0.05:1.0]" >> $@
	echo "set yrange [-50:10]" >> $@
	echo "plot 'integration.out' with filledcurves below y1=0 title 'integrated area for each segment dx.'" >> $@


	echo 'set output "oscillation.pdf"' >> $@
	echo 'set grid' >> $@
	echo 'set title "Energy as a function of the {/Symbol a}-parameter"' >> $@
	echo 'set xlabel "{/Symbol a}"' $@
	echo 'set ylabel "E({/Symbol a})"' >> $@
	echo 'set xrange [0.5:1.5]' >> $@
	echo 'set yrange [0.4:0.6]' >> $@
	echo 'plot "oscillation.out" with lines title "expectation value E vs alpha"' >> $@