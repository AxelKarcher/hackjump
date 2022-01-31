/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreenTerm
*/

#ifndef GAMESCREENTERM_HPP_
#define GAMESCREENTERM_HPP_

#include <SFML/Graphics.hpp>

#include "GameConstants.hpp"
#include "Utils.hpp"

namespace Screen::Game
{
enum TERMINAL_RETURN {
    CONTINUE,
    HANDLE_COMMANDS,
    DO_NOTHING
};

class Terminal
{
    public:
        Terminal();
        ~Terminal() = default;

        GameConstants::SCREEN_RETURN eventUpdate(const sf::Event &event);
        TERMINAL_RETURN logicUpdate(sf::RenderWindow &window, bool &escapeInput);
        GameConstants::SCREEN_RETURN drawUpdate(sf::RenderWindow &window);

        void resetCurrentInput();
        void setTermInputString(const std::string &str) { _text.setString(str); };
        std::string getCurrentInput() { return (_currentInput); };
        bool isOpen() { return (_isOpen); };

    private:
        bool                _upInput;
        bool                _backInput;
        bool                _tInput;
        bool                _enterInput;
        bool                _isOpen;

        char                _typed;

        std::string         _currentInput;
        std::string         _currentInputStock;

        sf::Clock           _clock;
        sf::RectangleShape  _layer;

        sf::Text            _text;
        sf::Font            _font;

};
};

#endif /* !GAMESCREENTERM_HPP_ */