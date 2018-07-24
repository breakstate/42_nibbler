#include "../includes/Game.hpp"
#include <unistd.h> // for usleep
#include <time.h> //
#include <stdlib.h>
#include <unistd.h>


Game::Game( void){
	std::cout << "test" << std::endl;
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
		this->_OM.moveSnake();
		if (tick == 5){
			this->_OM.setSnakeDir( this->testAI(0) ); // debug // test
			tick = 0;
		}
		tick++;
		usleep(microseconds);
	}
}

eDir	Game::testAI( int safe ){
	int dir = rand() % 4;
	std::cout << dir << std::endl;
	switch (dir){
		case(0):
		return (LEFT);
		case(1):
		return (UP);
		case(2):
		return (RIGHT);
	};
	return (DOWN);
}