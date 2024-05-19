/*
** EPITECH PROJECT, 2024
** M3-3.2L [WSL: Ubuntu]
** File description:
** Ball
*/

#ifndef BALL_HPP_
#define BALL_HPP_
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>


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
        Ball_Factory();
        ~Ball_Factory() = default;
        std::vector<std::shared_ptr<Ball>> _balls;
        sf::Vector2f _gravity = {0, 80};
        sf::SoundBuffer explosion_buffer;
        sf::Sound explosion;
        sf::SoundBuffer end_explosion_buffer;
        sf::Sound end_explosion;
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

        void collision(); //{
        //     int nb_balls = _balls.size();
        //     for (int i = 0; i < nb_balls; i++) {
        //         std::shared_ptr<Ball> ball = _balls[i];
        //         for (int j = i + 1; j < nb_balls; j++) {
        //             std::shared_ptr<Ball> other_ball = _balls[j];
        //             sf::Vector2f collision_axis = ball->_current_position - other_ball->_current_position;
        //             float distance = sqrt(pow(collision_axis.x, 2) + pow(collision_axis.y, 2));
        //             if (distance < 20) {
        //                 collision_axis = collision_axis / distance;
        //                 sf::Vector2f relative_velocity = ball->_current_position - other_ball->_current_position;
        //                 float velocity_along_axis = relative_velocity.x * collision_axis.x + relative_velocity.y * collision_axis.y;
        //                 if (velocity_along_axis > 0) {
        //                     float e = 1;
        //                     float j = -(1 + e) * velocity_along_axis;
        //                     j /= 1 / 1 + 1 / 1;
        //                     sf::Vector2f impulse = j * collision_axis;
        //                     ball->_current_position += impulse;
        //                     other_ball->_current_position -= impulse;
        //                 }
        //             }
        //         }
        //     }
        // }

        void createBallIfMousePressed(const sf::Sprite& M3_Exhaust);

        void drawBalls(std::shared_ptr<sf::RenderWindow> _window) {
            for (auto &ball : _balls) {
                _window->draw(ball->_ball);
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
