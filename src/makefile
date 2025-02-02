all: minesweeper

minesweeper: minesweeper.o Cell.o Board.o
	g++ minesweeper.o Cell.o Board.o -o minesweeper

minesweeper.o: minesweeper.cpp Cell.h Board.h
	g++ -c minesweeper.cpp

Cell.o: Cell.cpp Cell.h
	g++ -c Cell.cpp

Board.o: Board.cpp Board.h Cell.h
	g++ -c Board.cpp

clean:
	rm -f *.o minesweeper