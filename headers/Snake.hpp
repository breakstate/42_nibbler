#ifndef SNAKE_H
# define SNAKE_H

# include <vector>
# include <iostream>

# include "Direction.hpp"
# include "Segment.hpp"

class Snake {

public:

Snake( void );
~Snake( void );
//Snake( const Snake & srcObj);
//Snake & operator=( Snake const & srcObj );

Snake( int startX, int startY, eDir startDir );

void		move( void );
int			getLength( void );
int			getHeadX( void );
int			getHeadY( void );
eDir		getDir( void );
void		setDir( eDir direction );
void		debugPrint( void );
int			checkCollision( void );
void		grow( void );

std::vector<segment>	body;

protected:

private:

void		_shrink( void );

int						_headX;
int						_headY;
int						_length;
eDir					_direction;

};

#endif