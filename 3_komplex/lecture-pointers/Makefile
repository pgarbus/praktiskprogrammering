CFLAGS := -Wall -std=gnu99
LDLIBS := -lm

all: out-p.txt out-a.txt out-s.txt 
	cat $^

out-p.txt : p
	./$< > $@

out-a.txt : a
	./$< > $@

out-s.txt : s
	./$< > $@

clean:
	$(RM) out*.txt p a s
