#ifndef GAME_H
# define GAME_H

# include "Snake.hpp"
# include "ObjectManager.hpp"
# include "../libraries/LibraryManager.hpp"

class Game {

public:

Game( void );
Game( int width, int height );
~Game( void );
//Game( const Game & srcObj);
//Game & operator=( Game const & srcObj );

void	gameloop( void );
eDir	testAI( int safe );
void	setLib( LibraryManager *newLib );
void	setLib();
void	deleteLib( void );

protected:

private:

ObjectManager	*_OM;
const char		*_libs[3];
int				_libID;
void			*_handler;
createLib_t		*createLib;
destroyLib_t	*destroyLib;
LibraryManager	*_LM;
eDir			_getKey( void );
int				_width;
int				_height;

};

#endif