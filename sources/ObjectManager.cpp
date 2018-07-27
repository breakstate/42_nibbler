#include "../includes/ObjectManager.hpp"

#define SCRN_WIDTH 640 // debug // test
#define SCRN_HEIGHT 640 // debug // test

ObjectManager::ObjectManager( void ){
	std::cout << "created snake" << std::endl;
	this->_snake = new Snake( 10, 10, RIGHT );
}

ObjectManager::~ObjectManager( void ){
}

int		ObjectManager::collisionManager( void ){
	int	x = this->_snake->getHeadX();
	int	y = this->_snake->getHeadY();
	int	index;
	//std::cout << "Collision debug:\n" << "x= " << x << "; y= " << y << std::endl;
	if ((x <= 0) || (x >= SCRN_WIDTH)){
		//std::cout << "x collision" << std::endl;
		return (1);
	}
	if ((y <= 0) || (y >= SCRN_HEIGHT)){
		//std::cout << "y collision" << std::endl;
		return (1);
	}
	if (this->_snake->checkHeadCollision( _foodX, _foodY )){
		//std::cout << "food collision" << std::endl;
		this->_snake->grow();
	}
	if ((index = this->_snake->checkBodyCollision( x, y ))){
		//std::cout << "self collision" << std::endl;
		this->_snake->chop( index );
	}
	return (0);
}

void	ObjectManager::generateFood( void ){
	while (this->_snake->checkHeadCollision( _foodX, _foodY )){
	//this->_foodX = (rand() % (SCRN_WIDTH + 1)) - 2; // actual
	//this->_foodY = (rand() % (SCRN_HEIGHT + 1)) - 2; // actual
	}

	this->_foodX = 7; // test // debug
	this->_foodY = 10; // test // debug

	//debug print
	std::cout << "Food:\nx: " << this->_foodX << "	y: " << this->_foodY << std::endl;
}

void	ObjectManager::moveSnake( void ){
	this->_snake->move();
	this->_snake->debugPrint();
}

void	ObjectManager::setSnakeDir( eDir direction ){
	if (direction != OTHER) {
		this->_snake->setDir( direction );
	}
}

eDir	ObjectManager::getSnakeDir( void ){
	return (this->_snake->getDir());
}

std::vector<segment>	ObjectManager::getSnakeBody( void ) {
	return (this->_snake->getBody());
}


void	ObjectManager::_drawSnake( void ){

}

void	ObjectManager::_drawFood( void ){

}