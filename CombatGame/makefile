CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

fantasyGame: CharNode.o CharQueue.o Barbarian.o BlueMen.o Character.o HarryPotter.o Medusa.o Vampire.o menu.o main.o
	${CXX} ${CXXFLAGS} CharNode.o CharQueue.o Barbarian.o BlueMen.o Character.o HarryPotter.o Medusa.o Vampire.o menu.o main.o -o fantasyGame


Barbarian.o: Barbarian.cpp Barbarian.hpp
	${CXX} ${CXXFLAGS} -c Barbarian.cpp
	
BlueMen.o: BlueMen.cpp BlueMen.hpp
	${CXX} ${CXXFLAGS} -c BlueMen.cpp

Character.o: Character.cpp Character.hpp
	${CXX} ${CXXFLAGS} -c Character.cpp
	
HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	${CXX} ${CXXFLAGS} -c HarryPotter.cpp
	
Medusa.o: Medusa.cpp Medusa.hpp
	${CXX} ${CXXFLAGS} -c Medusa.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	${CXX} ${CXXFLAGS} -c Vampire.cpp

menu.o: menu.cpp menu.hpp
	${CXX} ${CXXFLAGS} -c menu.cpp
	
main.o: main.cpp 
	${CXX} ${CXXFLAGS} -c main.cpp

CharNode.o: CharNode.cpp CharNode.hpp
	${CXX} ${CXXFLAGS} -c CharNode.cpp

CharQueue.o: CharQueue.cpp CharQueue.hpp
	${CXX} ${CXXFLAGS} -c CharQueue.cpp
	
clean:
	rm *.o fantasyGame
