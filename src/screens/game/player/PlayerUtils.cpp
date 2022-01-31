/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** PlayerUtils
*/

#include "Player.hpp"

namespace Screen::Game
{
void Player::updateSprite(Terminal &terminal)
{
    if (terminal.isOpen()) {
        if (_rect.top == 144) {
            _rect.top = 432;
        } else if (_rect.top == 0) {
            _rect.top = 288;
        }
    } else {
        if (_rect.top == 432) {
            _rect.top = 144;
        } else if (_rect.top == 288) {
            _rect.top = 0;
        }
    }
    if (_rect.left >= 325) {
        _rect.left = 0;
    } else {
        _rect.left += 65;
    }
    _sprite.setTextureRect(_rect);
}

void Player::updateMovements(struct map_s &map)
{
    // Gravity & get the jump back
    if (canGoDown(map)) {
        if (_sprite.getPosition().y + _rect.height + GRAVITY >= FLOOR_LEVEL) {
            _sprite.setPosition(_sprite.getPosition().x,
                FLOOR_LEVEL - _rect.height);
        } else {
            _sprite.setPosition(_sprite.getPosition().x,
                _sprite.getPosition().y + GRAVITY);
        }
    }

    // Moving on x
    if (_leftInput) {
        _sprite.setPosition(_sprite.getPosition().x - 15,
            _sprite.getPosition().y);
        _rect.top = 144;
    }
    if (_rightInput) {
        _sprite.setPosition(_sprite.getPosition().x + 15,
            _sprite.getPosition().y);
        _rect.top = 0;
    }

    // Jumping
    if (_upInput) {
        if (!_hasJump) {
            _hasJump = true;
        }
        _upInput = false;
    }
    if (_hasJump) {
        jumpManagement();
    }

}

void Player::restartPlayer(int &deathCount, sf::Clock &deathClock)
{
    deathCount += 1;
    deathClock.restart();
    _sprite.setPosition(20, FLOOR_LEVEL - _rect.height);
}

bool Player::canGoDown(struct map_s &map)
{
    sf::Vector2f l1(_sprite.getPosition());
    sf::Vector2f r1(_sprite.getPosition().x + _rect.width,
        _sprite.getPosition().y + _rect.height);

    for (auto it = map.blocks.begin(); it !=
        map.blocks.end(); it++) {
        if (!it->get()->getActive()) {
            continue;
        }
        sf::Vector2f l2(it->get()->getPosition());
        sf::Vector2f r2(it->get()->getPosition() + it->get()->getSize());
        if (l1.x < r2.x && l2.x < r1.x) {
            size_t future_y = _sprite.getPosition().y + _rect.height + 25;
            if (future_y > it->get()->getPosition().y + it->get()->getSize().y) {
                continue;
            }
            if (future_y > it->get()->getPosition().y &&
                future_y < it->get()->getPosition().y + it->get()->getSize().y) {
                _sprite.setPosition(
                    _sprite.getPosition().x,
                    it->get()->getPosition().y - _rect.height - 1
                );
                return (false);
            }
            return (!(_sprite.getPosition().y +
                _rect.height + 25 > it->get()->getPosition().y));
        }
    }
    return (_sprite.getPosition().y + _rect.height < 850);
}

void Player::jumpManagement()
{
    _sprite.setPosition(_sprite.getPosition().x * (_velocity.x * 0.1),
        _sprite.getPosition().y * (_velocity.y * 0.1));
    _velocity.x += 0.1 * GRAVITY;
    _velocity.y += 0.1 * GRAVITY;
}
}