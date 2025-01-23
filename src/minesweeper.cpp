#include <stdlib.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"
using namespace std;

void menu_loop(string &state){

}

int main(){    
    //set up "global" variables
    string state = "MENU";

    float tiles_width = 10;
    float tiles_height = 10;
    float bomb_ratio = .10;

    while(true){
        if(state == "Menu"){
            menu_loop(state);
        }
    }
}