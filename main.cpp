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
#include "Menu.hpp"



int score = 0;

int main()
{
    Display display(1920, 1080, "M3 3.2L", 60, sf::Color::Black);
    M3 M3(display._window);
    Ball_Factory exhaust_projectile;
    Menu menu(display._window);
    Ball_Factory ball_factory;

    while (display._window->isOpen()) {
        while (display._window->pollEvent(*display._event)) {
            if (display._event->type == sf::Event::Closed) {
                display._window->close();
            }
        }
        menu.ifButtonHooverd();
        if (menu.ifButtonClicked()) {
            break;
        }
        menu.displayMenu();
        display._window->display();
    }

    while (display._window->isOpen()) {
        
        if (display._time2->asSeconds() > 60) {
            display._window->close();
            break;

        }
            

        display._time = std::make_shared<sf::Time>(display._clock->getElapsedTime());
        if (display._time->asSeconds() > display._time_sep) {
            display._clock->restart();
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
        M3.playTheme();
        exhaust_projectile.drawBalls(display._window);
        exhaust_projectile.destroyBallsIfTooFar();
        display._window->display();
        display.launch_it = false;
    }
    std::cout << "Score: " << score << std::endl;
    return 0;
}
