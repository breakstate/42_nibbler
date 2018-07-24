#include "../hdrs/ObjectManager.hpp"

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
	if ((x <= 0) || (x >= SCRN_WIDTH))
		return (1);
	if ((y <= 0) || (y >= SCRN_HEIGHT))
		return (1);
	if (x == _foodX && y == _foodY)
		this->_snake->grow();
	for (int i = 0; i < this->_snake->body.size(); i++){
		if (x == this->_snake->body[i].x && y == this->_snake->body[i].y )
			return (1);
	}
	return (0);
}

void	ObjectManager::generateFood( void ){

}

void	ObjectManager::moveSnake( void ){
	this->_snake->move();
	this->_snake->debugPrint();
}

void	ObjectManager::setSnakeDir( eDir direction ){
	this->_snake->setDir( direction );
}