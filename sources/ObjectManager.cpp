#include "../includes/ObjectManager.hpp"

#define SCRN_WIDTH 20 // debug // test
#define SCRN_HEIGHT 15 // debug // test

ObjectManager::ObjectManager( void ){
	std::cout << "created snake" << std::endl;
	this->_snake = new Snake( 10, 10, LEFT );
}

ObjectManager::~ObjectManager( void ){
}

int		ObjectManager::collisionManager( void ){
	int	x = this->_snake->getHeadX();
	int	y = this->_snake->getHeadY();
	std::cout << "x= " << x << "; y= " << y << std::endl;
	if ((x <= 0) || (x >= SCRN_WIDTH)){
		std::cout << "1" << std::endl;
		return (1);
	}
	if ((y <= 0) || (y >= SCRN_HEIGHT)){
		std::cout << "2" << std::endl;
		return (1);
	}
	if (x == _foodX && y == _foodY){
		std::cout << "3" << std::endl;
		this->_snake->grow();
	}
	for (int i = 1; i < this->_snake->body.size(); i++){
		if (x == this->_snake->body[i].x && y == this->_snake->body[i].y ){
			std::cout << "4" << std::endl;
			return (1);
		}
	}
	return (0);
}

void	ObjectManager::generateFood( void ){
	this->_foodX = (rand() % (SCRN_WIDTH + 1)) - 2;
	this->_foodY = (rand() % (SCRN_HEIGHT + 1)) - 2;

	//debug print
	std::cout << "Food:\nx: " << this->_foodX << "	y: " << this->_foodY << std::endl;
}

void	ObjectManager::moveSnake( void ){
	this->_snake->move();
	this->_snake->debugPrint();
}

void	ObjectManager::setSnakeDir( eDir direction ){
	this->_snake->setDir( direction );
}