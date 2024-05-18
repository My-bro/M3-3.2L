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
    this->_Exhaust._sprite.setScale(0.08, 0.08);
    this->_Exhaust._sprite.rotate(30);

    sf::Vector2f m3Position = this->_M3._sprite.getPosition();

    float x2 = m3Position.x;
    float y2 = m3Position.y + spriteSize.height - spriteSize.height / 2 + 10;

    this->_Exhaust._sprite.setPosition(x2 + 20, y2 + 20);
}

void M3::displayM3(std::shared_ptr<sf::RenderWindow> window)
{
    this->_Exhaust.displaySprite(window.get());
    this->_M3.displaySprite(window.get());
}

void M3::rotateExhaust(std::shared_ptr<sf::RenderWindow> window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);
    float dx = worldPos.x - this->_Exhaust._sprite.getPosition().x;
    float dy = worldPos.y - this->_Exhaust._sprite.getPosition().y;
    float rotation = atan2(dy, dx) * 180 / PI;
    rotation += 180;
    if (rotation < 90 && rotation > 0) {
        this->_Exhaust._sprite.setRotation(rotation);
        sf::Vector2u size =this->_Exhaust._sprite.getTexture()->getSize();
        this->_Exhaust._sprite.setOrigin(size.x / 2, size.y / 2);
    }
}