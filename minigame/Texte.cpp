#include <iostream>
#include <fstream>
#include <string>
#include "Texte.h"


using namespace std ;



Texte::Texte(int tai){
  texte = "init" ; 
  cout << "Voici un init de constructeur\n\n\n" << endl;
  taille = tai;  
}

//read some text 
void Texte::lis(char aaa[100]){
  string tmp = "" ; 
  ifstream fichier(aaa);
  if(fichier)
    {
      string ligne; 
      while(getline(fichier, ligne)) 	  
	{
	  // cout << ligne << endl;
	  tmp += ligne ;
	  tmp += "\n" ; 
	}
    }
  else
    {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture."<< endl;
    }
  texte = tmp ;   
        
}



std::string Texte::getText() {
  return texte ; 
}

void Texte :: setText(std::string n) {
  texte = n ; 
}

void Texte:: setTaille(int n){
  taille=n ; 
}

int Texte :: getTaille(){
  return taille ; 
}

