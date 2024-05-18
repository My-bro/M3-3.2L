/*
** EPITECH PROJECT, 2024
** M3-3.2L [WSL: Ubuntu]
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


class Sprite {
    public:
        Sprite(std::string &path);
        Sprite() = default;
        void putTexture(const std::string &path);
        void displaySprite(sf::RenderWindow *window);
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Vector2f _origin;
    protected:
    private:
};

#endif /* !SPRITE_HPP_ */
