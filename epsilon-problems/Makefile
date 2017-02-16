CFLAGS := -Wall -std=gnu99
LDLIBS := -lm
	
default: out.txt
	cat $<
out.txt : main
	./$< > $@