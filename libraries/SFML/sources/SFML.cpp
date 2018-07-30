#include "../includes/SFML.hpp"

SFML::SFML( int height, int width ) : _WindowHeight(height), _WindowWidth(width){
    std::cout << "SFML constructor called";
    this->init();
}

SFML::~SFML() {
    std::cout << "SFML destructor called";
}

void        SFML::init() {
    this->_Window.create(sf::VideoMode(this->_WindowWidth, this->_WindowHeight), "Nibbler", sf::Style::Close);
}

int         SFML::keyHook() {
    sf::Event event;
    while (this->_Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        this->_Window.close();
    }
    return (OTHER);
}
void        SFML::print(std::vector<segment>	body) {
    std::cout << "Head Value is" << body[0].x << std::endl;

    sf::RectangleShape rectangle(sf::Vector2f(10, 10));
    rectangle.setPosition(body[0].x, body[0].y);

    this->_Window.draw(rectangle);
    this->_Window.display();
}

SFML         *create(int height, int width) {
    return new SFML(height, width);
}

void        destroy(LibraryManager *lib) {
    delete (lib);
}