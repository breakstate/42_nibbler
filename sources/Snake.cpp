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
	this->_direction = startDir;
	this->_body.insert(this->_body.begin(), *temp);
	delete temp;
	this->grow(); // debug // test
}

void		Snake::move( void ){
	switch(this->_direction){
	case LEFT:
		this->_body[0].x -=5;
		break;
	case UP:
		this->_body[0].y -=5;
		break;
	case RIGHT:
		this->_body[0].x +=5;
		break;
	case DOWN:
		this->_body[0].y +=5;
		break;
	case OTHER:
		std::cout << "other" << std::endl;
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
	return (this->_body.size());
	//return (this->_length);
}

int			Snake::getHeadX( void ){
	return (this->_body[0].x);
	//return (this->_headX);
}

int			Snake::getHeadY( void ){
	return (this->_body[0].y);
	//return (this->_headY);
}

eDir		Snake::getDir( void ){
	return (this->_direction);
}

void		Snake::setDir( eDir direction ){
	this->_direction = direction;
}

int			Snake::checkHeadCollision( int x, int y ){
	// check collision with own head
	if (this->getHeadX() == x && this->getHeadY() == y)
		return (1);
	return (0);
}

int			Snake::checkBodyCollision( int x, int y ){
	// check collision with own body
	for (int i = 1; i < this->_body.size(); i++){
		if (this->_body[i].x == x && this->_body[i].y == y)
			return (1);
	}
	return (0);
}

void		Snake::grow( void ){
	segment *temp = new segment;
	temp->x = this->_body.end()->x;// + 1;
	temp->y = this->_body.end()->y;// + 1;
	temp->xAhead = this->_body.end()->x;
	temp->yAhead = this->_body.end()->y;
	temp->head = 0;
	//temp->index = 0; // not sure if needed
	this->_body.push_back(*temp);
	delete temp;
}

void		Snake::chop( int index ){
	this->_body.erase ( this->_body.begin() + index , this->_body.end() );
}

std::vector<segment>	Snake::getBody( void ){
	return (this->_body);
}


void		Snake::debugPrint( void ){
	std::cout << "debug print:" << std::endl;
	for (int i = 0; i < this->_body.size(); i++){
		std::cout << "x: " + std::to_string(this->_body[i].x) << "	y: " + std::to_string(this->_body[i].y) << std::endl;
	}
	std::cout << std::endl;
}