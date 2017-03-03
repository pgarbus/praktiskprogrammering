CFLAGS = -Wall -std=gnu99 -O `gsl-config --cflags`
LDLIBS = $$(gsl-config --libs)

# all : out.txt
# 	cat $^	
# out.txt : eigen
# 	./$< > $@

# all : test.dat
# 	less $<
# test.dat : eigen
# 	./eigen

all: box eigen
	./box
# eigen : eigen.c

.PHONEY: clean
clean : 
	$(RM) eigen *.txt *.dat box