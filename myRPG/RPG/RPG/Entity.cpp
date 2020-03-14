#include "Entity.h"

Entity::Entity(const float& deltatime) : dirrectionX(0), dirrectionY(0),  dt(deltatime) {
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

void Entity::move() {
	shape.move(dirrectionX * movementSpeed * dt, dirrectionY * movementSpeed * dt);
}

void Entity::update() {
	if (dirrectionX || dirrectionY) {
		float sqrtOfLength = sqrt( dirrectionX * dirrectionX + dirrectionY * dirrectionY);
		dirrectionX = dirrectionX / sqrtOfLength;
		dirrectionY = dirrectionY / sqrtOfLength;
		move();
		dirrectionX = 0;
		dirrectionY = 0;
	}
}

void Entity::render(sf::RenderTarget* target) {
	target->draw(shape);
}
