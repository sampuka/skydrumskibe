#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class Bullet
{
public:
    Bullet(sf::Vector2f pos, sf::Vector2f vel);
    sf::CircleShape getShape();
    void update();
    void display(sf::RenderWindow* window);
    
private:
    sf::CircleShape drawshape;
    sf::Vector2f position;
    sf::Vector2f velocity;
    float radius;
};

#endif
