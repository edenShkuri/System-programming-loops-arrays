all:mains

mains: main.o  myBank.o
	gcc -Wall main.o myBank.o -o mains

main.o: main.c myBank.h
	gcc -Wall -c main.c -o main.o

myBank.o: myBank.c
	gcc -Wall -c myBank.c -o myBank.o
	
.PHONY: clean all

clean: 
	rm *.o -f mains
