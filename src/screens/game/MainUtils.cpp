/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreenUtils
*/

#include <strings.h>

#include "Main.hpp"

namespace Screen::Game
{
GameConstants::SCREEN_RETURN Main::terminalHandleCommands()
{
    const char *currentInput = _terminal.getCurrentInput().c_str();

    if (strcasecmp(currentInput + 2, "switch") == 0) {
        switchBlocks();
    } else if (strcasecmp(currentInput + 2, "quit") == 0
        || strcasecmp(currentInput + 2, "exit") == 0
        || strcasecmp(currentInput + 2, "rage quit") == 0 ) {
        return (GameConstants::EXIT_GAME);
    } else if (strcasecmp(currentInput + 2, "banana") == 0 && _currentMap == 9) {
        _isRainingBananas = true;
    } else if (strcasecmp(currentInput + 2, "reset") == 0) {
        _player.restartPlayer(_deathCount, _deathClock);
        _deathCount = 0;
        _currentMap = 0;
        _chronoClock.restart();
    } else if (strcasecmp(currentInput + 2, "restart") == 0) {
        _player.restartPlayer(_deathCount, _deathClock);
    }
    _terminal.resetCurrentInput();
    _terminal.setTermInputString(std::string(currentInput));
    return (GameConstants::DO_NOTHING);
}

void Main::switchBlocks()
{
    for (auto it = _maps[_currentMap].blocks.begin(); it != _maps[_currentMap].blocks.end(); it++) {
        switch(it->get()->getColor()) {
            case RED:
                it->get()->changeMode(N_RED);
                break;
            case N_RED:
                it->get()->changeMode(RED);
                break;
            case BLUE:
                it->get()->changeMode(N_BLUE);
                break;
            case N_BLUE:
                it->get()->changeMode(BLUE);
                break;
            default:
                break;
        }
    }
}

GameConstants::SCREEN_RETURN Main::handleMapSwitch()
{
    if (_player.getPosition().x < -30) {
        if (_currentMap == 0) {
            printf("\n--- À demain ---\n\n");
            return (GameConstants::EXIT_GAME);
        } else {
            _currentMap -= 1;
            _player.setPosition(1920, _player.getPosition().y);
        }
    } else if (_player.getPosition().x > 1950 && _currentMap < NB_MAPS - 1) {
        _player.setPosition(0, _player.getPosition().y);
        _currentMap += 1;
    } else if (_player.getPosition().x > 1920 - _player.getSize().x
        && _currentMap == NB_MAPS - 1) {
        _player.setPosition(1920 - _player.getSize().x, _player.getPosition().y);
    }
    return (GameConstants::DO_NOTHING);
}

std::string Main::getChronoFormat(float sec)
{
    int s = int(sec);
    std::string minutes = "00";
    std::string separator = ":";
    std::string secondes = "00";

    if (s == 0)
        return ("--:--");

    if (sec < 60) {
        secondes = std::to_string(s);
        if (s < 10)
            secondes = "0" + secondes;
    } else {
        minutes = std::to_string(s / 60);
        secondes = std::to_string(s % 60);
        if (s % 60 < 10)
            secondes = "0" + secondes;
    }

    return (minutes + separator + secondes);
}

bool Main::doOverlap(sf::Vector2f l1, sf::Vector2f r1, sf::Vector2f l2, sf::Vector2f r2)
{
    if (l1.x == r1.x || l1.y == r2.y || l2.x == r2.x
        || l2.y == r2.y) {
        return false;
    }
    if (l1.x >= r2.x || l2.x >= r1.x) {
        return false;
    }
    if (l1.y >= r2.y || l2.y >= r1.y) {
        return false;
    }
    return true;
}

bool Main::checkHitboxes()
{
    sf::Vector2f l1(_player.getPosition());
    sf::Vector2f r1(_player.getPosition().x + _player.getSize().x,
        _player.getPosition().y + _player.getSize().y);

    for (auto it = _maps[_currentMap].blocks.begin(); it !=
        _maps[_currentMap].blocks.end(); it++) {
        if (!it->get()->getActive()) {
            continue;
        }
        sf::Vector2f l2(it->get()->getPosition());
        sf::Vector2f r2(it->get()->getPosition() + it->get()->getSize());
        if (doOverlap(l1, r1, l2, r2)) {
            return (false);
        }
    }
    return (true);
}
}