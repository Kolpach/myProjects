#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "IState.h"
#include "setDirCommand.h"

class GameState : public IState
{
private:
	Entity player = Entity(dt);
	setDirCommand left = setDirCommand(&player, -1, 0);
	setDirCommand right = setDirCommand(&player, 1, 0);
	setDirCommand up = setDirCommand(&player, 0, -1);
	setDirCommand down = setDirCommand(&player, 0, 1);
public:
	GameState(sf::RenderWindow* window, const float& delta, const std::queue<int>& supportedKeys);
	virtual ~GameState();
	std::map<sf::Keyboard::Key, ICommand* > allowedKeys = {
		supportedKeys.push();
		{static_cast<sf::Keyboard::Key>(0), &left},
		{static_cast<sf::Keyboard::Key>(3), &right},
		{static_cast<sf::Keyboard::Key>(22), &up},
		{static_cast<sf::Keyboard::Key>(18), &down},
		
	};
	//Functions

	//just before end
	virtual void endState();
	//updates key press events
	virtual void updateInput() override;
	virtual void update() override;
	virtual void render(sf::RenderTarget* target = nullptr) override;
};

#endif
