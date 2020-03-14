#ifndef STATE_H
#define STATE_H

#include "Entity.h"

class IState
{
protected:
	//variables
	const float& dt;

	sf::RenderWindow* window;
	bool quit;
	std::vector<sf::Texture*> texture;
	const std::queue<int>& supportedKeys;
public:
	IState(sf::RenderWindow* window, const float& delta, const std::queue<int>& Keys);
	virtual ~IState();

	//functions

	//simple getter
	const bool& getQuit() const;

	//just before end
	virtual void endState() = 0;
	//updates key press events
	virtual void updateInput() = 0;
	virtual void update() = 0;//dt = deltatime
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
#endif