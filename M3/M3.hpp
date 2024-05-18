/*
** EPITECH PROJECT, 2024
** M3-3.2L [WSL: Ubuntu]
** File description:
** M3
*/

#ifndef M3_HPP_
#define M3_HPP_
#include <SFML/Graphics.hpp>
#include "Sprite.hpp"
#include <memory>
#include <cmath>

const float PI = 3.14159265;

class M3 {


    public:
        M3(std::shared_ptr<sf::RenderWindow> window);
        Sprite _Exhaust;
        Sprite _M3;

        void displayM3(std::shared_ptr<sf::RenderWindow> window);
        void rotateExhaust(std::shared_ptr<sf::RenderWindow> window);
    
    protected:
    private:
};

#endif /* !M3_HPP_ */
