#include "Game.h"



//initialization functions

void Game::initWindow() {

	//default states
	std::string title = "None";
	sf::VideoMode window_bounds(800, 600);
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;

	//try to load states from file
	std::ifstream ifs("config/window.ini");
	
	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	ifs.close();

	window = new sf::RenderWindow(window_bounds, title);
	window->setFramerateLimit(framerate_limit);
	window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates() {
	states.push(new GameState(window, dt, supportedKeys));
}

void Game::initKeys() {
	std::ifstream ifs("config/key_binds.ini");

	if (ifs.is_open()) {
		while (!ifs.eof()) {
			int loc = 0;
			ifs >> loc;
			supportedKeys.push(loc);
		}
	}
	else {
		throw std::runtime_error("Can't find config/key_binds.ini file.");
	}

	ifs.close();
}

//Constructor/Destructor

Game::Game() {
	initWindow();
	initStates();
	initKeys();
}

Game::~Game() {
	delete window;
	while (!states.empty()) {
		delete states.top();
		states.pop();
	}
}

//Functions

//just some function, called at the end
void Game::endApplication() {
	std::cout << "Ending application \n";
}

//Sets delta time
void Game::updateDt() {
	dt = dtClock.restart().asSeconds();
}

//Handle window events
void Game::updateSFMLEvents() {
	while (window->pollEvent(windowEvent)) {
		if (windowEvent.type == sf::Event::Closed)
			window->close();
	}
}

//Update things every frame
void Game::update() {
	updateDt();
	updateSFMLEvents();
	if (!states.empty()) {

		IState* currentState = states.top();

		currentState->update();
		if (currentState->getQuit()) {

			//cleaning
			currentState = nullptr;
			delete states.top();
			states.pop();
		}
	}
	//if no more states than end application
	else {
		//just before end
		endApplication();

		window->close();
	}
}

//Renders canvas for window
void Game::render() {
	window->clear();

	//render items
	if (!states.empty()) {
		states.top()->render();
	}
	window->display();
}

//Runs the main loop
void Game::run() {
	while (window->isOpen()) {
		update();
		render();
	}
}
