/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** Utils
*/

#include "Utils.hpp"

void Utils::linkSpriteTexture(sf::Sprite &sprite, sf::Texture &texture, std::string const &asset)
{
  if (!texture.loadFromFile(asset)) {
      exit (84);
  }
  sprite.setTexture(texture);
}

void Utils::setString(const std::string &value, sf::Text &text,
    const sf::Vector2f &position, const sf::Color &color) {
    text.setString(value);
    text.setPosition(position);
    text.setFillColor(color);
}

bool Utils::isClockAtLimit(sf::Clock &clock, int limit)
{
    return (clock.getElapsedTime().asMilliseconds() >= limit);
}