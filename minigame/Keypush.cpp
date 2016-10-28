#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <fstream> 
#include<string>

#include "Keypush.h"
#include "Character.h"
#include "Grid.h"



using namespace std ;

Keypush::Keypush(){
  cout << "init constructor for the listener started ...." << endl ; 

}
//move the character on the grid
void Keypush::pushin( int c ,Character *c2, Grid* gg){
      
  cout << c << endl ;
  if(c == 4)
    c2->move(-1,c ,gg); 
  if(c == 1)
    c2->move(1,c,gg);
  if(c == 2)
    c2->move(-1,c,gg); 
  if(c == 3)
    c2->move(1,c,gg);
        
}
