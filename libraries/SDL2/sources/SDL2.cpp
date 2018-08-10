#include "../includes/SDL2.hpp"
#include "../../../includes/Direction.hpp"
#include <iostream>

SDL::SDL(int width, int height) : _blockHeight(10), _blockWidth(10), _WindowHeight(height), _WindowWidth(width) {
	this->init();
}

SDL::SDL() {
}

SDL::~SDL() {
	SDL_DestroyWindow( this->getScreen() );
	SDL_Quit();
}

void		SDL::setScreen(SDL_Window *screen) { this->_Window = screen; }

SDL_Window  *SDL::getScreen() { return (this->_Window); }

void		SDL::init() {
	if (SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
		return ;
	}
	this->setScreen(SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,this->_WindowWidth,this->_WindowHeight, SDL_WINDOW_SHOWN));
	if (!this->getScreen()) {
	} else {
		this->_screenSurface = SDL_GetWindowSurface( this->getScreen() );
	}
	
}

int			SDL::keyHook()	{

	while (SDL_PollEvent(&_event))
	{
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
					case SDLK_SPACE: return PAUSE;
					case SDLK_1: return SWITCH_SDL;
					case SDLK_2: return SWITCH_SFML;
					case SDLK_3: return SWITCH_NCURSES;
					case SDLK_q: return QUIT;
				}
		}
	}
	return (OTHER);
}


void    SDL::print(std::vector<segment>	body, int foodX, int foodY) {
	this->_backgroundcolor = SDL_MapRGB(this->_screenSurface->format,61,49,117);

	SDL_FillRect(this->_screenSurface, NULL, this->_backgroundcolor);

	// code for drawing rects
	this->print_rect(foodX, foodY, 3);
	for (int i = 0; i < body.size(); i++){
		this->print_rect(body[i].x, body[i].y, body[i].head);
	}

	SDL_UpdateWindowSurface(this->_Window);
}

void		SDL::print_rect(int x, int y, int colour){
	SDL_Rect rect;
	int offset = 1;

	if (colour == 0)
		this->_boxcolor = SDL_MapRGB(this->_screenSurface->format,35, 24, 88);
	else if (colour == 1)
		this->_boxcolor = SDL_MapRGB(this->_screenSurface->format,17, 7, 59);
	else 
		this->_boxcolor = SDL_MapRGB(this->_screenSurface->format,134, 125, 176);

	rect.w = this->_blockWidth;
	rect.h = this->_blockHeight;
	// change boxcolor accordingly
	rect.x = x * (this->_blockWidth + offset);
	rect.y = y * (this->_blockHeight + offset);
	SDL_FillRect(this->_screenSurface, &rect, this->_boxcolor);
}


SDL			*create(int width, int height) {
	return new SDL(width, height);
}

void		destroy(LibraryManager *lib) {
	delete (lib);
}