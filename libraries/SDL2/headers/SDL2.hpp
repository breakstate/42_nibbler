
#include "../../LibraryManager.hpp"

#ifndef SDL_LIB
#define SDL_LIB

class SDL : public LibraryManager {
    public:
        SDL(int height, int width);

        void        setScreen(SDL_Window *screen);
        SDL_Window  *getScreen();

        void        init();
        int         keyHook() = 0;
        void        print() = 0;
    private:
        SDL_Window*    _Window;
        SDL_Event       _event;
        int             _blockHeight;
        int             _blockWidth;
        int             _WindowHeight;
        int             _WindowWidth;
};


#endif // !SDL_LIB