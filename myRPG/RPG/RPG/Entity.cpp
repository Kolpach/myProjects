#include "Entity.h"

Entity::Entity(const float& deltatime) : dt(deltatime), physic() {
	posX = 0.f;
	posY = 0.f;
	dirrectionX = 0;
	dirrectionY = 0;
	shape.setSize(sf::Vector2f(50.f, 50.f));
	shape.setFillColor(sf::Color::White);
	movementSpeed = 100.f;
}

Entity::Entity(const float& deltatime, double positionX, double positionY) : dt(deltatime), physic() {
	posX = positionX;
	posY = positionY;
	dirrectionX = 0;
	dirrectionY = 0;
	shape.setSize(sf::Vector2f(50.f, 50.f));
	shape.setFillColor(sf::Color::White);
	movementSpeed = 100.f;
}

Entity::~Entity() {
}

void Entity::addDirrection(float x, float y) {
	dirrectionX += x;
	dirrectionY += y;
}

void Entity::accelerate() {
	physic.setAccelerationByForce(static_cast<double>(dirrectionX) * movementSpeed * dt * 20, static_cast<double>(dirrectionY) * movementSpeed * dt * 20);
	shape.setPosition(posX, posY);
}

void Entity::setPosition(double x, double y) {
	posX = x;
	posY = y;
}

void Entity::update() {
	if (dirrectionX || dirrectionY) {
		accelerate();
		dirrectionX = 0;
		dirrectionY = 0;
	}
	physic.update(this);
}

void Entity::render(sf::RenderTarget* target) {
	target->draw(shape);
}
