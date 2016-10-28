#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <fstream> 
#include<string>

#include "Playable.h" 
#include "Interface.h" 
#include "Texte.h"
#include "Grid.h"
#include "Keypush.h"
#include "Character.h"

using namespace std ; 

//constructor init all datas
Playable::Playable(bool b , sf::RenderWindow * windo ){
  cout << "init du listener" << endl ; 
  bo = b ; 
  windos = windo;
  personnage = new Character(4,4) ; 
  grid = new Grid() ; 
  grid->charger(1) ;
  check = false;  
  //init
  grid->ZOOM = 1 ; 
  grid->posDx = 0 ;
  grid->posDy= 0 ;
  grid->rotate = 0 ;
  TEXTE=false ;
  grid->grille[4][4] = '4' ;
  /* grid->mapping->getText() ;  */
  
  
  char name [100] = "txt/1.txt";  
  tex = new Texte(15) ;
  tex->lis(name) ; 
  cout << tex->getText() << endl ;
  //draw a rectangle
  sf::RectangleShape rectanglr(sf::Vector2f(800, 600));
  rectanglr.setFillColor(sf::Color::White);
  
  //load a texture
  if (!texture[0].loadFromFile("ressource/fond.jpg") )
    {
      // erreur...
    } 
  if(!texture[1].loadFromFile("ressource/image/pavel/sun.png")){
  }
        
  //init a Sprite with a basic size and load a texture but a bit not more
  sprite[0].setTextureRect(sf::IntRect(0, 0, 800, 600));
  sprite[0].setTexture(texture[0]);
  sprite[0].setPosition(sf::Vector2f(0, 0));
        
  
  sprite[1].setTexture(texture[1]);
  sprite[1].setPosition(sf::Vector2f(10, 10));
        
  //add elements to the windos
  windos->clear() ;  
  windos->draw(rectanglr) ;
  windos->draw(sprite[0]); 
  windos->draw(sprite[1]); 
  textee(260,430) ;  
  windos->draw(text);
  windos->display(); 
}


void Playable::fondecran(){
        //draw basic forms
  sf::RectangleShape rectangl(sf::Vector2f(800, 600));
  rectangl.setFillColor(sf::Color(0,0, 0));
  windos->clear() ;  
  windos->draw(rectangl);
  drawfield() ; 

}

void Playable::listener(){
  if(bo){
    //init 
    //mouse listener if we clic right
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
      {
       
	
	char act [100]  = "txt/2.txt" ;
	
	tex->lis(act); 
	/*	sf::RectangleShape rectanglr(sf::Vector2f(800, 600));
		rectanglr.setFillColor(sf::Color::White); */
	
	//printing some elements to the window 
	windos->clear() ;  
	sf::RectangleShape rectangl(sf::Vector2f(800, 600));
	rectangl.setFillColor(sf::Color(0, 0, 0));
	windos->draw(rectangl);
	drawfield() ; 
	drawfield() ; 
	
	windos->display();   
	                      
      }
      
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        TEXTE = true ;
    }
    //check what key we type.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and !check){
      orientation = 4 ;  check = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and !check){
      orientation = 1 ;  check = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and !check){
      orientation = 2 ;  check = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and !check){
      orientation = 3 ; 
      check = true;
    }
    
    
    
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
      grid->ZOOM -= 0.1f ; 
      windos->clear() ;  
      //we get the default view of window
      sf::View view = windos->getDefaultView();
      //we add a degree of zoom
      view.zoom(grid->ZOOM);
      view.rotate(grid->rotate);
      windos->setView(view); 
      //draw some elements back     
      fondecran() ;
      Tfield(); 
      windos->display(); 
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
      sf::View view = windos->getDefaultView();
      windos->clear() ; 
      grid->posDx -= 10 ;
      view.zoom(grid->ZOOM);
      view.rotate(grid->rotate);
                
      view.move(grid->posDx, grid->posDy);    
      windos->setView(view);
      fondecran();
      Tfield();
      windos->display() ; 
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
      sf::View view = windos->getDefaultView();
      windos->clear() ; 
      view.rotate(grid->rotate);
      grid->posDx += 10 ;
      view.zoom(grid->ZOOM);
      view.move(grid->posDx, grid->posDy);    
      windos->setView(view);
      fondecran();
      Tfield();
      windos->display() ; 
    }
       
       
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
      sf::View view = windos->getDefaultView();
      windos->clear() ; 
      grid->posDy -= 10 ;
      view.rotate(grid->rotate);
      view.zoom(grid->ZOOM);
      view.move(grid->posDx, grid->posDy);    
      windos->setView(view);
      fondecran();
      Tfield();
      windos->display() ; 
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
      sf::View view = windos->getDefaultView();
      windos->clear() ; 
               
                
      view.rotate(grid->rotate);
      grid->posDy += 10 ;
      view.zoom(grid->ZOOM);
      view.move(grid->posDx, grid->posDy);    
      windos->setView(view);
                
      fondecran();
      Tfield() ;
      windos->display() ; 
    }
       
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)){
        
      windos->clear() ;  
      sf::View view  = windos->getDefaultView();
      grid->rotate+=10 ;
      view.setRotation(0);

      view.rotate(grid->rotate);
      view.zoom(grid->ZOOM);   
      windos->setView(view);
      fondecran();
      Tfield();
      windos->display(); 
    }
       
       
       
       
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
      grid->ZOOM += 0.1f ; 
               
      windos->clear() ;  
      sf::View view  = windos->getDefaultView();
      view.rotate(grid->rotate);
      view.zoom(grid->ZOOM);
                
              
      windos->setView(view);
                
                
      fondecran();
      Tfield();
      windos->display(); 
       
    }
      
      
      
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && check){
     
      sf::RectangleShape rectangl(sf::Vector2f(800, 600));
      rectangl.setFillColor(sf::Color(0, 0, 0)); 
      key->pushin(orientation , personnage , grid) ;
      windos->clear() ;  
       
      windos->draw(rectangl);
      drawfield() ;
      Tfield();
      windos->display(); 
      check  =false;
    }
      
     
      
  }else{
       
    // ... 
  }
}

