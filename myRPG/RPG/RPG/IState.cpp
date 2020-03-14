#include "IState.h"

//Constructor/Destructor

IState::IState(sf::RenderWindow* window, const float& delta) : dt(delta) {
	this->window = window;
	//wantsEnd = false;
	quit = false;
}

IState::~IState() {
}

//functions

const bool& IState::getQuit() const {
	return quit;
}


