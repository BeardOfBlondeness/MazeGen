#include "Global.h"
#include "Game.h"

//Initiates the window and window events
sf::RenderWindow window(sf::VideoMode(900, 900), "Maze for Ioana");
sf::Event event;

/*g
* contains the game loop
*/
int main()
{
srand(time(0));
    Game g;
    srand(time(0));
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        g.run();
        window.display();
    }
    return 0;
}
