#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <time.h>
#include "Texte.h"
#include "Interface.h" 
#include "Playable.h"

/*
  this class allows to make an interface basic
*/


using namespace std ; 


Interface::Interface() : window(sf::VideoMode(800, 500), "SFML")/*,tex(new Texte())*/
{
 
}

Interface::~Interface()
{
  delete this ;
}
//init the window
void Interface::affiche(){
  SCREEN_WIDTH =800;
  SCREEN_HEIGHT=500;     
 
  
  window.setPosition(sf::Vector2i(20, 60));
  sf::RectangleShape rectangle(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
  rectangle.setFillColor(sf::Color::White);  
  sf::CircleShape shape(100.f);
    
  cout << this->SCREEN_WIDTH << endl ; 
    
     
  
  play = new Playable(true , &window) ; 
        //classic while for waiting commands
  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
        {
	  if (event.type == sf::Event::Closed)
	    window.close();
                
	  // play->listener() ; 
	  play->listener() ; 
        }
    }
}





int main(){
        
  Interface ii ; 
  ii.affiche() ; 
        
  return 0 ; 
}
