#ifndef GAME_H
# define GAME_H

# include "Snake.hpp"
# include "ObjectManager.hpp"

class Game {

public:

Game( void );
~Game( void );
//Game( const Game & srcObj);
//Game & operator=( Game const & srcObj );

void	gameloop( void );
eDir	testAI( int safe );

protected:

private:

ObjectManager _OM;
//LibraryManager _LM;
// **member functions


// **attributes
//Snake *_snake; // moved to object manager
// Snake class instance
// graphics lib controller (middle man) class instance

};

#endif