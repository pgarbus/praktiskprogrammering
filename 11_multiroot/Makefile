CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)

default: plots.pdf data.out
	firefox plots.pdf
	# $(RM) *.o

# plots.pdf: data.out Makefile
# 	echo'\
# 	set terminal "$(subst .,,$(suffix $@))";\
# 	set output "$@";\
# 	set title "my plot";\
# 	plot "$<" 1:2 with points ps 7 title "Numerical Data, \
# 		x*exp(-x) title "Analytical Function\ 
# 	'| tee plot.gpi | pyxplot
data.out: main
	./main

plots.pdf: data.out Makefile
	echo 'set term pdf' > plot.gpi
	echo 'set out "$@"' >> plot.gpi
	echo 'set xlabel "radius"' >> plot.gpi
	echo 'set ylabel "radial wave function"' >> plot.gpi
	echo 'set key right top' >> plot.gpi
	echo 'plot \' >> plot.gpi
	echo '"$(word 1,$^)"  using 1:2 with points ps 0.2 title "Numerical Data" \' >> plot.gpi
	echo ', x*exp(-x) title "Analytical Function" ' >> plot.gpi
	gnuplot plot.gpi

main: main.o auxilian_Me.o

.PHONEY:clean
clean:	
	find . -type f -executable -delete
	$(RM) *.o *.out *.gpi *.pdf