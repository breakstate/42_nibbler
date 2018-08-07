#include "../includes/ObjectManager.hpp"

ObjectManager::ObjectManager( int width, int height ){
	this->_height = height;
	this->_width = width;
	std::cout << "created snake" << std::endl;
	this->_snake = new Snake( 3, 3, RIGHT );
}

ObjectManager::ObjectManager( void ){
	std::cout << "created snake" << std::endl;
	this->_snake = new Snake( 3, 3, RIGHT );
}

ObjectManager::~ObjectManager( void ){
}

int		ObjectManager::collisionManager( void ){
	int	x = this->_snake->getHeadX();
	int	y = this->_snake->getHeadY();
	int	index;
	if ((x < 0) || (x >= (this->_width / 11))){ // moving scaling to lib
		exit(0);
	}
	if ((y < 0) || (y >= (this->_height / 11))){ // moving scaling to lib
		exit(0);
	}
	if (this->_snake->checkHeadCollision( _foodX, _foodY )){
		this->_snake->grow();
		this->generateFood();
		// incremement points
	}
	if ((index = this->_snake->checkBodyCollision( x, y ))){
		exit(0); // call library close function
		//the pdf hates fun
		//this->_snake->chop( index );
	}
	return (0);
}

void	ObjectManager::generateFood( void ){
	while (1){
		this->_foodX = (rand() % (this->_width / 11));//   /11 // need to move sacling to lib
		this->_foodY = (rand() % (this->_height / 11));//   /11 // need to move sacling to lib
		if (!(this->_snake->checkHeadCollision( _foodX, _foodY )) &&
			!(this->_snake->checkBodyCollision( _foodX, _foodY ))){
			break;
		}
	}
}

void	ObjectManager::moveSnake( void ){
	this->_snake->move();
	this->_snake->debugPrint();
}

int		ObjectManager::getFoodX( void ){
	return (this->_foodX);
}

int		ObjectManager::getFoodY( void ){
	return (this->_foodY);
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