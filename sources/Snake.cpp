#include "../includes/Snake.hpp"

Snake::Snake( void ){}

Snake::~Snake( void ){}

Snake::Snake( int startX, int startY, eDir startDir ){
	segment *temp = new segment;
	temp->x = startX;
	temp->y = startY;
	temp->head = 1;
	this->_direction = startDir;
	this->_body.insert(this->_body.begin(), *temp);
	delete temp;
	this->grow();
}

void		Snake::move( void ){
	switch(this->_direction){
	case LEFT:
		this->_body[0].x -=1;
		break;
	case UP:
		this->_body[0].y -=1;
		break;
	case RIGHT:
		this->_body[0].x +=1;
		break;
	case DOWN:
		this->_body[0].y +=1;
		break;
	case OTHER:
		break;
	case SWITCH_SDL:
		break;
	case SWITCH_SFML:
		break;
	case SWITCH_NCURSES:
		break;
	case PAUSE:
		break;
	case QUIT:
		break;
	};
	for (std::vector<int>::size_type i = 0; i < this->_body.size(); i++){
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
}

int			Snake::getHeadX( void ){
	return (this->_body[0].x);
}

int			Snake::getHeadY( void ){
	return (this->_body[0].y);
}

eDir		Snake::getDir( void ){
	return (this->_direction);
}

void		Snake::setDir( eDir direction ){
	this->_direction = direction;
}

int			Snake::checkHeadCollision( int x, int y ){
	if ((this->getHeadX() == x) && (this->getHeadY() == y))
		return (1);
	return (0);
}

int			Snake::checkBodyCollision( int x, int y ){
	for (std::vector<int>::size_type i = 1; i < this->_body.size(); i++){
		if (this->_body[i].x == x && this->_body[i].y == y){
			return (i);
		}
	}
	return (0);
}

void		Snake::grow( void ){
	segment *temp = new segment;
	temp->x = this->_body.back().x;
	temp->y = this->_body.back().y;
	temp->xAhead = this->_body.back().x;
	temp->yAhead = this->_body.back().y;
	temp->head = 0;
	this->_body.push_back(*temp);
	delete temp;
}

void		Snake::chop( int index ){
	this->_body.erase ( this->_body.begin() + index , this->_body.end() );
}

std::vector<segment>	Snake::getBody( void ){
	return (this->_body);
}