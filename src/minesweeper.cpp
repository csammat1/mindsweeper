#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"
using namespace std;

void randomize_board(int rows, int cols, float bomb_ratio, vector<vector<Cell>>& board){
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

void print_board(int rows, int cols, vector<vector<Cell>>& board){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if(j != cols - 1){
                cout << "[" << board[i][j].get_content() << "] ";
            }
            else{
                cout << "[" << board[i][j].get_content() << "]" << endl;
            }
        }
    }
}

int main(){    
    //set up "global" variables
    string state = "MENU";

    int rows = 10;
    int cols = 10;
    float bomb_ratio = .10;

    vector<vector<Cell>> board(rows, vector<Cell>(cols, 0));

    randomize_board(rows, cols, bomb_ratio, board);

    print_board(rows, cols, board);

    //set up game board for default settings


    //auto menu_loop = [&]{
    //    while(state == "Menu"){
    //
    //    }
    //};

    //while(true){
    //    if(state == "Menu"){
    //        menu_loop();
    //    }
    //}
}