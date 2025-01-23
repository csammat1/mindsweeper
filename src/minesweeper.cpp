#include <stdlib.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"
using namespace std;

void menu_loop(string &state){
    
}

int main(){
    string state = "MENU";

    while(true){
        if(state == "Menu"){
            menu_loop(state);
        }
    }
}