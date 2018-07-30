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
    while (SDL_PollEvent(&_event))
    {
        if (_event.type == SDL_QUIT) {
            exit(0);
        }
        switch (_event.type) {
           case SDL_KEYDOWN:
               switch (_event.key.keysym.sym) {
                   case SDLK_UP: return UP; std::cout << "up key" << std::endl;
                   case SDLK_DOWN: return DOWN; std::cout << "up down" << std::endl;
                   case SDLK_LEFT: return LEFT; std::cout << "up left" << std::endl;
                   case SDLK_RIGHT: return RIGHT; std::cout << "up right" << std::endl;
                   //case SDLK_ESCAPE: quit
               }
        }
    }
    return (OTHER);
}

void    SDL::print(std::vector<segment>	body, int foodX, int foodY) {
    std::cout << "Printing...." << std::endl; // debug
    std::cout << "Head X: " << body[0].x << std::endl; // debug
    std::cout << "Head Y: " << body[0].y << std::endl; // debug

    this->_backgroundcolor = SDL_MapRGB(this->_screenSurface->format, 0, 0, 0);

    SDL_FillRect(this->_screenSurface, NULL, this->_backgroundcolor);

    // code for drawing rects
    this->print_rect(foodX, foodY, 3);
    for (int i = 0; i < body.size(); i++){ // TESTNG
        this->print_rect(body[i].x, body[i].y, body[i].head);
    }

    SDL_UpdateWindowSurface(this->_Window);
}

void    SDL::print_rect(int x, int y, int head){
    SDL_Rect rect;
    int offset = 1;

    if (head == 0)
        this->_boxcolor = SDL_MapRGB(this->_screenSurface->format, 0, 0, 255);
    else if (head == 1)
        this->_boxcolor = SDL_MapRGB(this->_screenSurface->format, 0, 255, 0);
    else 
        this->_boxcolor = SDL_MapRGB(this->_screenSurface->format, 255, 0, 0);

    rect.w = this->_blockWidth;
    rect.h = this->_blockHeight;
    // change boxcolor accordingly
    rect.x = x * (this->_blockWidth + offset);
    rect.y = y * (this->_blockHeight + offset);
    SDL_FillRect(this->_screenSurface, &rect, this->_boxcolor);
}

SDL         *create(int height, int width) {
    return new SDL(height, width);
}

void        destroy(LibraryManager *lib) {
    delete (lib);
}