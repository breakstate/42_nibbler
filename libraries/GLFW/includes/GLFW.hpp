#include "../../LibraryManager.hpp"
#include <GLFW/glfw3.h>

#ifndef GLFW_HPP
#define GLFW_HPP

class Glfw : public LibraryManager {
	public:
		Glfw(int height, int width);
		virtual ~Glfw();

		void	init();
		int		keyHook();
		void	print(std::vector<segment> body, int foodX, int foodY);
	
	private:
		GLFWwindow		*_Window;
		int				_WindowHeight;
		int				_WindowWidth;
};

#endif // !OGL_HPP

#ifdef __cplusplus
extern "C" {
#endif

Glfw	*create(int height, int width);
void	destroy(LibraryManager *lib);

#ifdef __cplusplus
}
#endif