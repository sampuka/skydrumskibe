#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <SFML/Graphics.hpp>
#include <string>
#include <list>
#include "Bullet.hpp"

using namespace std;

enum shipType
{
    P1,
    P2,
    NoPlayer
};

class Spaceship
{
public:
    Spaceship(shipType type);
    sf::Vector2f getPosition();
    sf::Vector2<float> getVelocity();
    void update(sf::Vector2<float> acceleration, bool toShoot);
    void display(sf::RenderWindow *window);
    string getName();
    sf::Vector2f updateAccel();
    void deleteBullets();

private:
    sf::Vector2<float> position;
    sf::Vector2<float> velocity;
    float radius;
    sf::CircleShape drawshape;
    sf::Color shapecolor;
    string name;
    int controlType;
    void newBullet();
    list<Bullet*> bulletlist;    
};
#endif
