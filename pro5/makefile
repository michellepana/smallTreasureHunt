CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

treasureHunt: Board.o Bomb.o Elixir.o Player.o Regular.o Space.o Treasure.o Menu.o main.o
	${CXX} ${CXXFLAGS} Board.o Bomb.o Elixir.o Player.o Regular.o Space.o Treasure.o Menu.o main.o -o treasureHunt


Board.o: Board.cpp Board.hpp
	${CXX} ${CXXFLAGS} -c Board.cpp
	
Bomb.o: Bomb.cpp Bomb.hpp
	${CXX} ${CXXFLAGS} -c Bomb.cpp

Elixir.o: Elixir.cpp Elixir.hpp
	${CXX} ${CXXFLAGS} -c Elixir.cpp
	
Player.o: Player.cpp Player.hpp
	${CXX} ${CXXFLAGS} -c Player.cpp
	
Regular.o: Regular.cpp Regular.hpp
	${CXX} ${CXXFLAGS} -c Regular.cpp

Space.o: Space.cpp Space.hpp
	${CXX} ${CXXFLAGS} -c Space.cpp

Menu.o: Menu.cpp Menu.hpp
	${CXX} ${CXXFLAGS} -c Menu.cpp
	
main.o: main.cpp 
	${CXX} ${CXXFLAGS} -c main.cpp

Treasure.o: Treasure.cpp Treasure.hpp
	${CXX} ${CXXFLAGS} -c Treasure.cpp
	
clean:
	rm *.o treasureHunt
