BUILD=build
SRC=src
EXEC=app.out

CFLAGS=

COMPILE_OBJ=g++ $(CFLAGS) -o $@ -c $^

ALL:compile

### run ###
run: compile
	./$(EXEC)

### compilation ###
compile: main.o Plateau.o Joueur.o Bordure.o Carte.o
	g++ main.o Plateau.o Joueur.o Bordure.o Carte.o -o app.out	
### compilation en fichiers objet ###
main.o: main.cpp
	g++ -o main.o -c main.cpp

Plateau.o: Plateau.cpp Plateau.h
	$(COMPILE_OBJ)

Joueur.o: Joueur.cpp Joueur.h	
	$(COMPILE_OBJ)

Carte.o: Carte.cpp Carte.h
	$(COMPILE_OBJ)

Element.o: Element.cpp Element.h
	$(COMPILE_OBJ)

Meeple.o: Meeple.cpp Meeple.h
	$(COMPILE_OBJ)

Noeud.o: Noeud.cpp Noeud.h
	$(COMPILE_OBJ)

Bordure.o: Bordure.cpp Bordure.h
	$(COMPILE_OBJ)


### vérification de fuites de mémoire ###
memcheck: compile
	valgrind ./application/target/main


### clean ###
clean:
	rm *.o
	rm app.out

### archive ###
archive : clean
	cd ..
	tar -czvf CarcassonneIA.tar.gz CarcassonneIA
