CFLAGS = -Wall -std=gnu99
LDLIBS = -lm
CC = clang
SCRIPT = log.gpi
FORMAT = pdf
PLOTTER = gnuplot

.PHONEY: all
all: plot.$(FORMAT)
	firefox $<

plot.$(FORMAT) : out-stdio.dat out-cmdline.dat Makefile
	echo 'set term $(FORMAT)' > $(SCRIPT)
	echo 'set out "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set xlabel "x"' >> $(SCRIPT)
	echo 'set ylabel "y"' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo '"$(word 1,$^)" with points title "stdio" \' >> $(SCRIPT)
	echo ',"$(word 2,$^)" with points title "cmdline" \' >> $(SCRIPT)
	echo ',sin(x) with lines \' >> $(SCRIPT)
	echo ',cos(x) with lines' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

out-stdio.dat : in.dat main-stdio
	./$(word 2,$^) < $< > $@

out-cmdline.dat : in.dat main-cmdline
	./$(word 2,$^) `cat $<` > $@

in.dat : Makefile
	cat /dev/null > $@ # /dev/null is a black hole for linux based systems.
	# used to clear content of a file.
	for x in `seq 0 0.2 10`; do echo $$x >> $@; done # 

.PHONEY: clean
clean :
	find ./ -type f -executable -delete
	$(RM) *.dat $(SCRIPT) *.svg *.png *.pdf log*

.PHONEY: test
test:
	find ./ -type f -executable -exec echo {} \;
