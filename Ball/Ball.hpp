/*
** EPITECH PROJECT, 2024
** M3-3.2L [WSL: Ubuntu]
** File description:
** Ball
*/

#ifndef BALL_HPP_
#define BALL_HPP_
#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>
#include <memory>



class Ball {
    public:
        
        Ball() = default;
        // ~Ball();
        sf::CircleShape _ball;
        sf::Vector2f _current_position;
        sf::Vector2f _old_position;
        sf::Vector2f _acceleration;

        void updatePosition(float deltaTime) {
            sf::Vector2f velocity = _current_position - _old_position;
            _old_position = _current_position;
            _current_position = _current_position + velocity + _acceleration * deltaTime * deltaTime;
            _acceleration = {0, 0};
            this->_ball.setPosition(_current_position);   
        }
        void acceleration(sf::Vector2f acceleration) {
            _acceleration += acceleration;
        }
    protected:
    private:
};

class Ball_Factory {
    public:
        Ball_Factory() = default;
        ~Ball_Factory() = default;
        std::vector<std::shared_ptr<Ball>> _balls;
        sf::Vector2f _gravity = {0, 10};

        void update(float deltaTime) {
            applyGravity();
            updatePosition(deltaTime);
        }
        
        void applyGravity(void) {
            for (auto &ball : _balls) {
                ball->acceleration(_gravity);
            }
        }

        void updatePosition(float deltaTime) {
            for (auto &ball : _balls) {
                ball->updatePosition(deltaTime);
            }
        }

        void drawBalls(std::shared_ptr<sf::RenderWindow> _window) {
            for (auto &ball : _balls) {
                _window->draw(ball->_ball);
            }
        }

    protected:
    private:
};

#endif /* !BALL_HPP_ */
