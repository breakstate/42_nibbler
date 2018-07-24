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

protected:

private:

Snake	*_snake;
int		_foodX;
int		_foodY;

};

#endif