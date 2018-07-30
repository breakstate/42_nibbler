#ifndef GAME_H
# define GAME_H

# include "Snake.hpp"
# include "ObjectManager.hpp"
# include "../libraries/LibraryManager.hpp"

class Game {

public:

Game( void );
~Game( void );
//Game( const Game & srcObj);
//Game & operator=( Game const & srcObj );

void	gameloop( void );
eDir	testAI( int safe );
void    setLib( LibraryManager *newLib );
void    deleteLib( void );

protected:

private:

ObjectManager   _OM;
char            *_libs[3];
void            *_handler;
createLib_t     *createLib;
destroyLib_t    *destroyLib;
LibraryManager  *_LM;
eDir			_getDir( void );

};

#endif