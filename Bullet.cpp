#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

using namespace std;

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f vel)
{
    position = pos;
    velocity = vel;
    radius = 15;
    drawshape.setFillColor(sf::Color::White);
    drawshape.setPosition(position);
    drawshape.setRadius(radius);
    drawshape.setOrigin(radius, radius);
}

sf::CircleShape Bullet::getShape()
{
    return drawshape;
}

void Bullet::update()
{
    position += velocity;
    drawshape.setPosition(position);
}

void Bullet::display(sf::RenderWindow* window)
{
    window->draw(drawshape);
}
