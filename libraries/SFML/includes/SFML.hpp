#include "../../LibraryManager.hpp"
# include <SFML/System.hpp>
# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>

#ifndef SFML_LIB
#define SFML_LIB

class SFML: public LibraryManager {
    public:
        SFML(int height, int width);
        virtual ~SFML();

        void        init();
        int         keyHook();
        void        print(std::vector<segment>	body, int foodX, int foodY);
    private:
        sf::RenderWindow    _Window;
        int                 _WindowHeight;
        int                 _WindowWidth;
};

#ifdef __cplusplus
extern "C" {
#endif

SFML         *create(int height, int width);
void        destroy(LibraryManager *lib);

#ifdef __cplusplus
}
#endif

#endif // !SFML_LIB
