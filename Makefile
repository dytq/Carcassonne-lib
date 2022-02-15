### Répertoires ###
SRC_DIR=src
TRG_DIR=target

EXE=$(TRG_DIR)/Carcassonne_lib
SRC=$(wildcard $(SRC_DIR)/*.cpp)
OBJ=$(SRC:$(SRC_DIR)/%.cpp=$(TRG_DIR)/%.o)

### Compilateur ###
CXX=g++

### Flags ###
CXXFLAGS := -Iinclude -MMD -MP
CFLAGS   := -Wall
LDFLAGS  := -Llib
LDLIBS   := -lm

### all ###
.PHONY: all clean
all: $(EXE)

$(EXE): $(OBJ) | $(TRG_DIR)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(TRG_DIR)/%.o: $(SRC_DIR)/%.cpp | $(TRG_DIR)
	$(CXX) $(CXXFLAGS) $(CFLAGS) -c $< -o $@

$(TRG_DIR):
	mkdir -p $@

### Supprime les fichiers temporaires ###
clean:
	@$(RM) -rv $(TRG_DIR)
	clear

-include $(OBJ:.o=.d)

### Vérification de fuites de mémoire ###
memcheck: 
	valgrind ./$(SRC)$(EXEC)

### Archive ###
archive: clean
	cd ../..
	tar -czvf Carcassonne-lib.tar.gz Carcassonne-lib
