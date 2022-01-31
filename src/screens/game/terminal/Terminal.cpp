/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreenTerm
*/

#include <strings.h>

#include "Terminal.hpp"

namespace Screen::Game
{
Terminal::Terminal(): _upInput(false),  _backInput(false),
    _tInput(false), _enterInput(false), _isOpen(false),
    _typed('\0'), _currentInput("> "), _currentInputStock("> ")
{
    _layer.setSize(sf::Vector2f(1920, 1080));
    _layer.setPosition(sf::Vector2f(0, 0));
    _layer.setFillColor(sf::Color(0, 0, 0, 150));

    _text.setCharacterSize(25);

    _font.loadFromFile("assets/fontTerm.ttf");
    _text.setFont(_font);
}

void Terminal::resetCurrentInput()
{
    if (_currentInput.length() > 2) {
        _currentInputStock = _currentInput;
    }
    _currentInput = std::string("> ");
}

GameConstants::SCREEN_RETURN Terminal::eventUpdate(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T) {
        _tInput = true;
    }
    if (!isOpen()) {
        return (GameConstants::DO_NOTHING);
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        _enterInput = true;
    } else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter) {
        _enterInput = false;
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
        _upInput = true;
    } else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up) {
        _upInput = false;
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace) {
        _backInput = true;
    } else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::BackSpace) {
        _backInput = false;
    }

    if (event.type == sf::Event::TextEntered && _isOpen && !_backInput && !_enterInput) {
        _typed = event.text.unicode;
    }

    return (GameConstants::DO_NOTHING);
}

TERMINAL_RETURN Terminal::logicUpdate(__attribute__((unused)) sf::RenderWindow &window,
    bool &escapeInput)
{
    if (_tInput) {
        _isOpen = true;
        _tInput = false;
        return (CONTINUE);
    }
    if (_upInput) {
        _currentInput = _currentInputStock;
        _upInput = false;
        return (CONTINUE);
    }
    if (_backInput) {
        if (_currentInput.size() > 2) {
            _currentInput.erase(_currentInput.size() - 1, 1);
            _text.setString(_currentInput);
        }
        _backInput = false;
        return (CONTINUE);
    }
    if (_enterInput) {
        // _isTermSound = false;
        // if (!_isTermSound) {
            // _validSound.play();
            // _isEndTermSound = false;
        // }
        _isOpen = false;
        _enterInput = false;
        return (HANDLE_COMMANDS);
    }
    if (_isOpen && escapeInput) {
        _isOpen = false;
        escapeInput = false;
        resetCurrentInput();
        return (CONTINUE);
    }

    if (isalnum(_typed) || _typed == ' ') {
        // _typeSound.play();
        _currentInput += _typed;
        _typed = '\0';
    }
    Utils::setString(_currentInput, _text, sf::Vector2f(100, 150),
        sf::Color::Green);
    return (DO_NOTHING);
}

GameConstants::SCREEN_RETURN Terminal::drawUpdate(sf::RenderWindow &window)
{
    window.draw(_layer);
    window.draw(_text);
    return (GameConstants::DO_NOTHING);
}
}