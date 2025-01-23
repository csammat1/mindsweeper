#include <stdlib.h>
#include "Cell.h"
using namespace std;

Cell::Cell(){
    content = 0;
    revealed = false;
}

Cell::Cell(int con){
    content = con;
    revealed = false;
}

int Cell::get_content(){
    return content;
}

bool Cell::get_revealed(){
    return revealed;
}

void Cell::inc_content(){
    content++;
}

void Cell::reveal(){
    revealed = true;
}