void Playable::Tfield(){
        //write some text to a position on the screen
          sf::Text text2;
          text2.setString("Lire le README pour les touches");
          text2.setFont(fonte);
          text2.move(0 , 0 );
          text2.setColor(sf::Color::Red);
          windos->draw(text2) ;
}


void Playable::textee(int pos , int pos2){
//load a FOND and apply basicly.
  if (!fonte.loadFromFile("font/arial.ttf"))
    {
      cout << "Error  there is  !! " ; 
    }
  text.setFont(fonte); 
  text.setString(tex->getText());
  text.setCharacterSize(tex->getTaille()); 
  text.move(pos , pos2 );
      
  text.setColor(sf::Color::Red);        
}

void Playable::drawfield(){

   Tfield();
   //Load ressources 
  if (!texture[2].loadFromFile("ressource/p1.png"))
    {
      // erreur...
    }
  if (!texture[1].loadFromFile("ressource/h1.png"))
    {
      // erreur...
    }
  if (!texture[3].loadFromFile("ressource/image/pavel/sbas.png"))
    {
      // erreur...
    }
        
        
        
        
        
  //setting figure on the screen
  sf::CircleShape shape(50.f);
  shape.setFillColor(sf::Color::Yellow);
  shape.setPosition(170,10) ; 
  windos->draw(shape);
  int incr (2) ; 
  int mem =0 ;
  int mem2 =0 ; 
      
  for (int i (0); i <15 ; i++) {
    for (int j (0); j < 15; j++) {
      if(grid->grille[i][j] == '0' ){
	sprite[incr].setTexture(texture[2]);
	windos->draw(sprite[incr]);
	sprite[incr].setPosition(grid->left(i, j)-20, grid->top(i, j)-40);
      }else if (grid->grille[i][j] == '4'){
	mem = i ;
	mem2 = j ; 
                             
	 
      }else{
        //ste a texture and then print it on a determined position.     
	sprite[incr].setTexture(texture[1]);
	windos->draw(sprite[incr]);
	sprite[incr].setPosition(grid->left(i, j), grid->top(i, j));                      
                                
      }
      incr ++ ; 
    }
  } 
          
  sprite[230].setTexture(texture[3]);
  windos->draw(sprite[230]);
  sprite[230].setPosition(grid->left(mem, mem2), grid->top(mem, mem2)-2);       
}


