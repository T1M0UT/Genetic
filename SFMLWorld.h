//
// Created by Тимур Краснянский on 11.04.2022.
//

#ifndef GENETIC_SFMLWORLD_H
#define GENETIC_SFMLWORLD_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "World.h"
#include <iterator>
#include <list>
using namespace std;

namespace SFMLGame {
    class SFMLWorld : public World {
    public:
        explicit SFMLWorld(sf::RenderWindow &window);

        void draw() override;

    private:
        sf::RenderWindow &_window;
        list<int> entities;
        int scale;
    };
}


#endif //GENETIC_SFMLWORLD_H
