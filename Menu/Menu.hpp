/*
** EPITECH PROJECT, 2024
** m3-3l2
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_
    #include "SFML/Graphics.hpp"
    #include "Sprite.hpp"
    #include <memory>
    #include <SFML/Audio.hpp>

class Menu {
    public:
        Menu(std::shared_ptr<sf::RenderWindow> window);
        void ifButtonHooverd();
        bool ifButtonClicked();
        void displayMenu();
    protected:
    private:
        std::shared_ptr<sf::RenderWindow> _window;
        Sprite play;
        Sprite background;
        sf::SoundBuffer buffer;
        sf::Sound startup_sound;
};

#endif /* !MENU_HPP_ */
