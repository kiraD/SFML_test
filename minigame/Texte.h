#ifndef TEXTE_H
#define TEXTE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream> 
#include<string>

class Texte{
        public :
               Texte(int tai) ; 
               void lis(/*std::string txt*/char aaa [100] ) ;
               std::string getText();
               void setText(std::string n) ; 
               void setTaille(int t);
               int getTaille() ; 
        
        private: 
              std::string texte ;
              int taille ;  
};

#endif
