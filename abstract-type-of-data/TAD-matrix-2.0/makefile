all: compile run

compile: *.c 
	@gcc -c *.c 
	@gcc -o matrix.exe *.o

run: matrix.exe
	@./matrix.exe

clean: 
	@rm *.o matrix.exe