default : out.txt
	cat out.txt
out.txt : main
	./main > out.txt
main : main.o
	cc main.o -o main 
main.o : main.c
	cc -c main.c 
clean : 
	rm --force main.o main out.txt