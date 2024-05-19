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
    Display display(1920, 1080, "M3 3.2L", 60, sf::Color::Black);
    M3 M3(display._window);
    Ball_Factory exhaust_projectile;

    while (display._window->isOpen()) {
        
        display._time = std::make_shared<sf::Time>(display._clock->getElapsedTime());
        if (display._time->asSeconds() > display._time_sep) {
            display._clock->restart();
            std::cout << "FPS: " << 1 / display._time->asSeconds() << std::endl;
            display._time_sep -= 0.01f;
            display.launch_it = true;
        }

        while (display._window->pollEvent(*display._event)) {
            if (display._event->type == sf::Event::Closed) {
                display._window->close();
            }
        }
        exhaust_projectile.createBallIfMousePressed(M3._Exhaust._sprite);
        exhaust_projectile.allumette_handling(display);

        M3.rotateExhaust(display._window);
        exhaust_projectile.update(0.1);

        // std::cout << "x: " << sf::Mouse::getPosition(*display._window).x << " y: " << sf::Mouse::getPosition(*display._window).y << std::endl;

        display._window->clear();
        M3.displayM3(display._window);
        exhaust_projectile.drawBalls(display._window);
        exhaust_projectile.destroyBallsIfTooFar();
        display._window->display();
        display.launch_it = false;
    }
    return 0;
}
