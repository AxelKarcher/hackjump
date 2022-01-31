/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** CreditsScreen
*/

#include "ISCreen.hpp"

#ifndef CREDITSSCREEN_HPP_
#define CREDITSSCREEN_HPP_

namespace Screen::Credits
{
#define ARRAYLEN(array)     (sizeof(array)/sizeof((array)[0]))

class Main : public ISCreen {
  public:
    Main();
    ~Main() = default;

    GameConstants::SCREEN_RETURN eventUpdate(sf::RenderWindow &window) override;
    GameConstants::SCREEN_RETURN logicUpdate(sf::RenderWindow &window) override;
    GameConstants::SCREEN_RETURN displayUpdate(sf::RenderWindow &window) override;

    void initText(sf::Text &text, const sf::Font &font, const size_t &size);

  private:
    void setString(const std::string &value, sf::Text &text,
        const sf::Vector2f &position, const sf::Color &color);
    sf::Color getColorDependingOnLevel(size_t y);

    sf::Text _text;
    sf::Font _textFont;

    const size_t SCROLLING_FACTOR = 1;
    const size_t VERTICAL_OFFSET = 50;
    const size_t OFFSET_BETWEEN_BLOCKS = 200;
    const size_t LEFT_OFFSET = 700;

    sf::Text _chetrit[7];
    const std::string CHETRIT_TASKS[7] = {
      "Alexandre Chetrit:\n",
      "\nBoucle de jeu",
      "\nIScreen",
      "\nTableaux",
      "\nBlocs & collisions",
      "\nBonus",
      "\nbackground matrix"
    };

    sf::Text _axel[7];
    const std::string AXEL_TASKS[7] = {
        "Axel Karcher:",
        "\nDA",
        "\nblocs & collisions",
        "\nsprite personnage + idle",
        "\nsons",
        "\ntableaux",
        "\nbonus"
    };

    sf::Text _lucas[6];
    const std::string LUCAS_TASKS[6] = {
        "Lucas Bernard:",
        "\nGenerique",
        "\nmenu options",
        "\nfix sons",
        "\nmenu principal",
        "\nbonus"
    };

    sf::Text _maxime[7];
    const std::string MAXIME_TASKS[7] = {
        "Maxime Sarres:",
        "\nSons",
        "\nmenu principal",
        "\nfade out de lancement",
        "\nfix des sons",
        "\nmenu option",
        "\nbonus"
    };

    sf::Text _sean[6];
    const std::string SEAN_TASKS[6] = {
        "Sean Morton:",
        "\nAnimation sol",
        "\nbackground matrix",
        "\nsprite personnage + idle",
        "\ngenerique",
        "\nreadme/-h"
    };

    size_t y;
};
};

#endif /* !CREDITSSCREEN_HPP_ */
