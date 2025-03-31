CC = gcc
TARGET = testing
SRC = main.c

.PHONY: create test clear

create: $(SRC)
	$(CC) -o $(TARGET) $(SRC)

test: create
	./$(TARGET)

clear:
	rm -f $(TARGET)
