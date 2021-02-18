CC = gcc

all: compile run

compile: student.c main.c 
	@$(CC) -c student.c main.c
	@$(CC) -o student.exe student.o main.o

run: 
	@./student.exe

clean: 
	@rm *o student.exe
