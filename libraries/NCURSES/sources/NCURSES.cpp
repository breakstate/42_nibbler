#include "NCURSES.hpp"

NCURSES::NCURSES(){

}

NCURSES::~NCURSES(){
	std::cout << "deconstructing" << std::endl;
	//wrefresh(this->_Window);
	//delwin(this->_Window);
	refresh();
	endwin();
}


NCURSES::NCURSES( int height, int width ) : _WindowHeight(height), _WindowWidth(width){
	std::cout << "NCURSES constructor called";
	initscr();
	//cbreak(); // line buffering disabled
	keypad(stdscr, TRUE);
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(FALSE);
	raw();
	this->_Window = newwin(height, width, 0, 0);
	wrefresh(this->_Window);
}

int         NCURSES::keyHook(){
	int ch = 0;
	ch = getch();
			switch (ch) {
			case 'q':
				std::cout << "exiting" << std::endl;
				refresh();
				endwin();
				exit(1);
			case KEY_LEFT:
				mvprintw(5, 5, "left");
				std::cout << "left" << std::endl; // debug
				//return (LEFT); // uncomment
			case KEY_UP:
				std::cout << "up" << std::endl; // debug
				//return (UP); // uncomment
			case KEY_RIGHT:
				std::cout << "right" << std::endl; // debug
				//return (RIGHT); // uncomment
			case KEY_DOWN:
				std::cout << "down" << std::endl; // debug
				//return (DOWN); // uncomment
		}
//return (OTHER); // uncomment
return 1; // remove
}
void        NCURSES::print(std::vector<segment>	body, int foodX, int foodY){
	this->print_rect(foodX, foodY, 3);
	for (int i = 0; i < body.size(); i++){ // TESTNG
		this->print_rect(body[i].x, body[i].y, body[i].head);
	}
}

void        NCURSES::print_rect(int x, int y, int colour){
	mvaddch(x, y, 'o');
}