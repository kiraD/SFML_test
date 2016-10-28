#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream> 
#include<string>
#include "Texte.h"


class Grid {

        public: 
                Grid() ; 
                void charger(int mode) ; 
                Texte * getMapping() ; 
                int getDh() ;
                int getDl() ;
                int top(int x , int y) ; 
                int left(int x , int y) ; 
                Texte *mapping ;
                char grille [15][15] ; 
                float ZOOM ; 
                int posDx ; 
	        int posDy ;
	        int rotate ;

        protected : 
        
        private :
               
                int dh ;
	        int dl ;
	      
} ; 


#endif
