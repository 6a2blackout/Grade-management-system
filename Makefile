CC = gcc
TARGET = testing
SRC = main.c

create: $(SRC)
	$(CC) -o $(TARGET) $(SRC)

test: create
	./$(TARGET)

clear:
	rm -f $(TARGET)
