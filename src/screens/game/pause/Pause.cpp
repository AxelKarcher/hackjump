/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreenPause
*/

#include "Pause.hpp"

namespace Screen::Game
{
//TODO
// void Main::setVolume(float volume)
// {
//     _volume = volume;
//     _gameMusic->setVolume(volume);
//     _termSound.setVolume(volume);
//     _typeSound.setVolume(volume);
//     _validSound.setVolume(volume);
// }

Pause::Pause() : _isOpen(false), _mouseLeftInput(false), _mousePos(0, 0)
{
    Utils::linkSpriteTexture(_continueButtonSprite, _continueButtonTexture,
        "assets/buttonContinue.jpg");
    _continueButtonSprite.setPosition(sf::Vector2f(800, 450));
    Utils::linkSpriteTexture(_returnMenuSprite, _returnMenuTexture,
        "assets/buttonMenu.jpg");
    _returnMenuSprite.setPosition(sf::Vector2f(800, 600));
    Utils::linkSpriteTexture(_quitButtonSprite, _quitButtonTexture,
        "assets/buttonQuit.jpg");
    _quitButtonSprite.setPosition(sf::Vector2f(800, 750));
}

void Pause::open()
{
    _isOpen = true;
}

void Pause::close()
{
    _isOpen = false;
    _clock.restart();
}

GameConstants::SCREEN_RETURN Pause::eventUpdate(const sf::Event &event)
{
    _mousePos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        _mouseLeftInput = true;
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Pause::logicUpdate(__attribute__((unused)) sf::RenderWindow &window,
    bool &escapeInput)
{
    if (Utils::isClockAtLimit(_clock, 200)) {
        if (isOpen()) {
            if (_mouseLeftInput && _mousePos.x >= 800 &&
                _mousePos.x <= 1100 && _mousePos.y >= 450 && _mousePos.y <= 550) {
                _isOpen = false;
                return (GameConstants::DO_NOTHING);
            }
            if (_mouseLeftInput && _mousePos.x >= 800 &&
                _mousePos.x <= 1100 && _mousePos.y >= 600 && _mousePos.y <= 700) {
                _isOpen = false;
             /* _gameMusic->pause(); SHOULD PAUSE THE GAME MUSIC
                    USING A METHOD IN GAME OR A CUSTOM INGAME RETURN VALUE */
                return (GameConstants::CHANGE_TO_MENU);
            }
            if (_mouseLeftInput && _mousePos.x >= 800 &&
                _mousePos.x <= 1100 && _mousePos.y >= 750 && _mousePos.y <= 950) {
                _isOpen = false;
                return (GameConstants::EXIT_GAME);
            }
            if (_mouseLeftInput) {
                _mouseLeftInput = false;
            }
        }
        if (_isOpen && escapeInput) {
           escapeInput = false;
            _isOpen = false;
        } else if (!_isOpen && escapeInput) {
            escapeInput = false;
            _isOpen = true;
        }
        _clock.restart();
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Pause::drawUpdate(sf::RenderWindow &window)
{
    window.draw(_quitButtonSprite);
    window.draw(_continueButtonSprite);
    window.draw(_returnMenuSprite);
    return (GameConstants::DO_NOTHING);
}
}