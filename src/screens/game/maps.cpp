/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** maps
*/

#include "Main.hpp"

namespace Screen::Game
{
void Main::initMap0(struct map_s &map)
{
    Utils::setString("> SWITCH", _tutorialText1,
        sf::Vector2f(125, 490), sf::Color::White);
    Utils::setString("> RESTART", _tutorialText2,
        sf::Vector2f(1260, 174), sf::Color::White);

    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(50, 600),
        sf::Vector2f(537, 568), RED, true)); // Unique rouge
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 600),
        sf::Vector2f(1200, 590), GREY, true)); // Gris de gauche
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 600),
        sf::Vector2f(1550, 460), GREY, true)); // Gris de droite
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 70),
        sf::Vector2f(860, 725), N_BLUE, false)); // Cube bleu
}

void Main::initMap1(struct map_s &map)
{
    map.hiddenChar = "66";
    map.hiddenText.setFont(_termFont);
    Utils::setString(map.hiddenChar, map.hiddenText,
        sf::Vector2f(518, 805), sf::Color(180, 180, 180, 200));

    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 50),
        sf::Vector2f(1670, 370), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(75, 50),
        sf::Vector2f(815, 425), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(50, 1000),
        sf::Vector2f(1210, 410), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(180, 50),
        sf::Vector2f(770, 610), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 100),
        sf::Vector2f(500, 780), N_BLUE, false));
}

void Main::initMap2(struct map_s &map)
{
    map.hiddenChar = "65";
 map.hiddenText.setFont(_termFont);
    Utils::setString(map.hiddenChar, map.hiddenText,
        sf::Vector2f(810, 50), sf::Color(180, 180, 180, 200));

    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(180, 800),
        sf::Vector2f(275, 390), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(50, 800),
        sf::Vector2f(1000, 520), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(200, 700),
        sf::Vector2f(1530, 300), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 40),
        sf::Vector2f(1730, 300), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(50, 250),
        sf::Vector2f(820, 120), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(50, 400),
        sf::Vector2f(1530, -100), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(80, 40),
        sf::Vector2f(1245, 425), N_BLUE, false));
}

void Main::initMap3(struct map_s &map)
{
    map.hiddenChar = "78";
    map.hiddenText.setFont(_termFont);
    Utils::setString(map.hiddenChar, map.hiddenText,
        sf::Vector2f(787, 390), sf::Color(180, 180, 180, 200));

    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(40, 800),
        sf::Vector2f(430, 300), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(60, 60),
        sf::Vector2f(290, 410), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(60, 60),
        sf::Vector2f(160, 550), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(60, 60),
        sf::Vector2f(290, 690), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(950, 500), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(1140, 325), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(1300, 515), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(755, 340), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(515, 690), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(1580, 500), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(1540, 270), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 130),
        sf::Vector2f(1100, 770), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 550),
        sf::Vector2f(GameConstants::WINDOW_X - 50, 150), GREY, true));
}

void Main::initMap4(struct map_s &map)
{
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(200, 700),
        sf::Vector2f(1210, -10), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(700, 700),
        sf::Vector2f(-10, -10), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(520, 100),
        sf::Vector2f(690, 160), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(520, 100),
        sf::Vector2f(690, 400), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(520, 100),
        sf::Vector2f(690, 640), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 700),
        sf::Vector2f(900, 190), GREY, true));
}

