# COMPILADOR
CC = gcc

# DIRETÓRIOS
SRC = src
OBJ = obj
BIN = bin
INC = include

# FLAGS
CFLAGS = -Wall -Wextra -std=c99 -I$(INC)

# ARQUIVOS E OBJETOS
SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

# NOME DO EXECUTÁVEL
TARGET_NAME = $(BIN)/main.exe

# REGRA PRINCIPAL
$(TARGET_NAME): $(OBJECTS) | $(BIN)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

# REGRAS PARA GERAR EXECUTÁVEL
$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

# CRIANDO DIRETORIO obj
$(OBJ):
	mkdir -p $(OBJ)

# CRIANDO DIRETORIO bin
$(BIN):
	mkdir -p $(BIN)

# LIMPANDO EXECUTAL E OBJETOS	
.PHONY: clean run

clean:
	rm -rf $(OBJ)/*.o $(TARGET_NAME)

# RODA O EXECUTÁVEL
run: $(TARGET_NAME)
	./$(TARGET_NAME)
