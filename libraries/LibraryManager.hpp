#ifndef LIBRARYMANAGER_HPP
#define LIBRARYMANAGER_HPP

#include "../includes/Snake.hpp"

class LibraryManager {
    public:
        virtual int keyHook() = 0;
        virtual void print(std::vector<segment>	body, int foodX, int foodY) = 0;
        virtual ~LibraryManager(){};
};

typedef LibraryManager *createLib_t(int,int);
typedef void destroyLib_t(LibraryManager *lib);

#endif