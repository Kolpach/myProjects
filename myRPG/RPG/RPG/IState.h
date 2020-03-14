#ifndef STATE_H
#define STATE_H

#include "Entity.h"
#include "setDirCommand.h"

class IState
{
protected:
	//variables
	const float& dt;

	sf::RenderWindow* window;
	bool quit;
	std::vector<sf::Texture*> texture;
	std::map<sf::Keyboard::Key, ICommand* > allowedKeys;

public:
	IState(sf::RenderWindow* window, const float& delta);
	virtual ~IState();

	//functions

	virtual void initInput(const std::vector<int>& supportedKeys) {};
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