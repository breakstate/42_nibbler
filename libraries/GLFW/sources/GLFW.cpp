#include "../includes/GLFW.hpp"

Glfw::Glfw(int height, int width): _WindowHeight(height), _WindowWidth(width) {
	if (!glfwInit()) {
		std::cout << "Error" << std::endl;
		exit(0);
	}
	this->init();
}

Glfw::~Glfw() {

}

void	Glfw::init() {
	this->_Window = glfwCreateWindow(this->_WindowWidth, this->_WindowHeight, "Nibbler", NULL, NULL);
	if (!this->_Window) {
		glfwTerminate();
		exit(0);
	}
	glfwMakeContextCurrent(this->_Window);
}

int		Glfw::keyHook() {
	return (DOWN);
}

void	Glfw::print(std::vector<segment> body, int foodX, int foodY) {
	glViewport(0, 0, this->_WindowWidth, this->_WindowHeight);
	glEnd();
	glfwSwapBuffers(this->_Window);
}

Glfw		*create(int height, int width) {
	return new Glfw(height, width);
}

void	destroy(LibraryManager *lib) {
	delete (lib);
}
