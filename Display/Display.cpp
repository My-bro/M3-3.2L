/*
** EPITECH PROJECT, 2024
** M3-3.2L [WSL: Ubuntu]
** File description:
** Display
*/

#include "Display.hpp"

Display::Display(int width, int height, std::string title, int framerate, sf::Color color)
{
    this->_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title);
    this->_event = std::make_shared<sf::Event>();
    this->_window->setFramerateLimit(framerate);
    this->_window->clear(color);
    this->_clock = std::make_shared<sf::Clock>();
    this->_time = std::make_shared<sf::Time>();
}

