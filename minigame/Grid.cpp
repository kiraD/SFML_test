#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream> 
#include<string>

#include "Grid.h"
#include "Texte.h"

using namespace std ; 

Grid :: Grid(){
//init the grid
  for(int i (0) ; i < 15 ; i++){
    for(int j(0) ; j < 15 ; j++){
      grille[i][j] = 0 ; 
    }
  }
  dh = 15 ;
  dl = 26;
  mapping = new Texte(15);  // Init the container of text
}

void Grid::charger(int mode){
//load a MAP , and load it on a grid
  char map [100] = "txt/map.txt" ; // just a test  for a map one    
  mapping-> lis(map); 
  int i (0) , j(0) ; 
  
  
  for(int k(0) ; k < 15*16  ; k++) {
    if(mapping -> getText()[k] == '\n'){
      cout << "" << endl ; 
      j=0 ;
      i++ ; 
    }else{
      //  cout << mapping->getText()[k] ; 
      grille[i][j] = mapping->getText()[k] ; 
      j++ ;
    }
  } 
  cout << "=====State of the grid=====  " << endl ; 
  for(int i(0) ; i< 15 ; i++){
    for(int j(0) ; j< 15 ; j++){
      cout << grille[i][j] ; 
    }
    cout << ""<<endl ;
  } 
}

int Grid::top(int x, int y) {
  return (dh * y + dh * x) + 150;

}

int Grid::left(int x, int y) {
  return (dl * x - dl * y) + 370;
}

int Grid::getDl(){
  return dl ;
}

int Grid::getDh(){
  return dh ; 
}

Texte* Grid::getMapping(){
  return mapping ; 
}
