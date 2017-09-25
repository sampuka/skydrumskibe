#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Spaceship.hpp"

using namespace std;

class World
{
public:
    World();
    World(sf::Vector2u windowsize);
    void update(int ticks);
    void display(sf::RenderWindow* window);
    void addUnit(Spaceship* newship);
    void shoot();
    void deleteBullets();
    
private:
    list<Spaceship*> unitlist;
    sf::CircleShape planet;
    bool toShoot;
};
#endif
