CC = gcc

SRC = src
OBJ = obj
BIN = bin
INC = include

CFLAGS = -Wall -Wextra -std=c99 -I$(INC)

SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

TARGET_NAME = $(BIN)/main.exe

$(TARGET_NAME): $(OBJECTS) | $(BIN)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)
	
$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(BIN):
	mkdir -p $(BIN)
	
$(OBJ):
	mkdir -p $(OBJ)
	
.PHONY: run clean

run: $(TARGET_NAME)
	./$(TARGET_NAME)
	
clean:
	rm -rf $(BIN) $(OBJ)