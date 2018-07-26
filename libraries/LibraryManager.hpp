#ifndef LIBRARYMANAGER_HPP
#define LIBRARYMANAGER_HPP

#include "../includes/Game.hpp"
#include "../includes/Snake.hpp"

#include "SDL2/SDL2/SDL.h"

class LibraryManager {
    public:
        virtual int keyHook() = 0;
        virtual void print() = 0;
        virtual ~LibraryManager(){};
};

#endif