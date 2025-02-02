// https://github.com/csammat1/mindsweeper.git

#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"
#include "Board.h"
using namespace std;

int main(){    
    //set up "global" variables
    string state = "MENU";

    Board board;
    board.print_board();
    board.randomize_board();
    cout << endl;
    board.print_board();


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