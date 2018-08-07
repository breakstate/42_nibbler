#include "../includes/Game.hpp"

int main(int argc, char** argv){
	Game game(std::stoi(argv[1]), std::stoi(argv[2]));
	game.gameloop();
}