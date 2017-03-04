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
# .PHONEY: all
# all : out.txt error.txt
# 	./main 1> $(word 1, $^) 2> $(word 2, $^)
.PHONEY: all
all : out.txt
	tail -4 $<
out.txt error.txt: main
	./$< 1> out.txt 2> error.txt
# out.txt error.txt : main
	# echo $@
	# ./$< 1> $(word 1, $@) 2> $(word 2, $@)
main : helper.o box.o eigen.o
%.o : %.h
# eigen : eigen.c

.PHONEY: clean
clean : 
	$(RM) eigen *.txt *.dat box main *.o