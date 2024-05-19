/*
** EPITECH PROJECT, 2024
** M3-3.2L [WSL: Ubuntu]
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class Display {
    public:
        Display(int width, int height, std::string title, int framerate, sf::Color color);
        std::shared_ptr<sf::RenderWindow> _window;
        std::shared_ptr<sf::Event> _event;
        std::shared_ptr<sf::Clock> _clock;
        std::shared_ptr<sf::Time> _time;
        float _time_sep = 2.0f;
        bool launch_it = false;
    protected:
    private:
};

#endif /* !DISPLAY_HPP_ */
