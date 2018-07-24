#include "../hdr/Snake.hpp"

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
	this->_body.insert(this->_body.begin(), *temp);
	delete temp;
	this->_grow(); // debug // test
}

void		Snake::move( void ){
	switch(this->_direction){
	case LEFT:
		this->_headX -= 1;
		this->_body[0].x -=1;
		break;
	case UP:
		this->_headY -= 1;
		this->_body[0].y -=1;
		break;
	case RIGHT:
		this->_headX += 1;
		this->_body[0].x +=1;
		break;
	case DOWN:
		this->_headY += 1;
		this->_body[0].y +=1;
		break;
	};
	for (int i = 0; i < this->_body.size(); i++){
		if (!(this->_body[i].head)){
			this->_body[i].x = this->_body[i].xAhead;
			this->_body[i].y = this->_body[i].yAhead;
			this->_body[i].xAhead = this->_body[i-1].x;
			this->_body[i].yAhead = this->_body[i-1].y;
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

void		Snake::_checkCollision( void ){
	// gameover on collision with self or walls
}

void		Snake::_grow( void ){
	segment *temp = new segment;
	temp->x = this->_body.end()->x + 1;
	temp->y = this->_body.end()->y + 1;
	temp->xAhead = this->_body.end()->x;
	temp->yAhead = this->_body.end()->y;
	temp->head = 0;
	//temp->index = 0; // not sure if needed
	this->_body.push_back(*temp);
	delete temp;
}

void		Snake::_shrink( void ){

}

void		Snake::debugPrint( void ){
	std::cout << "debug print:" << std::endl;
	for (int i = 0; i < this->_body.size(); i++){
		std::cout << "x: " + std::to_string(this->_body[i].x) << "	y: " + std::to_string(this->_body[i].y) << std::endl;
	}
	std::cout << std::endl;
}

//collisions?
//move
//draw