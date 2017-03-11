CFLAGS = -Wall -std=gnu99 `gsl-config --cflags`
LDLIBS = `gsl-config --libs`
CC = gcc

report.pdf: report.tex plot.pdf
	pdflatex $<
	pdflatex $<

plot.pdf: plot.gpi data
	gnuplot plot.gpi

data: main
	./main > data

.PHONEY:clean
clean:
	$(RM) main data *.pdf *.log *.aux
