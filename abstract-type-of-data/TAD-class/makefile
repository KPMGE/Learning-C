CC = gcc

all: compile run

compile: *.c
	@$(CC) -c *.c 
	@$(CC) -o classStudentsProgram *.o

run: classStudentsProgram 
	@./classStudentsProgram 

clean: 
	@rm *.o classStudentsProgram 
