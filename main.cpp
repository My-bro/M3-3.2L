/*
** EPITECH PROJECT, 2024
** M3-3.2L [WSL: Ubuntu]
** File description:
** main
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "M3.hpp"
#include "Display.hpp"
#include "Ball.hpp"




int main()
{
    Display display(1920, 1080, "M3 3.2L", 120, sf::Color::Black);
    M3 M3(display._window);
    Ball_Factory ball_factory;


    while (display._window->isOpen()) {
        while (display._window->pollEvent(*display._event)) {
            if (display._event->type == sf::Event::Closed) {
                display._window->close();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            std::shared_ptr<Ball> ball = std::make_shared<Ball>();
            ball->_ball.setRadius(10);
            ball->_ball.setFillColor(sf::Color::Green);
            ball->_current_position = {
                static_cast<float>(sf::Mouse::getPosition(*display._window).x), 
                static_cast<float>(sf::Mouse::getPosition(*display._window).y)
            };
            ball->_old_position = ball->_current_position;
            ball_factory._balls.push_back(ball);
        }

        M3.rotateExhaust(display._window);
        ball_factory.update(0.1);

        display._window->clear();
        M3.displayM3(display._window);
        ball_factory.drawBalls(display._window);
        
        display._window->display();
    }
    return 0;
}