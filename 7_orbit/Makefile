CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)
CC = clang

# .PHONEY:all
# all : main
# 	./$<

PLOTTER = gnuplot
PLOTS = plot.png plot.jpeg plot.svg plot.pdf

.PHONEY: default
default: $(PLOTS)
	firefox plot.pdf

$(PLOTS): plot.gpi data # copied from fedorov
	cat $< \
	| sed 's/TERM/$(subst .,,$(suffix $@))/; s/OUT/"$@"/' \
	| tee log$(suffix $@).txt | $(PLOTTER)
	# cat $< \ # the content of plot.gpi is read in.
	# | sed 's/TERM/$(subst .,,$(suffix $@))/; s/OUT/"$@"/' \ # SED substitutes TERM with extension of PLOTS
	# # and OUT substitutes with the entire name of the current PLOTS item. 
	# | tee log$(suffix $@).txt \ # log$(suffix $@).txt is a bookkeeper file for gnuplot.
	# #log$(suffix $@).txt translates to log.png.txt, suffix func strips name from extension in $@
	# #tee sends the output from sed to a log.ext.txt file.
	# | $(PLOTTER) # input fed into gnuplot

data: main Makefile plot.gpi
	echo "0.01 1 -0.5" | ./$< > data # epsilon, u1, u2
	# variables for relativistic precessing planet around a sun.
.PHONEY: clean
clean:
	find . -type f -executable -delete
	$(RM) plot.* data *.txt

plot.gpi: Makefile # copied from Fedorov.
	echo 'set term   TERM' > $@
	echo 'set out    OUT' >> $@
	echo 'set title  "equatorial motion of a planet around a star"' >> $@
	echo 'set xlabel "x"' >> $@
	echo 'set ylabel "y"' >> $@
	echo 'set grid' >> $@
	echo 'plot "data" using (1/$$2)*sin($$1):(1/$$2)*cos($$1) with lines notitle ' >> $@