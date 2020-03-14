#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, const float& delta) : IState(window, delta) {
	
}

GameState::~GameState() {
}

//Functions

//just before end
void GameState::endState() {
	quit = true;
}

void GameState::updateInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		endState();
	}
	for (auto pairCommand : allowedKeys) {
		if (sf::Keyboard::isKeyPressed(pairCommand.first)) {
			pairCommand.second->execute();
		}
	}
}

void GameState::initInput(const std::vector<int>& supportedKeys) {
	allowedKeys = {
		{static_cast<sf::Keyboard::Key>(supportedKeys[0]), &left},
		{static_cast<sf::Keyboard::Key>(supportedKeys[1]), &right},
		{static_cast<sf::Keyboard::Key>(supportedKeys[2]), &up},
		{static_cast<sf::Keyboard::Key>(supportedKeys[3]), &down},
	};
}

void GameState::update() {
	updateInput();
	player.update();
}

void GameState::render(sf::RenderTarget* target) {
	if (!target) {
		target = window;
	}
	player.render(target);
}
