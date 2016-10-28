#ifndef KEYPUSH_H
#define KEYPUSH_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream> 
#include <SFML/System.hpp>
#include<string>

#include "Character.h"
#include "Grid.h"



/*
        Gestion of keyboard
*/

class Keypush {
        public : 
                Keypush() ; 
                void pushin ( int c , Character *c2,Grid *gg) ; //check the good pus

        private : 
                
                
} ;   



#endif
