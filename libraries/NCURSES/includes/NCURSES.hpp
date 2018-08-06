#ifndef NCURSES_H
# define NCURSES_H

# include <vector>
# include <iostream>
# include <ncurses.h>

# include "segment.hpp"

class NCURSES{

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

#endif