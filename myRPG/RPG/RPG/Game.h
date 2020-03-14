#ifndef GAME_H
#define GAME_H

#include "GameState.h"

class Game
{
private:
	//variables

	sf::RenderWindow* window;
	sf::Event windowEvent;
	float dt;
	sf::Clock dtClock;
	std::stack<IState*> states;

	std::vector<int> supportedKeys;

	//initialization functions

	void initWindow();
	void initStates();
	void initKeys();
public:
	Game();
	virtual ~Game();

	//Functions

	//Regular

	void endApplication();

	//update

	void updateDt();
	void updateSFMLEvents();
	void update();

	//render

	void render();

	//core

	void run();
};
#endif
