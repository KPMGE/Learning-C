CC = gcc
FLAGS = -lm

all: compile run 

compile: *.c
	@$(CC) -c *.c  
	@$(CC) -o complex.exe *.o $(FLAGS)

run: complex.exe
	@./complex.exe

clean: 
	@rm *.o complex.exe
