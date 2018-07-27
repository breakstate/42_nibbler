#include "../includes/SFML.hpp"

SFML::SFML( int height, int width ) {
    std::cout << "SFML constructor called";
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
}

SFML::~SFML() {
    std::cout << "SFML destructor called";
}

void        SFML::init() {

}

int         SFML::keyHook() {
    return 1;
}
void        SFML::print(std::vector<segment>	body) {

}

SFML         *create(int height, int width) {
    return new SFML(height, width);
}

void        destroy(LibraryManager *lib) {
    delete (lib);
}