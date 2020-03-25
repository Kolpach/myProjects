#include "Physics.h"
#include "Entity.h"
#include <iostream>
#include <cmath>
//Нужно полностью отойти от ускорения и перейти к силам
void Physics::effectFriction() {
	double deltaX = accelerationX != 0 ? -accelerationX / abs(accelerationX) * friction : 0;
	double deltaY = accelerationY != 0 ? -accelerationY / abs(accelerationY) * friction : 0;
	std::cout << deltaX << ' ' << deltaY << std::endl;
	accelerationX += deltaX;
	accelerationY += deltaY;
	if (accelerationX < 0.05 && accelerationX > -0.05) {
		accelerationX = 0;
	}
	if (accelerationY < 0.05 && accelerationY > -0.05) {
		accelerationY = 0;
	}
}

Physics::Physics() {
	affectedToGravitation = false;
	accelerationX = 0.f;
	accelerationY = 0.f;
	friction = 0.5f;
	mass = 1.f;
	speedX = 0.f;
	speedY = 0.f;
}

Physics::Physics(double mas, double fric, bool affectedToGrav) {
	mass = mas;
	friction = fric;
	affectedToGravitation = affectedToGrav;
	accelerationX = 0.f;
	accelerationY = 0.f;
	speedX = 0.f;
	speedY = 0.f;
}

void Physics::move(Entity* object, double X, double Y) {
	object->setPosition(X, Y);
	object->shape.setPosition(X, Y);
}

void Physics::setAccelerationByForce(double forceX, double forceY) {
	accelerationX = forceX / mass;
	accelerationY = forceY / mass;
}

void Physics::setFriction(double f) {
	friction = f;
}

void Physics::setMass(double m) {
	mass = m;
}

void Physics::setSpeed(double x, double y) {
	speedX = x;
	speedY = y;
}

void Physics::update(Entity* object) {
	//addAcceliration(0.f, 9.8 * mass); // gravitation
	effectFriction();
	speedX += accelerationX;
	speedY += accelerationY;
	move(object, speedX, speedY);
}
