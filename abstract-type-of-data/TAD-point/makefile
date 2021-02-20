CC = gcc
FLAGS = -lm

all: compile run

compile: *.c
	@$(CC) -c *.c  
	@gcc -o point.exe *.o $(FLAGS)

run: point.exe
	@clear
	@./point.exe

clean:
	@rm *.o point.exe
