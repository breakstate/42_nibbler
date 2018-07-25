#include "../headers/SDL2.hpp"
#include "../../../includes/Direction.hpp"

SDL::SDL(int height, int width) {

}

void        SDL::setScreen(SDL_Window *screen) { this->_Window = screen; }

SDL_Window  *SDL::getScreen() { return (this->_Window); }

void        SDL::init() {
    if (SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
        std::cout  << "SDL Initialization Error" << std::endl;
        return ;
    }
    this->setScreen(SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,640,SDL_WINDOW_OPENGL));
    if (!this->getScreen()) {
        std::cout << "Window not Created" << std::endl;
    }
}

int         SDL::keyHook() {
    SDL_Event   event;

    SDL_WaitEvent(&event);
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_UP: return UP;
                case SDLK_DOWN: return DOWN;
                case SDLK_LEFT: return LEFT;
                case SDLK_RIGHT: return RIGHT;
            }
    }
}

void    SDL::print() {}