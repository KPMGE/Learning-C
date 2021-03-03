CC = gcc

all: compile run 

compile: *.c
	@$(CC) -c *.c  
	@$(CC) -o complex.exe *.o

run: complex.exe
	@./complex.exe

clean: 
	@rm *.o complex.exe
