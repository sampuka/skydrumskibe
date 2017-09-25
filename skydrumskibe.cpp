#include <iostream>
#include "World.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes().at(0), "skydrumskibe", sf::Style::Fullscreen);
    sf::Vector2u windowsize = window.getSize();
    cout << "windowsize: " << windowsize.x << "x" << windowsize.y << endl; 

    //Deletable
    //sf::CircleShape shape(100.f);
    //shape.setOrigin(100,100);
    //shape.setPosition(windowsize.x, windowsize.y);
    //shape.setFillColor(sf::Color::Green);
    
    World mainworld(windowsize);
    Spaceship firstship(P1);
    Spaceship secondship(P2);
    mainworld.addUnit(&firstship);
    mainworld.addUnit(&secondship);

    //Time between frames
    sf::Time delay = sf::milliseconds(30);

    while (window.isOpen())
    {
        sf::Event event;
	while (window.pollEvent(event))
	{
	    switch(event.type)
	    {
		
	    case sf::Event::Closed:
		window.close();
		break;
		
	    case sf::Event::KeyPressed:
		switch(event.key.code)
		{
		case sf::Keyboard::Escape:
		    window.close();
		    break;

		case sf::Keyboard::Space:
		    mainworld.shoot();
		    cout << "Space pressed" << endl;
		    break;

		case sf::Keyboard::N:
		    mainworld.deleteBullets();
		    cout << "N pressed" << endl;
		    break;

		default:
		    break;
		}
		break;

	    default:
		break;
	    }
	    
	    //if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	    //window.close();
	}

	mainworld.update(1);
	window.clear();
	//window.draw(shape);
	mainworld.display(&window);
	window.display();
	sf::sleep(delay);
    }
    
    return 0;
}
