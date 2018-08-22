#include "../includes/ObjectManager.hpp"

ObjectManager::ObjectManager( int width, int height ){
	this->_height = height;
	this->_width = width;
	this->playerScore = 0;
	this->_snake = new Snake( 3, 3, RIGHT );
}

ObjectManager::ObjectManager( void ){
}

ObjectManager::~ObjectManager( void ){
}

int		ObjectManager::collisionManager( void ){
	int	x = this->_snake->getHeadX();
	int	y = this->_snake->getHeadY();
	int	index;
	if ((x < 0) || (x >= (this->_width / 11))){
		return (1);
	}
	if ((y < 0) || (y >= (this->_height / 11))){
		return (1);
	}
	if (this->_snake->checkHeadCollision( _foodX, _foodY )){
		this->_snake->grow();
		this->generateFood();
		this->playerScore += 50;
		return (2);
	}
	if ((index = this->_snake->checkBodyCollision( x, y ))){
		return (1);
		//this->_snake->chop( index );
	}
	return (0);
}

void	ObjectManager::generateFood( void ){
	while (1){
		this->_foodX = (rand() % (this->_width / 11));
		this->_foodY = (rand() % (this->_height / 11));
		if (!(this->_snake->checkHeadCollision( _foodX, _foodY )) &&
			!(this->_snake->checkBodyCollision( _foodX, _foodY ))){
			break;
		}
	}
}

void	ObjectManager::moveSnake( void ){
	this->_snake->move();
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