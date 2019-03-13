#pragma once
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

#define SFML_STATIC

using namespace std;

extern sf::RenderWindow window;
extern sf::Event event;

struct Pointa {
  int x;
  int y;
};
