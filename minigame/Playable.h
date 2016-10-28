#ifndef PLAYABLE_H
#define PLAYABLE_H


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <fstream> 
#include<string>

#include "Texte.h"
#include "Grid.h"


#include "Keypush.h"
#include "Character.h"


class Playable{

        public :
                Playable(bool b , sf::RenderWindow *windo ) ; 
                void listener() ; 
                void textee(int pos , int pos2);
                sf::RenderWindow *windos ; 
                void drawfield() ; //draw the field on the screen
                void fondecran() ;//draw the most basic grid
                void Tfield() ;//draw basic datas
                bool TEXTE ;//check if we write text
               
        private : 
                bool bo ; 
                
                sf::Texture texture [300];
                sf::Sprite sprite[250];
                
                Keypush *key ;  //gestion of movement
                Character *personnage ; 
                
                sf::Sprite character[230]; //character
                Texte *tex ; //draw some texts
                Grid * grid ; //grid
                sf::Font fonte;//font
                sf::Text text;
                int orientation ; //number of move
                bool check ;//check if we type the good key
               
                

} ; 


#endif
