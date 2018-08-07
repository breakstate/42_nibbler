#include "../includes/NCURSES.hpp"

#define HEAD 1
#define BODY 2
#define FOOD 3

NCURSES::NCURSES(){

}

NCURSES::~NCURSES(){
	std::cout << "deconstructing" << std::endl;
	wrefresh(this->_Window);
	delwin(this->_Window);
	refresh();
	endwin();
}


NCURSES::NCURSES( int width, int height ) : _WindowHeight(height/11), _WindowWidth(width/11){
	initscr();
	cbreak(); // line buffering disabled
	keypad(stdscr, TRUE);
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(FALSE);
	raw();

	start_color();
	init_pair(HEAD, COLOR_BLUE, COLOR_BLACK);
	init_pair(BODY, COLOR_GREEN, COLOR_BLACK);
	init_pair(FOOD, COLOR_RED, COLOR_BLACK);

	this->_Window = newwin(this->_WindowHeight, this->_WindowWidth * 2, 0, 0);
	wrefresh(this->_Window);
}

int			NCURSES::keyHook(){
	int ch = 0;
	ch = getch();
			switch (ch) {
			case 'q':
				refresh();
				endwin();
				exit(1);
			case KEY_LEFT:
				return (LEFT);
			case KEY_UP:
				return (UP);
			case KEY_RIGHT:
				return (RIGHT);
			case KEY_DOWN:
				return (DOWN); 
			case '1':
				return SWITCH_SDL;
			case '2':
				return SWITCH_SFML;
			case '3':
				return SWITCH_NCURSES;
		}
	return (OTHER);
}

void		NCURSES::print(std::vector<segment>	body, int foodX, int foodY){
	werase(this->_Window);
	box(this->_Window, 0, 0);
	this->print_rect(foodX, foodY, 2);
	for (int i = 0; i < body.size(); i++){
		this->print_rect(body[i].x, body[i].y, body[i].head);
	}
	wrefresh(this->_Window);
}

void		NCURSES::print_rect(int x, int y, int colour){
	std::string strx = std::to_string(x);
	std::string stry = std::to_string(y);
	std::string strco = strx + ";" + stry;
	switch (colour){
	case(0):
		wattron(this->_Window, COLOR_PAIR(BODY));
		mvwaddch(this->_Window, y, x*2, 'O');
		wattroff(this->_Window, COLOR_PAIR(BODY));
		break;
	case(1):
		wattron(this->_Window, COLOR_PAIR(HEAD));
		mvwaddch(this->_Window, y, x*2, 'X');
		wattroff(this->_Window, COLOR_PAIR(HEAD));
		break;
	case(2):
		wattron(this->_Window, COLOR_PAIR(FOOD));
		mvwaddch(this->_Window, y, x*2, '0');
		wattroff(this->_Window, COLOR_PAIR(FOOD));
		break;
	};
}

NCURSES		*create(int width, int height) {
	return new NCURSES(width, height);
}

void		destroy(LibraryManager *lib) {
	delete (lib);
}