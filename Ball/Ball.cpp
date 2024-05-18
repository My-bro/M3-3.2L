/*
** EPITECH PROJECT, 2024
** M3-3.2L [WSL: Ubuntu]
** File description:
** Ball
*/

#include "Ball.hpp"

void Ball_Factory::collision()
{
    int nb_balls = _balls.size();
    for (int i = 0; i < nb_balls; i++) {
        std::shared_ptr<Ball> ball = _balls[i];
        for (int j = i + 1; j < nb_balls; j++) {
            std::shared_ptr<Ball> other_ball = _balls[j];
            sf::Vector2f collision_axis = ball->_current_position - other_ball->_current_position;
            float distance = sqrt(pow(collision_axis.x, 2) + pow(collision_axis.y, 2));
            if (distance < 20) {
                collision_axis = collision_axis / distance;
                sf::Vector2f relative_velocity = ball->_current_position - other_ball->_current_position;
                float velocity_along_axis = relative_velocity.x * collision_axis.x + relative_velocity.y * collision_axis.y;
                if (velocity_along_axis > 0) {
                    float e = 1;
                    float j = -(1 + e) * velocity_along_axis;
                    j /= 1 / 1 + 1 / 1;
                    sf::Vector2f impulse = j * collision_axis;
                    ball->_current_position += impulse;
                    other_ball->_current_position -= impulse;
                }
            }
        }
    }
}


void Ball_Factory::createBallIfMousePressed(const sf::Sprite& M3_Exhaust)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::shared_ptr<Ball> ball = std::make_shared<Ball>();
        ball->_ball.setRadius(10);
        ball->_ball.setFillColor(sf::Color::White);
        
        float n = 40.0; // DISTANCE
        float exhaust_rotation = M3_Exhaust.getRotation() + 180.0f;
        sf::Vector2f exhaust_position = M3_Exhaust.getPosition();
        float exhaust_rotation_rad = exhaust_rotation * M_PI / 180.0f;
        ball->_current_position = {
            static_cast<float>(exhaust_position.x + n * cos(exhaust_rotation_rad)),
            static_cast<float>(exhaust_position.y + n * sin(exhaust_rotation_rad))
        };
        ball->_old_position = M3_Exhaust.getPosition();
        _balls.push_back(ball);
    }
}
