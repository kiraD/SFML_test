#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <fstream> 
#include<string>


#include "Grid.h"

class Character{
        public :
                Character(int pos , int pos2) ; 
                void move(int orientation,int sens,Grid *gg) ; //move the character to orientation time 
                int getXx() ; 
                int getYy() ; 
        private:
                int xx ; 
                int yy ; 
};



#endif
