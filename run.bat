@echo off
g++ Main.cpp  Game.cpp Sprite.cpp -IC:\SFML-2.4.2\include -LC:\SFML-2.4.2\lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -o run
TIMEOUT /T 3
run
