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

void		            move( void );
int			            getLength( void );
int			            getHeadX( void );
int			            getHeadY( void );
eDir		            getDir( void );
void		            setDir( eDir direction );
int			            checkHeadCollision( int x, int y );
int			            checkBodyCollision( int x, int y );
void		            grow( void );
void		            chop( int index );
std::vector<segment>	getBody( void );

void		debugPrint( void );


protected:

private:

std::vector<segment>	_body;
int						_length;
eDir					_direction;

};

#endif