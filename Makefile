# --- Configurações do Compilador ---
# --- Configurações do Compilador ---
CXX      := g++

# 1. Encontra TODAS as pastas dentro de 'include' (include/AI, include/Entities, etc)
INCLUDE_DIRS := $(shell find include -type d)

# 2. Adiciona o prefixo "-I" na frente de cada pasta encontrada
# Resultado: -Iinclude -Iinclude/AI -Iinclude/Entities ...
INCLUDES     := $(addprefix -I,$(INCLUDE_DIRS))

# 3. Adiciona isso nas flags
CXXFLAGS := -std=c++17 -Wall -Wextra -O3 $(INCLUDES)
LDFLAGS  := -lsfml-graphics -lsfml-window -lsfml-system

# --- Pastas ---
SRC_DIR   := src
BUILD_DIR := build
TARGET    := life_synm

# --- Busca Automática de Arquivos ---
# Encontra todos os .cpp dentro de src/ (recursivamente)
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')

# Cria a lista de objetos (.o) baseada nos nomes dos .cpp
# Exemplo: src/Main.cpp vira build/Main.o
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# --- Regras de Build ---

# Regra padrão (o que roda quando você digita apenas 'make')
all: $(TARGET)

# Linkagem final (Junta todos os .o para criar o executável)
$(TARGET): $(OBJS)
	@echo "Linking..."
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
	@echo "Build completo: ./$(TARGET)"

# Compilação (Transforma cada .cpp em .o)
# O comando 'mkdir -p' garante que a pasta build exista
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Comandos Úteis ---

# Limpa tudo
clean:
	@echo "Limpando..."
	rm -rf $(BUILD_DIR) $(TARGET)

# Compila e roda
run: all
	@echo "Rodando simulação..."
	./$(TARGET)

.PHONY: all clean run