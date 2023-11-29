all: pilha.o main.o
	gcc main.o pilha.o -o main -g -std=c99 -Wall

pilha.o:
	gcc -c pilha.c -o pilha.o

main.o:
	gcc -c main.c -o main.o

clean:
	rm main.o pilha.o ./main

run:
	./main