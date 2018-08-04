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
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			return SWITCH_SDL;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			return SWITCH_SFML;
		// else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		// {
		// 	return QUIT;
		// }
	}
	return (OTHER);
}
void	SFML::print(std::vector<segment>	body, int foodX, int foodY) {
	std::cout << "Head Value is" << body[0].x << std::endl;

	this->_Window.clear(sf::Color::White);

	// background test
	sf::Texture texture;
	if (!texture.loadFromFile("doge.jpg", sf::IntRect(0, 0, 640, 640)))
	{
		std::cout << "NOPE" << std::endl;
	}
	texture.setRepeated(true);
	sf::Sprite background(texture);
	this->_Window.draw(background);
	// background test end

	this->print_rect(foodX, foodY, 3);

    for (int i = 0; i < static_cast<int>(body.size()); i++){ // TESTNG
        this->print_rect(body[i].x, body[i].y, body[i].head);
    }

	this->_Window.display();
}

void	SFML::print_rect(int x, int y, int colour){
	//sf::RectangleShape rect(sf::Vector2f(10, 10));
	sf::CircleShape rect(5, 4);
	if (colour == 0)
		rect.setFillColor(sf::Color::Blue);
	else if (colour == 1)
		rect.setFillColor(sf::Color::Green);
	else
		rect.setFillColor(sf::Color::Red);

	rect.setPosition(x * (10 + 1), y * (10 + 1));
	this->_Window.draw(rect);
}

SFML	*create(int height, int width) {
	return new SFML(height, width);
}

void	destroy(LibraryManager *lib) {
	delete (lib);
}