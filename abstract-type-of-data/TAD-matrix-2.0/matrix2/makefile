all: compile run

compile: 
	@gcc -c ./source/matrix.c 
	@gcc -c ./source/main.c 
	@gcc -o matrix1.exe matrix.o main.o

run: matrix1.exe
	@./matrix1.exe 

clean: 
	@rm -rf *.o matrix1.exe
