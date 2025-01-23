all: minesweeper

minesweeper: minesweeper.o Cell.o
	g++  minesweeper.o Cell.o

minesweeper.o: minesweeper.cpp Cell.h
	g++ -c minesweeper.cpp

Cell.o: Cell.cpp Cell.h
	g++ -c Cell.cpp

clean:
	rm -f *.o minesweeper