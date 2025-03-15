GCC = gcc
CFLAGS = -g -Wall -Wshadow
SRCS = 
OBJS = $(SRCS:.c=.o) # OBJS = 


#compile and link the programs

program: $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o program


#implicit rules for object files
.c.o:
	$(GCC) $(CFLAGS) -c $*.c


#test the program using predefined cases
test: program
