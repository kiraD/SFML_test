#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <fstream> 
#include<string>

#include "Character.h"
#include "Grid.h"

using namespace std ;


Character:: Character (int pos , int pos2){
  xx = pos ;
  yy = pos2 ; 
}

//move the character and check if the character can move or not (tiles)        
void Character::move(int orientation , int sens,Grid * gg){
  if(sens == 4 || sens == 1 ){
    if(xx+orientation >12 || xx+orientation <1 || gg->grille[yy][xx+orientation] == '0'){
                        
    }else  xx += orientation ; 
  }
              
  if(sens == 2 || sens == 3){
    if(yy+orientation >14       || yy+orientation <1 || gg->grille[yy+orientation][xx] == '0'){
                        
    }else  yy += orientation ; 
          
               
                
  }
       //clear data and print it again
  for(int i(0) ; i < 15 ; i++){
    for(int j(0) ; j < 15 ; j++){
      if(gg->grille[i][j] == '4'){
	gg->grille[i][j] = '1' ;
      }
    }       
  }
       
  gg->grille[yy][xx] = '4' ;
  for(int i(0) ; i < 15 ; i++){
    for(int j(0) ; j < 15 ; j++){
      cout << gg->grille[i][j] ;
    }       
    cout <<""<<endl ;
  }
        
       
}


int Character::getXx(){
  return xx ; 
}

int Character::getYy() {
  return yy ;
}
