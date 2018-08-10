#ifndef OBJECTMANAGER_H
# define OBJECTMANAGER_H

# include "Snake.hpp"
# include "Direction.hpp"

class ObjectManager {

public:

ObjectManager( int width, int height );
ObjectManager( void );
~ObjectManager( void );
//ObjectManager( const ObjectManager & srcObj);
//ObjectManager & operator=( ObjectManager const & srcObj );

//drawManager
//void	objectCleaner

int		collisionManager( void );
void	generateFood( void );
void	moveSnake( void );
int		getFoodX( void );
int		getFoodY( void );
void	setSnakeDir( eDir direction );
eDir	getSnakeDir( void );
std::vector<segment>	getSnakeBody( void );
void	draw( void );

int		playerScore;

protected:

private:

void	_drawSnake( void );
void	_drawFood( void );

Snake	*_snake;
int		_foodX;
int		_foodY;
int		_height;
int		_width;

};

#endif