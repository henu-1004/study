# Makefile
CC = gcc
CFLAGS = -c -g
LDFLAGS =  
OBJECTS = main.o calc.o stack.o queue.o

all: calculator

calculator : $(OBJECTS)
	$(CC)  $(LDFLAGS) -o calculator $(OBJECTS) -lm

main.o : main.c
	$(CC) $(CFLAGS) main.c 

calc.o : calc.c
	$(CC) $(CFLAGS) calc.c

stack.o : stack.c
	$(CC) $(CFLAGS) stack.c
	
queue.o : queue.c
	$(CC) $(CFLAGS) queue.c

clean:
	rm -f *.o\

.PHONY: all bonus clean fclean re