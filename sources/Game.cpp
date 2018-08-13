#include "../includes/Game.hpp"
#include "../libraries/SDL2/includes/SDL2.hpp"
#include <unistd.h> // for usleep
#include <time.h> //
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

Game::Game( int width, int height ){
	if (width < 300 || height < 300) {
		throw (Game::MinimumscreenSizeException());
	} else if (width > 640 || height > 640) {
		throw (Game::MaximumScreenSizeException());
	}
	this->_OM = new ObjectManager(width, height);
	this->_width = width;
	this->_height = height;
	_libs[0] = "libraries/NCURSES/NCURSES.so";
	_libs[1] = "libraries/SFML/SFML.so";
	_libs[2] = "libraries/SDL2/SDL2.so";
	this->setLib();
}


Game::Game( void ) : _libID(0){
}

Game::~Game( void ){
	delete this->_OM;
}

void	Game::gameloop( void ){
	srand(time(NULL)); // for random dir
	this->_OM->generateFood();
	int	tick = 0;
	unsigned int microseconds = 100000;
	unsigned int speedModifier = 8000;
	int colResult;
	int quit = 0;
	int playing = 0;
	eDir direction;
	eDir activeDirection;
	while (!(quit)){
		direction = _getKey();
		if (direction == PAUSE) {
			playing++;
		} else if (direction == QUIT) {
			quit++;
			playing++;
			deleteLib();
		} else {
			activeDirection = direction;
		}
		if (playing % 2 == 0) {
			if (tick > 4){
				colResult = this->_OM->collisionManager();
				if (colResult == 1) {
					deleteLib();
					this->printScore();
					exit(0);
				}
				else if (colResult == 2) {
					if (microseconds > 10000)
						microseconds -= speedModifier;
					//speedModifier *= 2;
				}
			}else
				tick++;
			this->_OM->setSnakeDir( activeDirection );
			this->_LM->print(this->_OM->getSnakeBody(), this->_OM->getFoodX(), this->_OM->getFoodY());
			this->_OM->moveSnake();
		}
		usleep(microseconds);
	}
}

eDir	Game::_getKey(){
	int direction = (this->_LM->keyHook());
	switch (direction){
	case(0):
		if (this->_OM->getSnakeDir() != RIGHT && this->_OM->getSnakeDir() != LEFT){
			return (LEFT);
		}
		break;
	case(1):
		if (this->_OM->getSnakeDir() != DOWN && this->_OM->getSnakeDir() != UP){
			return (UP);
		}
		break;
	case(2):
		if (this->_OM->getSnakeDir() != LEFT && this->_OM->getSnakeDir() != RIGHT){
			return (RIGHT);
		}
		break;
	case(3):
		if (this->_OM->getSnakeDir() != UP && this->_OM->getSnakeDir() != DOWN){
			return (DOWN);
		}
		break;
	case(4):
		this->_libID = 0 ;
		usleep(500000);
		deleteLib();
		this->setLib();
		break;
	case(5):
		this->_libID = 1 ;
		deleteLib();
		this->setLib();
		break;
	case(6):
		this->_libID = 2 ;
		deleteLib();
		this->setLib();
		break;
	case(7):
		return (PAUSE);
		break;
	case(8):
		return (QUIT);
		break;
	};
	return (OTHER);
}

// eDir	Game::testAI( int safe ){
// 	int dir = rand() % 4;
// 	//std::cout << dir << std::endl; // debug AI direction
// 	switch (dir){
// 		case(0):
// 		if (this->_OM->getSnakeDir() != RIGHT && this->_OM->getSnakeDir() != LEFT){
// 			return (LEFT);
// 		}
// 		break;
// 		case(1):
// 		if (this->_OM->getSnakeDir() != DOWN && this->_OM->getSnakeDir() != UP){
// 			return (UP);
// 		}
// 		break;
// 		case(2):
// 		if (this->_OM->getSnakeDir() != LEFT && this->_OM->getSnakeDir() != RIGHT){
// 			std::cout << "RIGHT" << std::endl; // debug  AI direction
// 			return (RIGHT);
// 		}
// 		std::cout << "already right or left" << std::endl; // debug AI direction
// 		break;
// 		case(3):
// 		if (this->_OM->getSnakeDir() != UP && this->_OM->getSnakeDir() != DOWN){
// 			std::cout << "DOWN" << std::endl; // debug AI direction
// 			return (DOWN);
// 		}
// 		std::cout << "already down or up" << std::endl; // debug AI direction
// 		break;
// 	};
// 	return (OTHER);
// }

void	Game::setLib() {
	this->_handler = dlopen(this->_libs[this->_libID], RTLD_NOW);
	if (!this->_handler) {
		std::cout << dlerror() << std::endl;
	}
	createLib = (createLib_t*) dlsym(this->_handler, "create");
	destroyLib = (destroyLib_t*) dlsym(this->_handler, "destroy");
	if (dlerror()) {
		std::cout << dlerror() << std::endl;
	}
	this->setLib(createLib(this->_width, this->_height));
}

void	Game::setLib( LibraryManager *newLib ) {
	this->_LM = newLib;
}

void	Game::deleteLib( void ) {
	LibraryManager	*newLib = this->_LM;
	destroyLib(newLib);
	dlclose(this->_handler);
}

const char *Game::MaximumScreenSizeException::what() const throw() {
	return ("Error: Screen size too large\nAllowed Max Screen size: 640");
}

const char *Game::MinimumscreenSizeException::what() const throw() {
	return ("Error: Screen size too small\nAllowed Min Screen size: 300");
}

void	Game::printScore( void ){
	std::cout << "SCORE: " << this->_OM->playerScore << "!" << std::endl;
}