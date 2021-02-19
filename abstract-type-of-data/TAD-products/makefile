CC = gcc
NAME_PROGRAM = products.exe

all: compile run

compile: *.c
	@$(CC) -c *.c
	@$(CC) -o $(NAME_PROGRAM) *.o

run: $(NAME_PROGRAM)
	@./$(NAME_PROGRAM)

clean:
	@rm *.o $(NAME_PROGRAM)