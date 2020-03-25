#pragma once
#ifndef PHYSICS_H
#define PHYSICS_H

class Entity;
class Physics {
private:
	double accelerationX;
	double accelerationY;
	double friction;
	double mass;
	double speedX;
	double speedY;
	bool affectedToGravitation;
	void effectFriction();
public:
	Physics();
	Physics(double mas, double fric, bool affectedToGrav);
	void move(Entity* object, double X, double Y);// maybe private???
	void setAccelerationByForce(double forceX, double forceY);
	void setFriction(double f);
	void setMass(double m);
	void setSpeed(double x, double y);
	void update(Entity* object);
	~Physics() = default;
};

#endif // !PHYSICS_H
