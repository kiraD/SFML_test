
#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Texte.h"
#include "Playable.h"

class Interface 
{
        public : 
                Interface() ; 
                virtual ~Interface();
                void affiche() ; 
                
                sf::RenderWindow window;
        protected: 
        
        private :
       
                int value ; 
                int SCREEN_WIDTH  ;
                int SCREEN_HEIGHT ; 
                Texte *tex ; 
                Playable *play ; 
                


};

#endif
