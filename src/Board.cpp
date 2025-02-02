#include <stdlib.h>
#include <random>
#include <algorithm>
#include "Board.h"
#include "Cell.h"
#include <iostream>
using namespace std;


Board::Board(){
    rows = 10;
    cols = 10;
    bomb_ratio = .10;
    board.resize(rows, std::vector<Cell>(cols, Cell()));
    randomize_board();
}
void Board::resize_board(int new_rows, int new_cols){
    board.resize(new_rows);

    // Resize each inner vector to the new number of columns
    for (int i = 0; i < new_rows; ++i) {
        board[i].resize(new_cols);
    }
    reset_board();
    randomize_board();
}
void Board::change_bomb_ratio(int new_ratio){
    bomb_ratio = new_ratio;
    randomize_board();
}
void Board::reset_board(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            board[i][j].reset();
        }
    }
}
void Board::randomize_board(){
    reset_board();
    int bombs_to_make = rows * cols * bomb_ratio;
    vector<pair<int, int>> pairs;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            pairs.push_back({i, j});
        }
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(pairs.begin(), pairs.end(), g);

    for(int i = 0; i < bombs_to_make; i++){
        board[pairs[i].first][pairs[i].second].set_bomb();
        for(int j = pairs[i].first - 1; j <= pairs[i].first + 1; j++){
            for(int k = pairs[i].second - 1; k <= pairs[i].second + 1; k++){
                if(0 <= j && j <= rows - 1 && 0 <= k && k <= cols - 1){
                    board[j][k].inc_content();
                }
            }
        }
    }
}
void Board::print_board(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if(j != cols - 1){
                if(board[i][j].get_content() == 9){
                    cout << "[" << "B" << "] ";
                }
                else{
                    cout << "[" << board[i][j].get_content() << "] ";
                }
            }
            else{
                if(board[i][j].get_content() == 9){
                    cout << "[" << "B" << "] " << endl;
                }
                else{
                    cout << "[" << board[i][j].get_content() << "] " << endl;
                }
            }
        }
    }
}