# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -O0 -pedantic -I$(INCLUDE_DIR)

# Diretórios
SRC_DIR = src_cpp
INCLUDE_DIR = include_hpp
OBJ_DIR = obj

# Arquivos fonte e objeto
EXEC = Implementacao_e_Analise_de_Arvores_Balanceadas.exe
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: $(EXEC)

# Compilação do executável
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Criação do diretório obj, se não existir
$(OBJ_DIR):
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
# para Linux: mkdir -p $(OBJ_DIR)

# Compilação de cada .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean: # Para o Linux
	@echo "Limpando arquivos objeto e executavel..."
	@rm -f $(OBJ_DIR)/*.o $(EXEC)

clean-cmd: # Para o Prompt de Comando (no Windows)
	@echo "Limpando arquivos objeto e executavel..."
	@if exist $(OBJ_DIR)\*.o del /Q $(OBJ_DIR)\*.o
	@if exist $(EXEC) del /Q $(EXEC)

clean-pwsh: # Para o PowerShell (no Windows)
	@echo "Limpando arquivos objeto e executavel..."
	@if (Test-Path "$(OBJ_DIR)/*.o") { Remove-Item "$(OBJ_DIR)/*.o" -Force }
	@if (Test-Path "$(EXEC)") { Remove-Item "$(EXEC)" -Force }

# .PHONY declara que um alvo não é um arquivo real — é apenas um nome de comando.
.PHONY: all clean clean-cmd clean-pwsh