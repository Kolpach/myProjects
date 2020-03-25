#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "includeLibs.h"
#include "Physics.h"

class Entity
{
private:
	double posX;
	double posY;
	float dirrectionX;
	float dirrectionY;
protected:
	Physics physic;
	sf::RectangleShape shape;
	float movementSpeed;
	const float& dt;
public:
	Entity(const float& deltatime);
	Entity(const float& deltatime, double positionX, double positionY);
	virtual ~Entity();

	//Functions
	void addDirrection(float x, float y);
	virtual void accelerate();
	void setPosition(double x, double y);

	virtual void update() ;
	virtual void render(sf::RenderTarget* target);

	friend void Physics::move(Entity* object, double X, double Y);
};


#endif // !ENTITY_H