#include "../hdrs/Game.hpp"
#include <unistd.h>

Game::Game( void){
	std::cout << "test" << std::endl;
}

Game::~Game( void ){

}

void	Game::gameloop( void ){
	int	tick = 0;
	unsigned int microseconds = 1000000;
	int quit = 0;
	while (!(quit)){
		this->_OM.moveSnake();
		//this->_snake->debugPrint();
		if (tick == 3){
			this->_OM.setSnakeDir( UP );
		}
		tick++;
		usleep(microseconds);
	}
}