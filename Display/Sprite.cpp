/*
** EPITECH PROJECT, 2024
** M3-3.2L [WSL: Ubuntu]
** File description:
** Display
*/

#include "Sprite.hpp"

Sprite::Sprite(std::string &path)
{
    this->_texture.loadFromFile(path);
    this->_sprite.setTexture(this->_texture);
}

void Sprite::putTexture(const std::string &path)
{
    this->_texture.loadFromFile(path);
    this->_sprite.setTexture(this->_texture);
}

void Sprite::displaySprite(sf::RenderWindow *window)
{
    window->draw(this->_sprite);
}
