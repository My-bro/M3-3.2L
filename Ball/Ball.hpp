/*
** EPITECH PROJECT, 2024
** M3-3.2L [WSL: Ubuntu]
** File description:
** Ball
*/

#ifndef BALL_HPP_
#define BALL_HPP_
#include "SFML/Graphics.hpp"
#include "Display.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <random>



enum class BallType {
    EXHAUST = 0,
    ALLUMETTE = 1
};

class Ball {
    public:
        
        Ball() = default;
        // ~Ball();
        sf::CircleShape _ball;
        sf::Vector2f _current_position;
        sf::Vector2f _old_position;
        sf::Vector2f _acceleration;
        BallType _type;
        bool _is_touched = false;

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
        sf::Vector2f _gravity = {0, 80};

        void update(float deltaTime) {
            applyGravity();
            updatePosition(deltaTime);
            collision();
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

        void collision();

        void createBallIfMousePressed(const sf::Sprite& M3_Exhaust);
        void allumette_handling(Display _display);

        void drawBalls(std::shared_ptr<sf::RenderWindow> _window) {
            for (auto &ball : _balls) {
                sf::Vector2f ball_position = ball->_ball.getPosition();
                int size = 30;
                if (ball->_type == BallType::EXHAUST) {
                    for (int i = 0; i < size; i++) {
                        sf::CircleShape circle(i);
                        float t = static_cast<float>(i) / size;
                        sf::Color color;
                        if (t < 0.1f) {
                            color.r = 255;
                            color.g = 255;
                            color.b = 255 - t * 10 * 255;
                        } else if (t < 0.5f) {
                            color.r = 255;
                            color.g = 255 - (t - 0.1f) * 2.857 * (255 - 165);
                            color.b = 0;
                        } else {
                            color.r = 255;
                            color.g = 165 - (t - 0.5f) * 2 * 165;
                            color.b = 0;
                        }
                        color.a = 255 - t * 255;

                        circle.setFillColor(color);
                        circle.setPosition(ball_position.x - i/2, ball_position.y - i/2);
                        _window->draw(circle);
                    }
                }
                if (ball->_type == BallType::ALLUMETTE) {
                    _window->draw(ball->_ball);
                }
            }
        }

        void destroyBallsIfTooFar() {
            for (auto it = _balls.begin(); it != _balls.end();) {
                if (((*it)->_current_position.y > 1080) || ((*it)->_current_position.x > 1920) || ((*it)->_current_position.x < 0) || ((*it)->_current_position.y < 0)) {
                    it = _balls.erase(it);
                } else {
                    ++it;
                }
            }
        }
    protected:
    private:
};

#endif /* !BALL_HPP_ */
