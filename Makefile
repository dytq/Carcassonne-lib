EXEC=out

compil:
	g++ -c *.cpp main.cpp
	g++ -g *.cpp -o ${EXEC}
clean:
	rm *.o
	rm ${EXEC}
