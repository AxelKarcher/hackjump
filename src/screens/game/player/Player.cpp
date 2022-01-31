/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreenPlayer
*/

#include "Player.hpp"

namespace Screen::Game
{
Player::Player() : _velocity(0.5, 0.7)
{
    _texture.loadFromFile("assets/playerSheet.png");
    _rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(65, 144));
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(_rect);
    _sprite.setPosition(10, FLOOR_LEVEL - _rect.height);
}

GameConstants::SCREEN_RETURN Player::eventUpdate(const sf::Event &event)
{
    if ((event.type == sf::Event::KeyPressed
        && (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Q))) {
        _leftInput = true;
    } else if((event.type == sf::Event::KeyReleased
        && (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Q))) {
        _leftInput = false;
    }

    if ((event.type == sf::Event::KeyPressed
        && (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D))) {
        _rightInput = true;
    } else if((event.type == sf::Event::KeyReleased
        && (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D))) {
        _rightInput = false;
    }

    if ((event.type == sf::Event::KeyPressed
        && (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Z))) {
        _upInput = true;
    } else if((event.type == sf::Event::KeyReleased
        && (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Z))) {
        _upInput = false;
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Player::logicUpdate(__attribute__((unused)) sf::RenderWindow &window,
    struct map_s &map, Terminal &terminal)
{
    if (Utils::isClockAtLimit(_clock, 100)) {
        updateSprite(terminal);
        if (!terminal.isOpen()) {
            updateMovements(map);
        }
        _clock.restart();
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Player::displayUpdate(sf::RenderWindow &window)
{
    window.draw(_sprite);
    return (GameConstants::DO_NOTHING);
}
}