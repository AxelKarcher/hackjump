/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** GameScreen
*/

#ifndef GAMESCREEN_HPP_
#define GAMESCREEN_HPP_

#include <memory>
#include <string>
#include <iostream>
#include <array>

#include "../../ISCreen.hpp"
#include "pause/Pause.hpp"
#include "terminal/Terminal.hpp"
#include "player/Player.hpp"
#include "maps.hpp"

namespace Screen::Game
{
static const size_t FLOOR_LEVEL = 850;

class Main : public ISCreen {
    public:
        Main();
        ~Main() = default;

        void setVolume(float volume);

        GameConstants::SCREEN_RETURN eventUpdate(sf::RenderWindow &window) override;
        GameConstants::SCREEN_RETURN logicUpdate(sf::RenderWindow &window) override;
        GameConstants::SCREEN_RETURN displayUpdate(sf::RenderWindow &window) override;

    private:
        std::string getChronoFormat(float seconds);

        void initInputs();

        void updateTexts();
        void updateSprites();
        void restartPlayer();

        sf::Event _event;
        sf::Font _termFont;
        sf::Font _graffFont;

        sf::Text _levelText;

        // Tutorial
        sf::Text _tutorialText1;
        sf::Text _tutorialText2;
        sf::Sprite _tKeySprite;
        sf::Texture _tKeyTexture;
        sf::Sprite _showSprite;
        sf::Texture _showTexture;

        // Game Music
        sf::Music   *_musicGame;
        sf::Sound   _soundTerminal;
        sf::Sound   _soundType;
        sf::Sound   _soundValid;
        float   _volume;
        bool    _isTermSound;
        bool    _isEndTermSound;

        // Bananas
        bool _isRainingBananas;
        static const size_t NB_BANANAS = 150;
        GameConstants::SCREEN_RETURN updateBananas();
        sf::Sprite _bananaSprite;
        std::vector<sf::Sprite> _bananas;
        sf::Texture _bananaTexture;
        sf::Clock _bananaClock;
        size_t _nbBananas;
        sf::RectangleShape _fadeRectangle;

        // Death
        int _deathCount;
        sf::Sprite _deathSprite;
        sf::Texture _deathTexture;
        sf::Text _deathText;
        sf::Clock _deathClock;

        // Chrono
        sf::Clock _chronoClock;
        sf::Text _chronoText;
        bool _calledOnce;

        bool doOverlap(sf::Vector2f l1, sf::Vector2f r1, sf::Vector2f l2, sf::Vector2f r2);
        Player _player;

        // Background
        void initBackground();
        sf::IntRect _backgroundRect;
        sf::Texture _background;
        sf::Sprite _sBackground;
        size_t _currentBackground;
        void updateBackground();
        sf::Clock _bgClock;

        //Ground
        sf::Texture _groundTexture;
        sf::Sprite _groundSprite;
        sf::IntRect _groundRect;
        sf::Clock _groundClock;

        // Moving
        bool _rightInput;
        bool _leftInput;

        // Jumping
        int _jumpHigh;
        bool _hasJump;
        bool _upInput;

        bool _escapeInput;
        Pause _pauseMenu;

        // Terminal mode
        Terminal _terminal;
        GameConstants::SCREEN_RETURN terminalHandleCommands();

        // Blocks
        void initMaps();
        void switchBlocks();

        bool checkHitboxes();

        // Maps
        #define NB_MAPS 10
        GameConstants::SCREEN_RETURN handleMapSwitch();
        size_t _currentMap;
        std::array<struct map_s, NB_MAPS> _maps;

        void initMap0(struct map_s &map);
        void initMap1(struct map_s &map);
        void initMap2(struct map_s &map);
        void initMap3(struct map_s &map);
        void initMap4(struct map_s &map);
        void initMap5(struct map_s &map);
        void initMap6(struct map_s &map);
        void initMap7(struct map_s &map);
        void initMap8(struct map_s &map);
        void initMap9(struct map_s &map);

        void (Main:: *mapFuncs[NB_MAPS])(struct map_s &map) = {
            &Main::initMap0,
            &Main::initMap1,
            &Main::initMap2,
            &Main::initMap3,
            &Main::initMap4,
            &Main::initMap5,
            &Main::initMap6,
            &Main::initMap7,
            &Main::initMap8,
            &Main::initMap9,
        };
};
};

#endif /* !GameSCREEN_HPP_ */
