antGame: main.o menu.o ant.o Board.o 
	g++ main.o menu.o ant.o Board.o -o antGame

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp
	
ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp
	
Board.o: Board.cpp Board.hpp
	g++ -c Board.cpp
	
clean:
	rm *.o antGame