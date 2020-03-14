#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, const float& delta, const std::queue<int>& supportedKeys) : IState(window, delta, supportedKeys) {
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
