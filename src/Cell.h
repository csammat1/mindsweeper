#indef Cell_H
#define Cell_H

class Cell{
    public:
        int get_content();
        bool get_revealed();
        void set_content(int i);
        void reveal();
    private:

    int content;
    bool revealed;
    const sf::Texture* texture; // Pointer to texture
};



#endif