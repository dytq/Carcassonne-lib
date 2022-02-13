SRC=
BUILD=

#COMPILATOR=clang++
COMPILATOR=g++

CFLAGS=-Wall -g
EXEC=app

FILE=$(wildcard $(SRC)*.cpp)                  # recupère tous les .cpp
OBJ=$(patsubst %.cpp, %.o , $(FILE))          # on remplace .cpp en .o

all:compile

### run ###
run:
	./app

### compile le programme ###
compile: $(OBJ)  
	$(COMPILATOR) $(CFLAGS) -o $(EXEC) $(OBJ) 

%.o: %.cpp
	$(COMPILATOR) $(CFLAGS) -o $@ -c $< 

### supprime les fichers objets ###
clean:
	rm *.o
	rm ${EXEC}

### vérification de fuites de mémoire ###
memcheck: 
	valgrind ./$(SRC)$(EXEC)

### archive ###
archive : clean
	cd ../..
	tar -czvf CarcassonneIA.tar.gz CarcassonneIA
