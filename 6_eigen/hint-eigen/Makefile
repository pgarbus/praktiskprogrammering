CFLAGS = -Wall -std=gnu99
CFLAGS += `gsl-config --cflags`
LDLIBS += `gsl-config --libs`
PLOTTER = gnuplot

.PHONEY:all
all: efuns.pdf log efuns.png evals.pdf evals.png
	head log

efuns.png          : efuns.pdf         ; convert -density 200 $< $@
evals.png          : evals.pdf         ; convert -density 200 $< $@
efuns.pdf evals.pdf: plot.ppl data log ; $(PLOTTER) $<
data log           : main              ; ./$< 1> data  2> log

plot.ppl: Makefile
	echo 'set terminal pdf'           >  $@
	echo 'set title "eigen-functions"' >> $@
	echo 'set output "efuns.pdf"'      >> $@
	echo 'set xlabel "x"'       >> $@
	echo 'set ylabel "u(x)"' >> $@
	echo 'set key right'               >> $@
	echo 'set tics out'               >> $@
	echo 'set xzeroaxis'               >> $@
	echo 'set yzeroaxis'               >> $@
	echo 'plot \'                     >> $@
	echo ' "data" using "x":"u0" with lines title "u_0" \' >> $@
	echo ',"data" using "x":"u1" with lines title "u_1" \' >> $@
	echo ',"data" using "x":"u2" with lines title "u_2"  ' >> $@
	echo 'set output "evals.pdf"'      >> $@
	echo 'set title "eigen-values"' >> $@
	echo 'set xlabel "n"'       >> $@
	echo 'set ylabel "E_n"' >> $@
	echo 'set key left'               >> $@
	echo 'plot \'                     >> $@
	echo ' "log" using "n":"calculated" with linespoints title "calculated" \' >> $@
	echo ',"log" using "n":"exact" with linespoints title "exact"  ' >> $@

.PHONEY:clean
clean:
	$(RM) *.pdf *.png plot.ppl data main log *.c~

.PHONEY:indent
STYLE = --linux-style
indent: 
	indent $(STYLE) *.c