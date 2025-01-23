#ifndef Cell_H
#define Cell_H

#include <stdlib.h>
#include <SFML/Graphics.hpp>

class Cell{
    public:
        Cell();
        Cell(int con);
        int get_content();
        bool get_revealed();
        void inc_content();
        void reveal();
    private:

    int content;
    bool revealed;
    const sf::Texture* texture; // Pointer to texture
};



#endif