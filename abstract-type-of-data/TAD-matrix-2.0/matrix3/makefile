OBJ = ./obj

all: compile run

compile:  
	@gcc -c ./source/*.c 
	@mv *.o ./obj
	@gcc -o matrix1.exe ./obj/*.o

run: matrix1.exe
	@./matrix1.exe 

clean: 
	@rm -rf ./obj/*.o matrix1.exe
