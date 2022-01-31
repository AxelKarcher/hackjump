/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** CreditsScreen
*/

#include "Main.hpp"

namespace Screen::Credits
{
Main::Main()
{
    y = 0;

    _textFont.loadFromFile("assets/fontCredits.ttf");

    initText(_text, _textFont, 70);
    for (size_t i = 0; i < ARRAYLEN(CHETRIT_TASKS); ++i)
        initText(_chetrit[i], _textFont, 40);
    for (size_t i = 0; i < ARRAYLEN(AXEL_TASKS); ++i)
        initText(_axel[i], _textFont, 40);
    for (size_t i = 0; i < ARRAYLEN(LUCAS_TASKS); ++i)
        initText(_lucas[i], _textFont, 40);
    for (size_t i = 0; i < ARRAYLEN(MAXIME_TASKS); ++i)
        initText(_maxime[i], _textFont, 40);
    for (size_t i = 0; i < ARRAYLEN(SEAN_TASKS); ++i)
        initText(_sean[i], _textFont, 40);
}

void Main::initText(sf::Text &text, const sf::Font &font, const size_t &size)
{
    text.setCharacterSize(size);
    text.setFont(font);
}

void Main::setString(const std::string &value, sf::Text &text, const sf::Vector2f &position, const sf::Color &color) {
    text.setString(value);
    text.setPosition(position);
    text.setFillColor(color);
}

GameConstants::SCREEN_RETURN Main::eventUpdate(__attribute__((unused)) sf::RenderWindow &window)
{
    sf::Event event;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return (GameConstants::CHANGE_TO_MENU);
    while (window.pollEvent(event));
    return (GameConstants::DO_NOTHING);
}

sf::Color Main::getColorDependingOnLevel(size_t y)
{
    size_t offsetFromMiddle = std::abs(static_cast<int>(GameConstants::WINDOW_Y / 2 - y));

    return (sf::Color(255, 255, 255,
        255  - ((offsetFromMiddle * 255) / (GameConstants::WINDOW_Y / 2))));
}

GameConstants::SCREEN_RETURN Main::logicUpdate(__attribute__((unused)) sf::RenderWindow &window)
{
    size_t yFirstText =  100 - y * SCROLLING_FACTOR;
    size_t currentOffset = 300;

    setString("Thanks For Playing!", _text, sf::Vector2f(LEFT_OFFSET, yFirstText),
        getColorDependingOnLevel(yFirstText));
    for (size_t i = 0; i < ARRAYLEN(CHETRIT_TASKS); ++i) {
        size_t crt_y = (currentOffset + i * VERTICAL_OFFSET) - (y * SCROLLING_FACTOR);
        setString(CHETRIT_TASKS[i], _chetrit[i], sf::Vector2f(LEFT_OFFSET,
            crt_y), getColorDependingOnLevel(crt_y));
    }
    currentOffset += (ARRAYLEN(CHETRIT_TASKS) - 1) * VERTICAL_OFFSET + OFFSET_BETWEEN_BLOCKS;
    for (size_t i = 0; i < ARRAYLEN(AXEL_TASKS); ++i) {
        size_t crt_y = (currentOffset + i * VERTICAL_OFFSET) - (y * SCROLLING_FACTOR);
        setString(AXEL_TASKS[i], _axel[i], sf::Vector2f(LEFT_OFFSET,
            crt_y), getColorDependingOnLevel(crt_y));
    }
    currentOffset += (ARRAYLEN(AXEL_TASKS) - 1) * VERTICAL_OFFSET + OFFSET_BETWEEN_BLOCKS;
    for (size_t i = 0; i < ARRAYLEN(LUCAS_TASKS); ++i) {
        size_t crt_y = (currentOffset + i * VERTICAL_OFFSET) - (y * SCROLLING_FACTOR);
        setString(LUCAS_TASKS[i], _lucas[i], sf::Vector2f(LEFT_OFFSET,
            crt_y), getColorDependingOnLevel(crt_y));
    }
    currentOffset += (ARRAYLEN(LUCAS_TASKS) - 1) * VERTICAL_OFFSET + OFFSET_BETWEEN_BLOCKS;
    for (size_t i = 0; i < ARRAYLEN(MAXIME_TASKS); ++i) {
        size_t crt_y = (currentOffset + i * VERTICAL_OFFSET) - (y * SCROLLING_FACTOR);
        setString(MAXIME_TASKS[i], _maxime[i], sf::Vector2f(LEFT_OFFSET,
            crt_y), getColorDependingOnLevel(crt_y));
    }
    currentOffset += (ARRAYLEN(MAXIME_TASKS) - 1) * VERTICAL_OFFSET + OFFSET_BETWEEN_BLOCKS;
    for (size_t i = 0; i < ARRAYLEN(SEAN_TASKS); ++i) {
        size_t crt_y = (currentOffset + i * VERTICAL_OFFSET) - (y * SCROLLING_FACTOR);
        setString(SEAN_TASKS[i], _sean[i], sf::Vector2f(LEFT_OFFSET,
            crt_y), getColorDependingOnLevel(crt_y));
    }
    if (((currentOffset + 5 * VERTICAL_OFFSET) - y * SCROLLING_FACTOR) <= 0) {
        return (GameConstants::CHANGE_TO_MENU);
    }

    y += 1;
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::displayUpdate(sf::RenderWindow &window)
{
    window.draw(_text);
    for (size_t i = 0; i < ARRAYLEN(CHETRIT_TASKS); ++i)
        window.draw(_chetrit[i]);
    for (size_t i = 0; i < ARRAYLEN(AXEL_TASKS); ++i)
        window.draw(_axel[i]);
    for (size_t i = 0; i < ARRAYLEN(LUCAS_TASKS); ++i)
        window.draw(_lucas[i]);
    for (size_t i = 0; i < ARRAYLEN(MAXIME_TASKS); ++i)
        window.draw(_maxime[i]);
    for (size_t i = 0; i < ARRAYLEN(SEAN_TASKS); ++i)
        window.draw(_sean[i]);
    return (GameConstants::DO_NOTHING);
}
}