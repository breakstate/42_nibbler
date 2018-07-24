#include "../headers/Game.hpp"
#include <unistd.h>

Game::Game( void){
	std::cout << "test" << std::endl;
	this->_snake = new Snake( 10, 10, LEFT );
}

Game::~Game( void ){

}

void	Game::gameloop( void ){
	int	tick = 0;
	unsigned int microseconds = 1000000;
	int quit = 0;
	while (!(quit)){
		this->_snake->move();
		this->_snake->debugPrint();
		if (tick == 3){
			this->_snake->setDir( UP );
		}
		tick++;
		usleep(microseconds);
	}
}