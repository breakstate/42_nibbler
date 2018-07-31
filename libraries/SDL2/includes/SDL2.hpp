
#include "../../LibraryManager.hpp"
#include "../SDL2/SDL.h"
#ifndef SDL_LIB
#define SDL_LIB

class SDL : public LibraryManager {
    public:
        SDL(int height, int width);
        virtual ~SDL();

        void        setScreen(SDL_Window *screen);
        SDL_Window  *getScreen();

        void        init();
        int         keyHook();
        void        print(std::vector<segment>	body, int foodX, int foodY);
        void        print_rect(int x, int y, int head);

    private:
        SDL( void );
        SDL_Window*     _Window;
        SDL_Surface     *_screenSurface;
        SDL_Event       _event;
        unsigned        _boxcolor;
        unsigned        _backgroundcolor;
        int             _blockHeight;
        int             _blockWidth;
        int             _WindowHeight;
        int             _WindowWidth;
};

#ifdef __cplusplus
extern "C" {
#endif

SDL         *create(int height, int width);
void        destroy(LibraryManager *lib);

#ifdef __cplusplus
}
#endif

#endif // !SDL_LIB