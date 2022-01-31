/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreenPlayer
*/

#ifndef GAMESCREENPLAYER_HPP_
#define GAMESCREENPLAYER_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameConstants.hpp"
#include "Utils.hpp"

#include "../maps.hpp"
#include "../terminal/Terminal.hpp"

namespace Screen::Game
{
#define NB_MAPS 10 // TODO - TO DELETE BECAUSE ITS ALREADY IN GAMESCREEN

class Player {
    public:
        Player();
        ~Player() = default;

        GameConstants::SCREEN_RETURN eventUpdate(const sf::Event &event);
        GameConstants::SCREEN_RETURN logicUpdate(sf::RenderWindow &window,
            struct map_s &map, Terminal &terminal);
        GameConstants::SCREEN_RETURN displayUpdate(sf::RenderWindow &window);

        void updateSprite(Terminal &terminal);
        void updateMovements(struct map_s &map);
        void animPlayer();
        void jump();
        void restartPlayer(int &deathCount, sf::Clock &deathClock);

        sf::Vector2f getPosition() { return (sf::Vector2f(_sprite.getPosition().x,
            _sprite.getPosition().y)); };
        sf::Vector2i getSize() { return (sf::Vector2i(_rect.width,
            _rect.height)); };

        void setPosition(sf::Vector2f newPos) { _sprite.setPosition(newPos); };
        void setPosition(float x, float y) { _sprite.setPosition(sf::Vector2f(x, y)); };

    private:
        const size_t FLOOR_LEVEL = 850;
        const unsigned char GRAVITY = 15;
        bool canGoDown(struct map_s &map);
        void jumpManagement();

        sf::Event       _event;
        sf::Clock       _clock;

        // Player
        sf::Sprite      _sprite;
        sf::Texture     _texture;
        sf::IntRect     _rect;

        // Moving
        bool            _rightInput;
        bool            _leftInput;

        // Jumping
        sf::Vector2f    _velocity;
        int             _jumpHigh;
        bool            _hasJump;
        bool            _upInput;
};
};

#endif /* !GAMESCREENPLAYER_HPP_ */
