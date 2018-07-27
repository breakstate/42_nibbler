#include "../includes/Game.hpp"
#include "../libraries/SDL2/includes/SDL2.hpp"
#include <unistd.h> // for usleep
#include <time.h> //
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

Game::Game( void ) {
	this->_handler = dlopen("libraries/SDL2/SDL2.so", RTLD_NOW);
	if (!this->_handler) {
		std::cout << "DLOPEN Error" << std::endl;
		std::cout << dlerror() << std::endl;
	}
	createLib = (createLib_t*) dlsym(this->_handler, "create");
	destroyLib = (destroyLib_t*) dlsym(this->_handler, "destroy");
	if (dlerror()) {
		std::cout << "ERROR" << std::endl;
		std::cout << dlerror() << std::endl;
		std::cout << "ERROR" << std::endl;
	}
	this->setLib(createLib(640, 640));
}

Game::~Game( void ){

}

void	Game::gameloop( void ){
	srand(time(NULL)); // for random dir
	this->_OM.generateFood();
	int	tick = 0;
	unsigned int microseconds = 1000000;
	int quit = 0;
	while (!(quit)){
		if (this->_OM.collisionManager())
			std::cout << "You'd be so dead rn" << std::endl;
		eDir direction = static_cast<eDir>(this->_LM->keyHook());
		std::cout << "Direction is: " << direction << std::endl;
		this->_OM.setSnakeDir( direction );
		this->_OM.moveSnake();
		this->_LM->print(this->_OM.getSnakeBody());
		// if (tick == 5){
		// 	this->_OM.setSnakeDir( this->testAI(0) ); // debug // test
		// 	tick = 0;
		// }
		// tick++;
		usleep(microseconds);
	}
}

eDir	Game::testAI( int safe ){
	int dir = rand() % 4;
	//std::cout << dir << std::endl; // debug AI direction
	switch (dir){
		case(0):
		if (this->_OM.getSnakeDir() != RIGHT && this->_OM.getSnakeDir() != LEFT){
			std::cout << "LEFT" << std::endl; // debug AI direction
			return (LEFT);
		}
		std::cout << "already left or right" << std::endl; // debug AI direction
		break;
		case(1):
		if (this->_OM.getSnakeDir() != DOWN && this->_OM.getSnakeDir() != UP){
			std::cout << "UP" << std::endl; // debug AI direction
			return (UP);
		}
		std::cout << "already up or down" << std::endl; // debug AI direction
		break;
		case(2):
		if (this->_OM.getSnakeDir() != LEFT && this->_OM.getSnakeDir() != RIGHT){
			std::cout << "RIGHT" << std::endl; // debug  AI direction
			return (RIGHT);
		}
		std::cout << "already right or left" << std::endl; // debug AI direction
		break;
		case(3):
		if (this->_OM.getSnakeDir() != UP && this->_OM.getSnakeDir() != DOWN){
			std::cout << "DOWN" << std::endl; // debug AI direction
			return (DOWN);
		}
		std::cout << "already down or up" << std::endl; // debug AI direction
		break;
	};
	return (OTHER);
}

void    Game::setLib( LibraryManager *newLib ) {
	this->_LM = newLib;
}

void    Game::deleteLib( void ) {
	destroyLib(this->_LM);
}
