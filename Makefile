# Nome do compilador
CXX = g++

# Diretórios
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj

# Flags do compilador
CXXFLAGS = -std=c++11 -Wall -Wextra -I$(INCLUDE_DIR)

# Lista de arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.cpp) main.cpp

# Lista de arquivos objeto
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Nome do executáveles

TARGET = main

# Regra padrão para compilar tudo
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Regra para compilar os arquivos objeto
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpa os arquivos objeto e o executável
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Indica que all e clean não são arquivos reais
.PHONY: all clean
