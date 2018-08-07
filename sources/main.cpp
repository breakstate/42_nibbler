#include "../includes/Game.hpp"

int main(int argc, char** argv){
	try {
		if (argc >= 2) {
			Game game(std::stoi(argv[1]), std::stoi(argv[2]));
			game.gameloop();
		} else {
			std::cout << "Usage: ./nibbler [width] [height]" << std::endl;
		}
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}