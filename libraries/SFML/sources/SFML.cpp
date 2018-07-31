#include "../includes/SFML.hpp"

SFML::SFML( int height, int width ) : _WindowHeight(height), _WindowWidth(width){
	std::cout << "SFML constructor called";
	this->init();
}

SFML::~SFML() {
	std::cout << "SFML destructor called";
}

void	SFML::init() {
	this->_Window.create(sf::VideoMode(this->_WindowWidth, this->_WindowHeight), "Nibbler", sf::Style::Close);
}

int		SFML::keyHook() {
	sf::Event event;
	while (this->_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed){
			this->_Window.close();
			exit(0);
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			return LEFT;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			return RIGHT;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			return UP;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			return DOWN;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			return SWITCH_LIB;
		// else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		// {
		//     // quit...
		// }
	}
	return (OTHER);
}
void	SFML::print(std::vector<segment>	body, int foodX, int foodY) {
	std::cout << "Head Value is" << body[0].x << std::endl;

	sf::RectangleShape rectangle(sf::Vector2f(10, 10));
	rectangle.setPosition(body[0].x, body[0].y);

	foodX = 0;
	foodY = 0;

	this->_Window.draw(rectangle);
	this->_Window.display();

	// clear the window with black color
	this->_Window.clear(sf::Color::Black);

	// draw everything here...
	// window.draw(...);

	// end the current frame
	this->_Window.display();
}

SFML	*create(int height, int width) {
	return new SFML(height, width);
}

void	destroy(LibraryManager *lib) {
	delete (lib);
}