void Main::initMap5(struct map_s &map)
{
    map.hiddenChar = "65";
 map.hiddenText.setFont(_termFont);
    Utils::setString(map.hiddenChar, map.hiddenText,
        sf::Vector2f(1673, 715), sf::Color(180, 180, 180, 200));

    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(87, 230),
        sf::Vector2f(427, -15), N_BLUE, false)); // Bleu on first pylon
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(87, 674),
        sf::Vector2f(427, 214), GREY, true)); // Left pylon
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(130, 24),
        sf::Vector2f(210, 330), N_BLUE, false)); // Bleu line on the left
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(87, 45),
        sf::Vector2f(30, 490), RED, true)); // High red at bottom left
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(136, 530),
        sf::Vector2f(1044, 338), GREY, true)); // End of middle pylon
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(48, 31),
        sf::Vector2f(1346, 433), RED, true)); // Red exit
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(388, 115),
        sf::Vector2f(1180, 484), N_BLUE, false)); // Blue exit from middle pylon
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(206, 114),
        sf::Vector2f(1568, 485), GREY, true)); // Grey exit
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(60, 40),
        sf::Vector2f(895, 487), N_BLUE, false)); // Bleu after vine
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(246, 50),
        sf::Vector2f(180, 620), N_BLUE, false)); // Bleu rect on the left
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(10, 424),
        sf::Vector2f(640, -15), RED, true)); // Red vine
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(10, 494),
        sf::Vector2f(813, -15), N_BLUE, false)); // Blue vine
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(136, 95),
        sf::Vector2f(1044, -15), GREY, true)); // Middle grey
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(136, 258),
        sf::Vector2f(1044, 80), RED, true)); // Red part of the middle pylon
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(34, 314),
        sf::Vector2f(1568, 171), RED, true)); // Red dorr
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(27, 276),
        sf::Vector2f(1747, 599), GREY, true)); // Trap wall
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(119, 276),
        sf::Vector2f(1655, 599), N_BLUE, false)); // Fake blue
}

void Main::initMap6(struct map_s &map)
{
    map.hiddenChar = "78";
map.hiddenText.setFont(_termFont);
    Utils::setString(map.hiddenChar, map.hiddenText, sf::Vector2f(811, 806),
        sf::Color(180, 180, 180, 200));

    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 775),
        sf::Vector2f(1620, 95), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 100),
        sf::Vector2f(450, 700), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 100),
        sf::Vector2f(650, 600), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 100),
        sf::Vector2f(850, 500), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 100),
        sf::Vector2f(1050, 400), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 100),
        sf::Vector2f(1220, 300), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 40),
        sf::Vector2f(1720, 150), N_BLUE, false));
}

void Main::initMap7(struct map_s &map)
{
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 320),
        sf::Vector2f(1720, -20), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 350),
        sf::Vector2f(1720, 550), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 25),
        sf::Vector2f(500, 300), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 25),
        sf::Vector2f(500, 500), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 25),
        sf::Vector2f(500, 700), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 25),
        sf::Vector2f(600, 400), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 25),
        sf::Vector2f(400, 600), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(200, 25),
        sf::Vector2f(800, 275), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(78, 25),
        sf::Vector2f(1000, 275), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(640, 25),
        sf::Vector2f(1080, 275), GREY, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(920, 25),
        sf::Vector2f(800, 550), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 300),
        sf::Vector2f(750, -10), N_BLUE, false));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(100, 700),
        sf::Vector2f(750, 200), GREY, true));
}

void Main::initMap8(struct map_s &map)
{
    map.hiddenChar = "65";
    map.hiddenText.setFont(_termFont);
    Utils::setString(map.hiddenChar, map.hiddenText,
        sf::Vector2f(647, 815), sf::Color(180, 180, 180, 200));

    for (size_t i = 0; i < 6; ++i) {
        map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 550 - i * 100),
            sf::Vector2f(500 + 220 * i, -10), GREY, true));
        map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(70, 2000),
            sf::Vector2f(500 + 220 * i, 700 - 60 * i), GREY, true));
    }
}

void Main::initMap9(struct map_s &map)
{
    map.hiddenChar = "> xxxxxx";
    map.hiddenText.setFont(_termFont);
    Utils::setString(map.hiddenChar, map.hiddenText, sf::Vector2f(GameConstants::WINDOW_X / 2 - 120,
        (GameConstants::WINDOW_Y - FLOOR_LEVEL) / 2 + 100), sf::Color(180, 180, 180, 200));

    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(GameConstants::WINDOW_X - 400, 120),
        sf::Vector2f(200, FLOOR_LEVEL - 100), RED, true));
    map.blocks.push_back(std::make_shared<Block>(sf::Vector2f(GameConstants::WINDOW_X - 400, 120),
        sf::Vector2f(200, FLOOR_LEVEL - 100), N_BLUE, false));
}
}