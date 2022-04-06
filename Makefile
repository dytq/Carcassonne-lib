### Chemins ###
SRC_DIR = src
TRG_DIR = target
TRG = $(TRG_DIR)/main

### Fichiers ###
SRC = $(wildcard $(SRC_DIR)/*.cpp)

### Compilateur ###
CXX = g++

### Flags ###
CXXFLAGS = -O3 -Wall -g

### run ###
run: dir compile
	./$(TRG)

dir:
	mkdir -p $(TRG_DIR)

compile:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TRG)

### Suppression du répertoire cible ###
clean:
	rm -rf $(TRG_DIR)
	rm -f *.o
	clear

### Vérification de fuites de mémoire ###
memcheck: compile
	valgrind ./$(EXE)

### Deboguage GDB ###
gdb: compile
	gdb ${EXE}

### Archivage ###
archive: clean
	cd ../..
	tar -czvf Carcassonne-lib.tar.gz Carcassonne-lib