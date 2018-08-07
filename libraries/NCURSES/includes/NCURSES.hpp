#ifndef NCURSES_H
# define NCURSES_H

# include <vector>
# include <iostream>
# include <ncurses.h>

# include "../../LibraryManager.hpp"

class NCURSES: public LibraryManager{

public:
		NCURSES(void);
		NCURSES(int height, int width);
		~NCURSES();

		void        init();
		int         keyHook();
		void        print(std::vector<segment>	body, int foodX, int foodY);
		void        print_rect(int x, int y, int colour);

private:
		WINDOW    *_Window;
		int                 _WindowHeight;
		int                 _WindowWidth;
};

#ifdef __cplusplus
extern "C" {
#endif

NCURSES		*create(int height, int width);
void		destroy(LibraryManager *lib);

#ifdef __cplusplus
}
#endif

#endif