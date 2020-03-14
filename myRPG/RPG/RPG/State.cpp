#include "IState.h"

//Constructor/Destructor

IState::IState(sf::RenderWindow* window) {
	this->window = window;
	quit = false;
}

IState::~IState() {
}

//functions

const bool& IState::getQuit() const {
	return quit;
}