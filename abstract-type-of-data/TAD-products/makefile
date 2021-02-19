CC = gcc
NAME_PROGRAM = products.exe

all: compile run

compile: ./src/*.c
	@mkdir obj
	@$(CC) -c main.c ./src/*.c
	@mv *.o ./obj
	@$(CC) -o $(NAME_PROGRAM) ./obj/*.o

run: $(NAME_PROGRAM)
	@./$(NAME_PROGRAM)

clean:
	@rm -rf *.txt $(NAME_PROGRAM) obj/
