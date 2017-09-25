#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "Spaceship.hpp"
#include "World.hpp"

using namespace std;

World::World()
{
    unitlist = {};
    planet.setRadius(100);
    planet.setOrigin(100, 100);
    planet.setPosition(500, 500);
    planet.setFillColor(sf::Color::Green);
    toShoot = false;
}

World::World(sf::Vector2u windowsize)
{
    unitlist = {};
    planet.setRadius(100);
    planet.setOrigin(100, 100);
    planet.setPosition(windowsize.x/2, windowsize.y/2);
    planet.setFillColor(sf::Color::Green);
    toShoot = false;
}

void World::update(int ticks)
{
    //cout << "World::update() called" << endl;
    for (Spaceship* ship : unitlist)
    {
	//cout << "shipname: " << ship->getName() << endl;
	ship->update(
	    (planet.getPosition()-ship->getPosition())/300.f+
	    ship->updateAccel(),
	    toShoot
	    );
    }
    toShoot = false;
}

void World::display(sf::RenderWindow* window)
{
    window->draw(planet);
    //cout << "World::display() called and unitlist[1]: " << unitlist.front()->getPosition().x  << endl;
    for (Spaceship* ship : unitlist)
    {
	ship->display(window);
    }
}

void World::addUnit(Spaceship* newship)
{
    unitlist.push_back(newship);
}

void World::shoot()
{
    toShoot = true;
}

void World::deleteBullets()
{
    for (Spaceship* ship : unitlist)
    {
	ship->deleteBullets();
    }
}
