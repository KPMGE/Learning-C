.PHONY = all clean

CC = gcc # compiler use
LINKERFLAG = -lm

SRCS := hello.c
BINS := hello

all: hello

hello: hello.c
	@echo "Compiling"
	${CC} hello.c -o hello ${LINKERFLAG}

clean:
	@rm hello
