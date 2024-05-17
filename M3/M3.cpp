/*
** EPITECH PROJECT, 2024
** M3-3.2L [WSL: Ubuntu]
** File description:
** M3
*/

#include "M3.hpp"

M3::M3(std::shared_ptr<sf::RenderWindow> window)
{
    this->_M3.putTexture("assets/M3_3,2L.png");
    this->_Exhaust.putTexture("assets/Exhaust.png");

    sf::Vector2u windowSize = window->getSize();
    sf::FloatRect spriteSize = this->_M3._sprite.getLocalBounds();

    float x = windowSize.x - spriteSize.width;
    float y = (windowSize.y / 2) - (spriteSize.height / 2);
    this->_M3._sprite.setPosition(x, y);
    this->_Exhaust._sprite.setScale(0.1, 0.1);
    this->_Exhaust._sprite.rotate(30);

    sf::Vector2f m3Position = this->_M3._sprite.getPosition();

    float x2 = m3Position.x;
    float y2 = m3Position.y + spriteSize.height - spriteSize.height / 2 + 10;

    this->_Exhaust._sprite.setPosition(x2, y2);
}

void M3::displayM3(std::shared_ptr<sf::RenderWindow> window)
{
    this->_M3.displaySprite(window.get());
    this->_Exhaust.displaySprite(window.get());
}