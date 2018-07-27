#ifndef OBJECTMANAGER_H
# define OBJECTMANAGER_H

# include "Snake.hpp"
# include "Direction.hpp"

class ObjectManager {

public:

ObjectManager( void );
~ObjectManager( void );
//ObjectManager( const ObjectManager & srcObj);
//ObjectManager & operator=( ObjectManager const & srcObj );

//drawManager
//void	objectCleaner

int		collisionManager( void );
void	generateFood( void );
void	moveSnake( void );
void	setSnakeDir( eDir direction );
eDir	getSnakeDir( void );
std::vector<segment>	getSnakeBody( void );
void	draw( void );

protected:

private:

void	_drawSnake( void );
void	_drawFood( void );

Snake	*_snake;
int		_foodX;
int		_foodY;

};

#endif