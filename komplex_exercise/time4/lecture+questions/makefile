CFLAGS := -Wall -std=gnu99
LDLIBS := -lm

default: out4.txt out2.txt out3.txt
	cat $<

out.txt : p
	./$< > $@

out2.txt : a
	./$< > $@

out3.txt : s
	./$< > $@

out4.txt : questions
	./$< > $@