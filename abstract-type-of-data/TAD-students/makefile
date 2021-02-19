CC = gcc

all: compile run

compile: *.c 
	@$(CC) -c *.c 
	@$(CC) -o student.exe *.o

run: 
	@./student.exe

clean: 
	@rm *o student.exe
