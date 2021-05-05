FLAGS = -lm -pedantic -Wall 
NAMEBIN = final.exe
CC = gcc

all: link compile  

link: \
	main.o\
	shape.o\
	rectangle.o\

%.o: %.c %h
	@ ${CC} -c $^

compile:
	@ ${CC} -o ${NAMEBIN} ${FLAGS} *.o

run: ${NAMEBIN}
	@ ./${NAMEBIN}

clean: 
	@ rm -rf *.o ${NAMEBIN}
