GCC = gcc
CFLAGS = -g -Wall -Wshadow
SRCS = 
OBJS = $(SRCS:.c=.o) #OBJS = 

#compile and limmk the program
program: $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o 

#implicit rules for object files:
.c.o:
	$(GCC) $(CFLAGS) -c $*.c

#test the program using predefined cases
test: program
	for case in  0 1 2 3; do \
		echo "Running test case $$case:"; \
		./program inputs/input$$case > output$$case; \
		diff output$$case expected/expected$$case; \
	done

#clean up the object files and the program
clean:
	rm -f *.o