#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include "Cell.h"
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class Board{
    public:
        Board();
        void resize_board(int new_rows, int new_cols);
        void change_bomb_ratio(int new_ratio);
        void reset_board();
        void randomize_board();
        void print_board();
    private:

    int rows;
    int cols;
    float bomb_ratio;
    vector<vector<Cell>> board;
};



#endif