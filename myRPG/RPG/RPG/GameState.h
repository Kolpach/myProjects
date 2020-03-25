#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "IState.h"

class GameState : public IState
{
private:
	Entity player = Entity(dt);
	setDirCommand left = setDirCommand(&player, -1, 0);
	setDirCommand right = setDirCommand(&player, 1, 0);
	setDirCommand up = setDirCommand(&player, 0, -1);
	setDirCommand down = setDirCommand(&player, 0, 1);
public:
	GameState(sf::RenderWindow* window, const float& delta);
	virtual ~GameState();
	//Functions

	//just before end
	virtual void endState();

	//updates key press events
	virtual void handleInput() override;
	virtual void initInput(const std::vector<int>& supportedKeys) override;
	virtual void update() override;
	virtual void render(sf::RenderTarget* target = nullptr) override;
};

#endif
