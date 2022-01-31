/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreenPause
*/

#ifndef GAMESCREENPAUSE_HPP_
#define GAMESCREENPAUSE_HPP_

#include <SFML/Graphics.hpp>

#include "GameConstants.hpp"
#include "Utils.hpp"

namespace Screen::Game
{
class Pause
{
    public:
        Pause();
        ~Pause() = default;

        GameConstants::SCREEN_RETURN eventUpdate(const sf::Event &event);
        GameConstants::SCREEN_RETURN logicUpdate(sf::RenderWindow &window, bool &escapeInput);
        GameConstants::SCREEN_RETURN drawUpdate(sf::RenderWindow &window);

        bool isOpen() { return _isOpen; };
        void open();
        void close();

    private:
        bool                _isOpen;
        bool                _mouseLeftInput;

        sf::Event           _event;

        sf::Clock           _clock;

        sf::RectangleShape  _blackSquare;
        sf::Vector2i        _mousePos;


        sf::Texture         _continueButtonTexture;
        sf::Sprite          _continueButtonSprite;

        sf::Texture         _returnMenuTexture;
        sf::Sprite          _returnMenuSprite;

        sf::Texture         _quitButtonTexture;
        sf::Sprite          _quitButtonSprite;
};
};

#endif /* !GAMESCREENPAUSE_HPP_ */