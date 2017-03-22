CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)
CC = gcc

PLOT = plot.pdf
PLOTTER = gnuplot
REPORT = report.pdf

.PHONEY: all
all : $(REPORT)
	gnuplot plot.gpi && firefox report.pdf && ./main
# all : main
# 	./main


$(REPORT): report.tex $(PLOT)
	pdflatex $<
	pdflatex $<

$(PLOT): plot.gpi math_h_tan.out odeiv.out
	cat $< | $(PLOTTER)

odeiv.out math_h_tan.out : main
	./$<

plot.gpi: Makefile
	echo "set term pdf" > $@
	echo "set out 'plot.pdf'" >> $@
	echo "set size 0.6,0.6" >> $@
	echo "set tics out" >> $@
	echo "set key left top" >> $@
	echo "set xlabel 'x ["{/Symbol p}"]'" >> $@
	echo "set ylabel 'y'" >> $@
	echo 'set xtics ("-1/8" -pi/8, "-1/4" -pi/4, "-3/8" -3*pi/8, "-1/2" -pi/2, "0" 0, "1/8" pi/8, "1/4" pi/4, "3/8" 3*pi/8, "1/2" pi/2)' >> $@
	echo "set xrange [-pi/2:pi/2]" >> $@
	echo "set yrange [-20:20]" >> $@
	echo 'plot \' >> $@ # gnuplot doesn't support \"
	echo '"odeiv.out" using 1:2 with points title "ODEIV2 tan(x)", \' >> $@ # if space after '\' gnuplot fails
	echo '"math_h_tan.out" using 1:2 with lines title "math.h tan(x)"' >> $@
	# echo '"$(word 1,$^)"  using 1:2 with points ps 0.2 title "Numerical Data" \' >> plot.gpi
	# echo ', x*exp(-x) title "Analytical Function" ' >> plot.gpi
	# echo "plot 'data' using 1:2 with lines title 'error function'" >> $@


.PHONEY: clean
clean:
	find . -type f -executable -delete
	$(RM) *.txt plot.* data *.pdf *.log *.aux *.out