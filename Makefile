#Makefile

FLAGS = -pedantic-errors -std=c++11

card.o: card.cpp card.h
	g++ $(FLAGS) -c $<
player.o: player.cpp player.h
	g++ $(FLAGS) -c $<
game.o: game.cpp game.h
	g++ $(FLAGS) -c $<
main.o: main.cpp game.h player.h card.h
	g++ $(FLAGS) -c $<
main: game.o card.o player.o main.o
	g++ $(FLAGS) $^ -o $@
clean:
	rm -f main.o game.o card.o player.o main

.PHONY: clean

