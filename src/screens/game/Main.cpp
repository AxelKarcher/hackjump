/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreen
*/

#include "Main.hpp"

namespace Screen::Game
{
Main::Main()
{
    srand(time(NULL));

    _termFont.loadFromFile("assets/fontTerm.ttf");

    // Banana
    _bananaClock.restart();
    _isRainingBananas = false;
    _nbBananas = 0;
    Utils::linkSpriteTexture(_bananaSprite, _bananaTexture, "assets/banana.png");
    for (size_t i = 0; i < NB_BANANAS; ++i) {
        sf::Sprite newBanana(_bananaSprite);
        newBanana.setPosition(sf::Vector2f(rand() % 1920, 0));
        newBanana.setScale(sf::Vector2f(0.2, 0.2));
        _bananas.push_back(newBanana);
    }
    _fadeRectangle.setSize(sf::Vector2f(1920, 1080));
    _fadeRectangle.setPosition(sf::Vector2f(0, 0));
    _fadeRectangle.setFillColor(sf::Color(0, 0, 0, 0));

    // Game Music
    _musicGame = new sf::Music();
    _musicGame->openFromFile("audio/musicGame.ogg");
    _musicGame->setLoop(true);
    _volume = 50;
    _isTermSound = false;
    _isEndTermSound = false;
    _musicGame->setVolume(_volume);
    sf::SoundBuffer *_termBuffer = new sf::SoundBuffer();
    _termBuffer->loadFromFile("audio/soundTerminal.ogg");
    _soundTerminal.setBuffer(*_termBuffer);
    sf::SoundBuffer *_typeBuffer = new sf::SoundBuffer();
    _typeBuffer->loadFromFile("audio/soundType.ogg");
    _soundType.setBuffer(*_typeBuffer);
    sf::SoundBuffer *_validBuffer = new sf::SoundBuffer();
    _validBuffer->loadFromFile("audio/soundEndTerminal.ogg");
    _soundValid.setBuffer(*_validBuffer);

    // Chrono
    _graffFont.loadFromFile("assets/fontGraff.ttf");
    _levelText.setFont(_graffFont);
    _chronoText.setFont(_graffFont);

    // Death
    Utils::linkSpriteTexture(_deathSprite, _deathTexture, "assets/death.png");
    _deathSprite.setPosition(1745, 10);
    _deathText.setFont(_graffFont);

    // Tutorial
    Utils::linkSpriteTexture(_tKeySprite, _tKeyTexture, "assets/tutoKey.png");
    _tKeySprite.setPosition(206, 370);
    Utils::linkSpriteTexture(_showSprite, _showTexture,"assets/tutoShow.jpg");
    _showSprite.setPosition(382, 596);
    _showSprite.setColor(sf::Color(170, 170, 170));
    _tutorialText1.setFont(_termFont);
    _tutorialText2.setFont(_termFont);

    initInputs();
    initMaps();

    // Ground
    Utils::linkSpriteTexture(_groundSprite, _groundTexture, "assets/ground.png");
    _groundRect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(1920, 340));
    _groundSprite.setTextureRect(_groundRect);
    _groundSprite.setPosition(0, 740);
    _groundClock.restart();

    initBackground();
}

GameConstants::SCREEN_RETURN Main::eventUpdate(sf::RenderWindow &window)
{
    while (window.pollEvent(_event)) {
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape) {
            _escapeInput = true;
        }
        _terminal.eventUpdate(_event);
        _pauseMenu.eventUpdate(_event);
        _player.eventUpdate(_event);
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::logicUpdate(sf::RenderWindow &window)
{
    sf::Vector2f stkPosition = _player.getPosition();
    GameConstants::SCREEN_RETURN retval;

    if (!_calledOnce) {
        _musicGame->play();
        _chronoClock.restart();
        _calledOnce = true;
    }
    if (_terminal.logicUpdate(window, _escapeInput) == HANDLE_COMMANDS
        && terminalHandleCommands() == GameConstants::EXIT_GAME) {
        return (GameConstants::EXIT_GAME);
    }
    retval = _pauseMenu.logicUpdate(window, _escapeInput);
    if (retval == GameConstants::CHANGE_TO_MENU || retval == GameConstants::EXIT_GAME) {
        return (retval);
    }
    if (_terminal.logicUpdate(window, _escapeInput) == HANDLE_COMMANDS) {
        terminalHandleCommands();
    }
    if (_player.logicUpdate(window, _maps[_currentMap], _terminal) == GameConstants::EXIT_GAME) {
        return (GameConstants::EXIT_GAME);
    }
    if (!checkHitboxes()) {
        _player.setPosition(stkPosition);
    }
    if (handleMapSwitch() == GameConstants::EXIT_GAME) {
        return (GameConstants::EXIT_GAME);
    }

    updateTexts();
    updateSprites();

    if (_isRainingBananas && Utils::isClockAtLimit(_bananaClock, 80)) {
        if (updateBananas() == GameConstants::CHANGE_TO_CREDITS) {
            return (GameConstants::CHANGE_TO_CREDITS);
        }
        _bananaClock.restart();
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::displayUpdate(sf::RenderWindow &window)
{
    window.draw(_sBackground);
    if (_isRainingBananas) {
        for (size_t i = 0; i < _bananas.size(); ++i) {
            window.draw(_bananas[i]);
        }
    }

    if (_currentMap == 0) {
        window.draw(_tutorialText1);
        window.draw(_tutorialText2);
        window.draw(_tKeySprite);
        window.draw(_showSprite);
    }

    window.draw(_maps[_currentMap].hiddenText);
    for (auto it = _maps[_currentMap].blocks.begin(); it != _maps[_currentMap].blocks.end(); it++)
        window.draw(it->get()->getShape());
    window.draw(_groundSprite);
    if (_terminal.isOpen()) {
        _terminal.drawUpdate(window);
    }
    _player.displayUpdate(window);
    window.draw(_chronoText);
    window.draw(_deathText);
    window.draw(_deathSprite);
    window.draw(_levelText);
    if (_pauseMenu.isOpen()) {
        _pauseMenu.drawUpdate(window);
    }
    window.draw(_fadeRectangle);
    return (GameConstants::DO_NOTHING);
}
}