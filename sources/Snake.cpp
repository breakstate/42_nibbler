#include "../includes/Snake.hpp"

Snake::Snake( void ){
}

Snake::~Snake( void ){
}

Snake::Snake( int startX, int startY, eDir startDir ){
	segment *temp = new segment;
	temp->x = startX;
	temp->y = startY;
	temp->head = 1;
	//temp->index = 0; // not sure if needed
	this->_direction = startDir;
	this->body.insert(this->body.begin(), *temp);
	delete temp;
	this->grow(); // debug // test
}

void		Snake::move( void ){
	switch(this->_direction){
	case LEFT:
		this->_headX -= 1;
		this->body[0].x -=1;
		break;
	case UP:
		this->_headY -= 1;
		this->body[0].y -=1;
		break;
	case RIGHT:
		this->_headX += 1;
		this->body[0].x +=1;
		break;
	case DOWN:
		this->_headY += 1;
		this->body[0].y +=1;
		break;
	};
	for (int i = 0; i < this->body.size(); i++){
		if (!(this->body[i].head)){
			this->body[i].x = this->body[i].xAhead;
			this->body[i].y = this->body[i].yAhead;
			this->body[i].xAhead = this->body[i-1].x;
			this->body[i].yAhead = this->body[i-1].y;
		}
	}
}

int			Snake::getLength( void ){
	return (this->_length);
}

int			Snake::getHeadX( void ){
	return (this->_headX);
}

int			Snake::getHeadY( void ){
	return (this->_headY);
}

eDir		Snake::getDir( void ){
	return (this->_direction);
}

void		Snake::setDir( eDir direction ){
	this->_direction = direction;
}

int			Snake::checkCollision( void ){
	// gameover on collision with self or walls
	return (0);
}

void		Snake::grow( void ){
	segment *temp = new segment;
	temp->x = this->body.end()->x + 1;
	temp->y = this->body.end()->y + 1;
	temp->xAhead = this->body.end()->x;
	temp->yAhead = this->body.end()->y;
	temp->head = 0;
	//temp->index = 0; // not sure if needed
	this->body.push_back(*temp);
	delete temp;
}

void		Snake::_shrink( void ){

}

void		Snake::debugPrint( void ){
	std::cout << "debug print:" << std::endl;
	for (int i = 0; i < this->body.size(); i++){
		std::cout << "x: " + std::to_string(this->body[i].x) << "	y: " + std::to_string(this->body[i].y) << std::endl;
	}
	std::cout << std::endl;
}

//collisions?
//move
//draw