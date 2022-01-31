/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** InitGameScreen
*/

#include "Main.hpp"

namespace Screen::Game
{
void Main::initInputs()
{
    _leftInput = false;
    _rightInput = false;
    _upInput = false;
    _escapeInput = false;
    _calledOnce = false;

    _hasJump = false;
    _jumpHigh = 0;
    _deathCount = 0;
}

void Main::initMaps()
{
    _currentMap = 0;
    for (size_t i = 0; i < NB_MAPS; ++i) {
        (this->*mapFuncs[i])(_maps[i]);
    }
}

void Main::initBackground()
{
    _backgroundRect = sf::IntRect(sf::Vector2i(0, 200),
        sf::Vector2i(1200, 1080));
    _background.loadFromFile("assets/matrixBackground.png");
    _sBackground.setTexture(_background);
    _sBackground.setColor(sf::Color(_sBackground.getColor().r,
        _sBackground.getColor().g, _sBackground.getColor().b, 100));
    _sBackground.setScale(sf::Vector2f(1.6, 1.6));
    _sBackground.setTextureRect(_backgroundRect);
    _currentBackground = 0;
    _bgClock.restart();
}
}