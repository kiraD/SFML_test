g++ -c Texte.cpp Texte.h Grid.cpp Keypush.cpp Character.cpp Playable.cpp Interface.cpp 
g++ Texte.o Grid.o Playable.o Keypush.o Character.o Interface.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
 ./sfml-app &
 rm *.o 
 
