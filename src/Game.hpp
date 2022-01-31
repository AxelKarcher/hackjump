/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "ISCreen.hpp"
#include "GameConstants.hpp"

#include "screens/game/Main.hpp"
#include "screens/menu/Main.hpp"
#include "screens/credits/Main.hpp"

class Game {
	public:
		Game();
		~Game() = default;

		void run();

	private:
		bool checkScreenReturnValue(GameConstants::SCREEN_RETURN value);
		Screen::Game::Main _gameScreen;
		Screen::Menu::Main _menuScreen;
		Screen::Credits::Main _creditsScreen;
		std::unique_ptr<ISCreen> _currentScreen;
		sf::RenderWindow _window;
		sf::Clock clock;
};

#endif /* !GAME_HPP_ */
