/*
** EPITECH PROJECT, 2024
** m3-3l2
** File description:
** Menu
*/

#include "Menu.hpp"
#include "Sprite.hpp"
#include <thread>

Menu::Menu(std::shared_ptr<sf::RenderWindow> window) : _window(window)
{
    this->background.putTexture("assets/Background.jpg");
    this->background._sprite.setPosition(0, 0);
    this->background._sprite.setScale(1.9, 1.1);
    this->play.putTexture("assets/Play.png");
    this->play._sprite.setPosition(650, 75);
    this->buffer.loadFromFile("assets/startup_sound.wav");
    this->startup_sound.setBuffer(buffer);
}

void Menu::ifButtonHooverd()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*this->_window);
    sf::Vector2f worldPos = this->_window->mapPixelToCoords(mousePos);
    if (this->play._sprite.getGlobalBounds().contains(worldPos)) {
        this->play._sprite.setColor(sf::Color::Red);
    } else {
        this->play._sprite.setColor(sf::Color::White);
    }
}

bool Menu::ifButtonClicked()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*this->_window);
        sf::Vector2f worldPos = this->_window->mapPixelToCoords(mousePos);
        if (this->play._sprite.getGlobalBounds().contains(worldPos)) {
            this->startup_sound.play();
            return true;
        }
    }
    return false;
}

void Menu::displayMenu()
{
    this->background.displaySprite(this->_window.get());
    this->play.displaySprite(this->_window.get());
}
