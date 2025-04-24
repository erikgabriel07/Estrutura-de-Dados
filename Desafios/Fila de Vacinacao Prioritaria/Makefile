# NOME DO COMPILADOR
CC = gcc

# DIRETÓRIOS DOS ARQUIVOS E OBJETOS
SRC = src
OBJ = obj
BIN = bin
INC = include

# FLAGS PARA O GCC
CFLAGS = -Wall -Wextra -std=c99 -I$(INC)

# NOME DO ARQUIVO EXECUTÁVEL
TARGET_NAME = $(BIN)/main.exe

# ARQUIVOS .c E OBJETOS .o
SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

# REGRA PRINCIPAL PARA GERAR O EXECUTÁVEL
$(TARGET_NAME): $(OBJECTS) | $(BIN)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)
	
# REGRA PARA GERAR OS OBJETOS
$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

# CRIANDO DIRETÓRIO obj	
$(OBJ):
	mkdir -p $(OBJ)
	
# CRIANDO DIRETÓRIO bin
$(BIN):
	mkdir -p $(BIN)

# REGRAS PARA LIMPAR E EXECUTAR	
.PHONY: clean run

clean:
	rm -rf $(TARGET_NAME) $(OBJ)/*.o

run: $(TARGET_NAME)
	./$(TARGET_NAME)
