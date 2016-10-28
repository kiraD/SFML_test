g++ -c Texte.cpp Texte.h Interface.cpp
g++ Texte.o Interface.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app 
