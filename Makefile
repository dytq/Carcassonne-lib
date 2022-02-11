### run ###
run: compile
	./main


### compilation ###
compile: main.o
	g++ -Wall -g application/sources/main.o -o application/target/main


### compilation en fichiers objet ###
main.o: main.cpp
	g++ -Wall -g application/sources/main.cpp -c


### vérification de fuites de mémoire ###
memcheck: compile
	valgrind ./application/target/main


### clean ###
clean:
	rm -f application/sources/*.o
	rm -f application/target/main
	clear


### archive ###
archive : clean
	cd ..
	tar -czvf CarcassonneIA.tar.gz CarcassonneIA