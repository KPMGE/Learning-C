OBJ          = ./obj
INCLUDE      = ./include
SRC          = ./src
BIN          = ./bin
NAME_PROGRAM = finalProgram.exe       


all: directories libed create run 

directories:
	@ mkdir ${OBJ}
	@ mkdir ${BIN}

libed:\
	${OBJ}/main.o\
	${OBJ}/employee.o\
	${OBJ}/linked-list.o\


create: ${BIN}/${NAME_PROGRAM}


run:
	@ ./${BIN}/${NAME_PROGRAM}


valgrind: all
	@ clear
	@ valgrind ./${BIN}/${NAME_PROGRAM}
	@ echo "\n\n"


# rule for libed
${OBJ}/%.o: ${SRC}/%.c  
	@ ${CC} -c $< -I ${INCLUDE} -o $@
	@ echo " \033[0;35m  Generating compilation object \033[45;1;37m$@\033[0m\033[0;35m  \033[0m "
	@ echo ''


# rule for create
${BIN}/%: 
	@ ${CC} $< ${OBJ}/*.o -I ${INCLUDE} -o $@ ${FLAGS}
	@ echo " \033[0;33m  Building binary \033[43;1;37m$@\033[0m\033[0;33m  \033[0m "
	@ echo ''

clean:
	@ clear
	@ rm -rf ${BIN}
	@ rm -rf ${OBJ}
