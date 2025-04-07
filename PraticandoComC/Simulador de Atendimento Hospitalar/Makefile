# COMPILADOR
CC = gcc

# DIRETÓRIOS
SRC = src
OBJ = obj
BIN = bin
INC = include

# ARQUIVOS E OBJETOS
SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

# FLAG
CFLAG = -Wall -Wextra -std=c99 -I$(INC)

# NOME DO EXECUTÁVEL
TARGET_NAME = $(BIN)/main.exe

# REGRA PRINCIPAL
$(TARGET_NAME): $(OBJECTS) | $(BIN)
	$(CC) $(CFLAG) -o $@ $(OBJECTS)

# REGRA PARA GERAR OBJETOS
$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAG) -o $@ -c $<
	
# REGRA PARA GERAR DIRETÓRIOS
$(OBJ):
	mkdir -p $(OBJ)
	
$(BIN):
	mkdir -p $(BIN)
	
# LIMPEZA DE ARQUIVOS
.PHONY: clean run

clean:
	rm -rf $(TARGET_NAME) $(OBJ)/*.o
	
run: $(TARGET_NAME)
	./$(TARGET_NAME)