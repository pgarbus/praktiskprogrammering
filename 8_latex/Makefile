CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)
CC = gcc

PLOT = plot.pdf
PLOTTER = gnuplot
REPORT = report.pdf

.PHONEY: all
all : $(REPORT)
	firefox $<

$(REPORT): report.tex $(PLOT)
	pdflatex $<
	pdflatex $<

$(PLOT): plot.gpi data
	cat $< | $(PLOTTER)
data : main
	./$< -2.95 2.95 0.1 > data

plot.gpi: Makefile
	echo "set term pdf" > $@
	echo "set out 'plot.pdf'" >> $@
	echo "set size 0.6,0.6" >> $@
	echo "set tics out" >> $@
	echo "set xlabel 'x'" >> $@
	echo "set ylabel 'error value'" >> $@
	echo "plot 'data' using 1:2 with lines title 'error function'" >> $@


.PHONEY: clean
clean:
	find . -type f -executable -delete
	$(RM) *.txt plot.* data *.pdf