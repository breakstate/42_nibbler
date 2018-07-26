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
	std::cout << dir << std::endl; // debug AI direction
	switch (dir){
		case(0):
		if (this->_OM.getSnakeDir() != RIGHT && this->_OM.getSnakeDir() != LEFT){
			std::cout << "LEFT" << std::endl; // debug AI direction
			return (LEFT);
		}
		std::cout << "already left" << std::endl; // debug AI direction
		break;
		case(1):
		if (this->_OM.getSnakeDir() != DOWN && this->_OM.getSnakeDir() != UP){
			std::cout << "UP" << std::endl; // debug AI direction
			return (UP);
		}
		std::cout << "already up" << std::endl; // debug AI direction
		break;
		case(2):
		if (this->_OM.getSnakeDir() != LEFT && this->_OM.getSnakeDir() != RIGHT){
			std::cout << "UP" << std::endl; // debug  AI direction
			return (RIGHT);
		}
		std::cout << "already right" << std::endl; // debug AI direction
		break;
		case(3):
		if (this->_OM.getSnakeDir() != UP && this->_OM.getSnakeDir() != DOWN){
			std::cout << "UP" << std::endl; // debug AI direction
			return (DOWN);
		}
		std::cout << "already down" << std::endl; // debug AI direction
		break;
	};
	return (this->_OM.getSnakeDir());
}