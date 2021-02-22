CC = gcc
NAME_OBJ = tic-tac-toe

all: compile run

compile: *.c ./src/*.c
	@$(CC) -c *.c ./src/*.c
	@mv *.o ./obj
	@$(CC) -o $(NAME_OBJ) ./obj/*.o

run: $(NAME_OBJ)
	@./$(NAME_OBJ)

clean:
	@rm $(NAME_OBJ) 