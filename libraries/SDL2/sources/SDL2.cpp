#include "../includes/SDL2.hpp"
#include "../../../includes/Direction.hpp"
#include <iostream>

SDL::SDL(int height, int width) : _blockHeight(10), _blockWidth(10), _WindowHeight(height), _WindowWidth(width) {
    std::cout << "SDL Constructor called" << std::endl;
    this->init();
}

SDL::SDL() {
    std::cout << "SDL Default Constructor called" << std::endl;
}

SDL::~SDL() {
    std::cout << "SDL Default Destructor called" << std::endl;
    SDL_DestroyWindow( this->getScreen() );
    SDL_Quit();
}

void        SDL::setScreen(SDL_Window *screen) { this->_Window = screen; }

SDL_Window  *SDL::getScreen() { return (this->_Window); }

void        SDL::init() {
    if (SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
        std::cout  << "SDL Initialization Error" << std::endl;
        return ;
    }
    this->setScreen(SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,this->_WindowHeight,this->_WindowWidth, SDL_WINDOW_SHOWN));
    if (!this->getScreen()) {
        std::cout << "Window not Created" << std::endl;
    } else {
        this->_screenSurface = SDL_GetWindowSurface( this->getScreen() );
        // this->_rect.w = this->_blockWidth;
        // this->_rect.h = this->_blockHeight;
        // this->_rect.x = (this->_WindowWidth - this->_rect.w) / 2;
        // this->_rect.y = (this->_WindowHeight - this->_rect.h) / 2;
        // this->_boxcolor = SDL_MapRGB(this->_screenSurface->format, 0, 0, 255);
        // this->_backgroundcolor = SDL_MapRGB(this->_screenSurface->format, 0, 0, 0);
        // SDL_FillRect(this->_screenSurface, NULL, this->_backgroundcolor);
        // SDL_FillRect(this->_screenSurface, &this->_rect, this->_boxcolor);
        // SDL_UpdateWindowSurface(this->_Window);
    }
    
}

int         SDL::keyHook()   {
    while (SDL_PollEvent(&_event)) {
        if (_event.type == SDL_QUIT) {
            exit(0);
        }
        switch (_event.type) {
           case SDL_KEYDOWN:
               switch (_event.key.keysym.sym) {
                   case SDLK_UP: return UP;
                   case SDLK_DOWN: return DOWN;
                   case SDLK_LEFT: return LEFT;
                   case SDLK_RIGHT: return RIGHT;
               }
        }
    }
    return (OTHER);
}

void    SDL::print(std::vector<segment>	body) {
    std::cout << "Printing...." << std::endl;
    std::cout << "Head X: " << body[0].x << std::endl;
    std::cout << "Head Y: " << body[0].y << std::endl;
    SDL_FillRect(this->_screenSurface, NULL, 0x000000);
    this->_rect.w = this->_blockWidth;
    this->_rect.h = this->_blockHeight;
    std::cout << "X: " << ((this->_WindowWidth - this->_rect.w) / 2) << std::endl;
    std::cout << "Y: " << ((this->_WindowHeight - this->_rect.h) / 2) << std::endl;
    this->_rect.x = body[0].x;
    this->_rect.y = body[0].y;
    this->_boxcolor = SDL_MapRGB(this->_screenSurface->format, 0, 0, 255);
    this->_backgroundcolor = SDL_MapRGB(this->_screenSurface->format, 0, 0, 0);
    SDL_FillRect(this->_screenSurface, NULL, this->_backgroundcolor);
    SDL_FillRect(this->_screenSurface, &this->_rect, this->_boxcolor);
    SDL_FillRect(this->_screenSurface, NULL, this->_backgroundcolor);
    SDL_FillRect(this->_screenSurface, &this->_rect, this->_boxcolor);
    SDL_UpdateWindowSurface(this->_Window);
}

SDL         *create(int height, int width) {
    return new SDL(height, width);
}

void        destroy(LibraryManager *lib) {
    delete (lib);
}