/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** MenuScreen
*/

#include <unistd.h>

#include "Main.hpp"

namespace Screen::Menu
{
Main::Main()
{
	// version
	_textFont.loadFromFile("assets/calibri_bold.TTF");
	_versionText.setFont(_textFont);
	_versionText.setString(_version);
	_versionText.setPosition(30, 30);
	_versionText.setCharacterSize(30);
	_versionText.setOutlineColor(sf::Color::Black);
	_versionText.setOutlineThickness(2);

	// sprites and texture
	Utils::linkSpriteTexture(_menuSprite, _menuTexture, "assets/menuBackground.jpg");
	_menuSprite.setPosition(0, 0);
	Utils::linkSpriteTexture(_playSprite, _playTexture, "assets/buttonPlay1.jpg");
	_playSprite.setPosition(300, 600);
	Utils::linkSpriteTexture(_quitSprite, _quitTexture, "assets/buttonQuit1.jpg");
	_quitSprite.setPosition(1300, 600);
	Utils::linkSpriteTexture(_optionSprite, _optionTexture, "assets/buttonOption1.jpg");
	_optionSprite.setPosition(800, 850);
	Utils::linkSpriteTexture(_creditsSprite, _creditsTexture, "assets/buttonCredits.jpg");
	_creditsSprite.setPosition(GameConstants::WINDOW_X / 2 + 150, 750);
	Utils::linkSpriteTexture(_returnMenuSprite, _returnMenuTexture, "assets/buttonMenu.jpg");
	_returnMenuSprite.setPosition(GameConstants::WINDOW_X / 2 - 450, 750);
	Utils::linkSpriteTexture(_volumeDownSprite, _volumeDownTexture, "assets/volumeDown.jpg");
	_volumeDownSprite.setPosition(GameConstants::WINDOW_X / 2 - 300, 600);
	Utils::linkSpriteTexture(_volumeUpSprite, _volumeUpTexture, "assets/volumeUp.jpg");
	_volumeUpSprite.setPosition(GameConstants::WINDOW_X / 2 + 200, 600);
	Utils::linkSpriteTexture(_cutVolumeSprite, _cutVolumeTexture, "assets/volumeCut.jpg");
	_cutVolumeSprite.setPosition(GameConstants::WINDOW_X / 2 - 50, 750);


	// buttons states textures
	_cutVolume2Texture.loadFromFile("assets/volumeRestore.jpg");
	_play2Texture.loadFromFile("assets/buttonPlay2.jpg");
	_quit2Texture.loadFromFile("assets/buttonQuit2.jpg");
	_option2Texture.loadFromFile("assets/buttonOption2.jpg");
	_play3Texture.loadFromFile("assets/buttonPlay3.jpg");
	_quit3Texture.loadFromFile("assets/buttonQuit3.jpg");
	_option3Texture.loadFromFile("assets/buttonOption3.jpg");
	_statePlay = _stateQuit = _stateOption = 0;
	_isOption = false;

	// bar of volume
	_volume = 50;
	_isMuted = false;
	_optionBar.setSize(sf::Vector2f(_volume * 3, 50));
	_optionBar.setFillColor(sf::Color::White);
	_optionBar.setPosition(960 - 150, 625);
	_backgroundOptionBar.setSize(sf::Vector2f(320, 70));
	_backgroundOptionBar.setFillColor(sf::Color::Black);
	_backgroundOptionBar.setPosition(960 - 160, 615);


	// fadeout init
	_rectShape.setSize(sf::Vector2f(1920, 1080));
	_rectShape.setFillColor(sf::Color(255, 255, 255, 0));

	//audio init
	_optionClock.restart();
	_musicMenu = new sf::Music();
	_musicMenu->openFromFile("audio/musicMenu.ogg");
	_musicMenu->setLoop(true);
	_musicMenu->setVolume(_volume);
	_musicMenu->play();
	_isMusic = false;
	sf::SoundBuffer *_playBuffer = new sf::SoundBuffer();
	_playBuffer->loadFromFile("audio/soundStart.ogg");
	_soundPlay.setBuffer(*_playBuffer);
	sf::SoundBuffer *_mouseBuffer = new sf::SoundBuffer();
	_mouseBuffer->loadFromFile("audio/soundMouse.ogg");
	_soundMouse.setBuffer(*_mouseBuffer);
	_soundMouse.setVolume(_volume / 2);
	sf::SoundBuffer *_selectBuffer = new sf::SoundBuffer();
	_selectBuffer->loadFromFile("audio/soundSelect.ogg");
	_soundSelect.setBuffer(*_selectBuffer);
}

GameConstants::SCREEN_RETURN Main::eventUpdate(sf::RenderWindow &window)
{
	if (_isOption) {
		return (optionEventUpdate(window));
	}
	if (_isMusic == false) {
		_musicMenu->play();
		_isMusic = true;
	}
	while (window.pollEvent(_event));
	// managing the fade out when play is clicked
	if (_fadeOutProgress <= 650 && _fadeOutProgress > 0) {
		_fadeOutProgress -= 1;
		return (GameConstants::DO_NOTHING);
	} else if (_fadeOutProgress <= 0) {
		_soundPlay.stop();
		_isMusic = false;
		return (GameConstants::CHANGE_TO_GAME);
	}
	_mousePos = sf::Mouse::getPosition(window);

	// event managing (clicks, mouse area, Escape...)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return (GameConstants::EXIT_GAME);
	if (_mousePos.x >= 300 && _mousePos.x <= 600 && _mousePos.y >= 600 && _mousePos.y <= 720) {
		return (this->playButtonManager(window));
	} else if (_mousePos.x >= 1300 && _mousePos.x <= 1600 && _mousePos.y >= 600 && _mousePos.y <= 720) {
		return (this->quitButtonManager(window));
	} else if (_mousePos.x >= 800 && _mousePos.x <= 1100 && _mousePos.y >= 850 && _mousePos.y <= 970) {
		return (this->optionButtonManager(window));
	}
	// if mouse is away of area button, return to basic states
	_stateQuit = _statePlay = _stateOption = 0;
	_playSprite.setTexture(_playTexture);
	_quitSprite.setTexture(_quitTexture);
		_optionSprite.setTexture(_optionTexture);
	return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::logicUpdate(sf::RenderWindow &window)
{
	if (_isOption) {
		return (optionLogicUpdate(window));
	}
	if (_fadeOutProgress <= 650) {
		_opacity += 0.38;
		_rectShape.setFillColor(sf::Color(255, 255, 255, _opacity));
	}
	return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::displayUpdate(sf::RenderWindow &window)
{
	window.draw(_menuSprite);
	window.draw(_versionText);
	if (!_isOption) {
		window.draw(_playSprite);
		window.draw(_quitSprite);
		window.draw(_optionSprite);
	} else {
		optionDisplayUpdate(window);
	}
	if (_fadeOutProgress <= 650) {
		window.draw(_rectShape);
	}
	return (GameConstants::DO_NOTHING);
}
}