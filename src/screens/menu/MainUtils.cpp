/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** MenuUtils
*/

#include <unistd.h>

#include "Main.hpp"

namespace Screen::Menu
{
GameConstants::SCREEN_RETURN Main::playButtonManager(sf::RenderWindow &window)
{
    if (_statePlay) {
        // if mouse is in button area change state play
        _soundMouse.play();
        _statePlay = 1;
        _playSprite.setTexture(_play2Texture);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // if click on button play
        _soundSelect.play();
        _playSprite.setTexture(_play3Texture);
        this->displayUpdate(window);
        window.display();
        _fadeOutProgress = 650;
        _musicMenu->stop();
        _soundPlay.play();
        return (GameConstants::DO_NOTHING);
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::quitButtonManager(sf::RenderWindow &window)
{
    if (!_stateQuit) {
    	// if mouse is in button area change state quit
    	_soundMouse.play();
    	_stateQuit = 1;
    	_quitSprite.setTexture(_quit2Texture);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    	// if click on button quit
    	_soundSelect.play();
    	_quitSprite.setTexture(_quit3Texture);
    	this->displayUpdate(window);
    	_musicMenu->stop();
    	window.display();
    	usleep(500000);
    	return (GameConstants::EXIT_GAME);
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::optionButtonManager(sf::RenderWindow &window)
{
    //_soundMouse.play();
    if (!_stateOption) {
      // if mouse is in button area change state quit
      _soundMouse.play();
      _stateOption = 1;
      _optionSprite.setTexture(_option2Texture);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      _soundSelect.play();
      _optionSprite.setTexture(_option3Texture);
      this->displayUpdate(window);
      _isOption = true;
      window.display();
      usleep(500000);
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::returnMenuButtonManager()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      _isOption = false;
      return (GameConstants::CHANGE_TO_MENU);
    }
  return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::volumeDownButtonManager()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      if (_volume > 0) {
        _volume -= 1;
        _optionBar.setSize(sf::Vector2f(_volume * 3, 50));
      }
      if (_isMuted == 0) {
        _musicMenu->setVolume(_volume);
        _soundMouse.setVolume(_volume / 2);
        _soundSelect.setVolume(_volume / 2);
        _soundPlay.setVolume(_volume);
      } else {
        _soundMouse.setVolume(0);
        _soundSelect.setVolume(0);
        _musicMenu->setVolume(0);
        _soundPlay.setVolume(0);
      }
      return (GameConstants::DO_NOTHING);
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::volumeUpButtonManager()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      if (_volume < 100) {
        _volume += 1;
        _optionBar.setSize(sf::Vector2f(_volume * 3, 50));
      }
      if (_isMuted == 0) {
        _musicMenu->setVolume(_volume);
        _soundMouse.setVolume(_volume / 2);
        _soundSelect.setVolume(_volume / 2);
        _soundPlay.setVolume(_volume);
      }
      else {
        _soundMouse.setVolume(0);
        _soundSelect.setVolume(0);
        _musicMenu->setVolume(0);
        _soundPlay.setVolume(0);
      }
      return (GameConstants::DO_NOTHING);
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::cutVolumeButtonManager()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _optionClock.getElapsedTime().asMilliseconds() > 200) {
      _optionClock.restart();
      if (_isMuted > 0 && _ispressed == 0) {
        _volume = _isMuted;
        _isMuted = 0;
        _cutVolumeSprite.setTexture(_cutVolumeTexture);
        _musicMenu->setVolume(_volume);
        _soundMouse.setVolume(_volume / 2);
        _soundSelect.setVolume(_volume / 2);
        _soundPlay.setVolume(_volume);
        return (GameConstants::DEMUTE_GAME_VOLUME);
      } else if (_isMuted == 0 && _ispressed == 0) {
        _isMuted = _volume;
        _volume = 0;
        _cutVolumeSprite.setTexture(_cutVolume2Texture);
        _musicMenu->setVolume(0);
        _soundMouse.setVolume(0);
        _soundSelect.setVolume(0);
        _soundPlay.setVolume(0);
        return (GameConstants::MUTE_GAME_VOLUME);
      }
      _ispressed = 1;
      return (GameConstants::DO_NOTHING);
    } else
    _ispressed = 0;
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::creditsButtonManager()
{
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      _isOption = false;
      return (GameConstants::CHANGE_TO_CREDITS);
    }
  return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::optionEventUpdate(sf::RenderWindow &window)
{
    while (window.pollEvent(_event));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return (GameConstants::EXIT_GAME);
    _mousePos = sf::Mouse::getPosition(window);
    if (_mousePos.x >= 960 - 450 && _mousePos.x <= 960 - 150 && _mousePos.y >= 750 && _mousePos.y <= 850) {
      	return (this->returnMenuButtonManager());
    }
    if (_mousePos.x >= 960 + 150 && _mousePos.x <= 960 + 450 && _mousePos.y >= 750 && _mousePos.y <= 850) {
      	return (this->creditsButtonManager());
    }
    if (_mousePos.x >= 960 - 300 && _mousePos.x <= 960 - 200 && _mousePos.y >= 600 && _mousePos.y <= 700) {
      	return (this->volumeDownButtonManager());
    }
    if (_mousePos.x >= 960 - 50 && _mousePos.x <= 960 + 50 && _mousePos.y >= 750 && _mousePos.y <= 850) {
      	return (this->cutVolumeButtonManager());
    }
    if (_mousePos.x >= 960 + 200 && _mousePos.x <= 960 + 300 && _mousePos.y >= 600 && _mousePos.y <= 700) {
      	return (this->volumeUpButtonManager());
    }
    return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::optionLogicUpdate(__attribute__((unused)) sf::RenderWindow &window)
{
  return (GameConstants::DO_NOTHING);
}

GameConstants::SCREEN_RETURN Main::optionDisplayUpdate(sf::RenderWindow &window)
{
    window.draw(_menuSprite);
    window.draw(_returnMenuSprite);
    window.draw(_volumeDownSprite);
    window.draw(_volumeUpSprite);
    window.draw(_cutVolumeSprite);
    window.draw(_creditsSprite);
    window.draw(_backgroundOptionBar);
    window.draw(_optionBar);
    return (GameConstants::DO_NOTHING);
}
}