CFLAGS := -Wall -std=gnu99
LDLIBS := -lm
	
default: out.txt
	cat $<
out.txt : main
	./$< > $@

main : main.o
	cc main.o -o main

main.o : main.c
	cc -c main.c


.PHONEY: clean
clean:
	find . -type f -executable -delete
	$(RM) out.txt *.o