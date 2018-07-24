#ifndef GAME_H
# define GAME_H

# include "Snake.hpp"

class Game {

public:

Game( void );
~Game( void );
//Game( const Game & srcObj);
//Game & operator=( Game const & srcObj );

void	gameloop( void );

protected:

private:

// **member functions
// gameloop
// draw (?)

// **attributes
Snake *_snake;
// Snake class instance
// graphics lib controller (middle man) class instance

};

#endif