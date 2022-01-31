/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** Utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <SFML/Graphics.hpp>

class Utils {
  public:
    Utils() = default;
    ~Utils() = default;

    /**
     * @brief link a sprite to a texture
     * linkSpriteTexture
     * @param sprite the sprite to link
     * @param texture the texture to be linked by a sprite
     * @param asset path to the texture file
     */
    static void linkSpriteTexture(sf::Sprite &sprite, sf::Texture &texture, std::string const &asset);

    /**
     * @brief check if clock is at limit
     * isClockAtLimit
     * @param clock the clock
     * @param limit the limit to check in miliseconds
     * @return true if clock is at limit
     * @return false if clock isn't at limit
     */
    static bool isClockAtLimit(sf::Clock &clock, int limit);

    /**
     * @brief set a string into an sf::Text
     * setString
     * @param value the string
     * @param text the sf::Text
     * @param position the position where to set the text
     * @param color the color of the text
     */
    static void setString(const std::string &value, sf::Text &text,
      const sf::Vector2f &position, const sf::Color &color);
};

#endif /* !UTILS_HPP_ */
