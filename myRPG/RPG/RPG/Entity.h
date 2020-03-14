#ifndef ENTITY_H
#define ENTITY_H

#include "includeLibs.h"

class Entity
{
private:
	float dirrectionX;
	float dirrectionY;
protected:
	sf::RectangleShape shape;
	float movementSpeed;
	const float& dt;
public:
	Entity(const float& deltatime);
	virtual ~Entity();

	//Functions
	void addDirrection(float x, float y);
	virtual void move();

	virtual void update() ;
	virtual void render(sf::RenderTarget* target);
};


#endif // !ENTITY_H