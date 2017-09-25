#include <SFML/Graphics.hpp>
#include <string>
#include "Spaceship.hpp"
#include <iostream>
#include <list>
#include "Bullet.hpp"

using namespace std;

sf::Keyboard::Key controlKeys[3][4] =
{
    {sf::Keyboard::Unknown, sf::Keyboard::Unknown, sf::Keyboard::Unknown, sf::Keyboard::Unknown},
    {sf::Keyboard::Up, sf::Keyboard::Left, sf::Keyboard::Down, sf::Keyboard::Right},
    {sf::Keyboard::W, sf::Keyboard::A, sf::Keyboard::S, sf::Keyboard::D}
};

sf::Keyboard::Key shootKey = sf::Keyboard::Space;

/*
Spaceship::Spaceship()
{
    cout << "standard ship constructer" << endl;
    position = sf::Vector2<float>(350, 350);
    velocity = sf::Vector2<float>(15,-15);
    name = "Default name";
    radius = 30;
    drawshape = sf::CircleShape(radius);
    shapecolor = sf::Color::Red;
    drawshape.setFillColor(shapecolor);
    drawshape.setPosition(100,100);
    drawshape.setOrigin(30,30);
    controlType = 0;
}
*/

Spaceship::Spaceship(shipType type)
{
    bulletlist = {};
    switch (type)
    {
    case P1:
	cout << "ship A-type" << endl;
	position = sf::Vector2<float>(350, 350);
	velocity = sf::Vector2<float>(15,-15);
	name = "A";
	radius = 30;
	drawshape = sf::CircleShape(radius);
	shapecolor = sf::Color::Red;
	drawshape.setFillColor(shapecolor);
	drawshape.setPosition(position);
	drawshape.setOrigin(30,30);
	controlType = 1;

	break;
    
    case P2:
	cout << "ship B-type" << endl;
	position = sf::Vector2<float>(700, 300);
	velocity = sf::Vector2<float>(-20,-5);
	name = "B";
	radius = 30;
	drawshape = sf::CircleShape(radius);
	shapecolor = sf::Color::Blue;
	drawshape.setFillColor(shapecolor);
	drawshape.setPosition(position);
	drawshape.setOrigin(30,30);
	controlType = 2;

	break;
	
    case NoPlayer:
	cout << "NoPlayer-type ship" << endl;
	position = sf::Vector2<float>(350, 350);
	velocity = sf::Vector2<float>(15,-15);
	name = "Default name";
	radius = 30;
	drawshape = sf::CircleShape(radius);
	shapecolor = sf::Color::Red;
	drawshape.setFillColor(shapecolor);
	drawshape.setPosition(position);
	drawshape.setOrigin(30,30);
	controlType = 0;
	
	break;
	
    default:
	cout << "wrong ship type I think" << endl;
	position = sf::Vector2<float>(350, 350);
	velocity = sf::Vector2<float>(15,-15);
	name = "Default name";
	radius = 30;
	drawshape = sf::CircleShape(radius);
	shapecolor = sf::Color::Red;
	drawshape.setFillColor(shapecolor);
	drawshape.setPosition(position);
	drawshape.setOrigin(30,30);
	controlType = 0;

	break;
    }
}

sf::Vector2f Spaceship::getPosition()
{
    return position;
}

sf::Vector2<float> Spaceship::getVelocity()
{
    return velocity;
}

void Spaceship::update(sf::Vector2<float> acceleration, bool toShoot)
{
    velocity += acceleration;
    position += velocity;
    drawshape.setPosition(position);
    //cout << "shapeposition: " << position.x << endl;

    if (sf::Keyboard::isKeyPressed(shootKey))
	drawshape.setFillColor(sf::Color::White);
    else
	drawshape.setFillColor(shapecolor);

    if (toShoot)
	newBullet();

    for (Bullet* bullet : bulletlist)
    {
	bullet->update();
    }
    
}

void Spaceship::display(sf::RenderWindow *window)
{
    window->draw(drawshape);
    //cout << name << "'s display called" << endl;

    for(Bullet* bullet : bulletlist)
    {
	bullet->display(window);
    }
}

string Spaceship::getName()
{
    return name;
}

sf::Vector2f Spaceship::updateAccel()
{
    sf::Vector2f tempVec = sf::Vector2f(0,0);
    if (sf::Keyboard::isKeyPressed(controlKeys[controlType][0]))
	tempVec += sf::Vector2f(0, -1);
    if (sf::Keyboard::isKeyPressed(controlKeys[controlType][1]))
	tempVec += sf::Vector2f(-1, 0);
    if (sf::Keyboard::isKeyPressed(controlKeys[controlType][2]))
	tempVec += sf::Vector2f(0, 1);
    if (sf::Keyboard::isKeyPressed(controlKeys[controlType][3]))
	tempVec += sf::Vector2f(1, 0);
    return tempVec;
	
}

void Spaceship::deleteBullets()
{
    for (Bullet* bullet : bulletlist)
    {
	delete bullet;
    }
    bulletlist = {};
}
    
void Spaceship::newBullet()
{
    //for (int i = 0; i < 1500; i++)
    bulletlist.push_back(new Bullet(position, velocity));
}
