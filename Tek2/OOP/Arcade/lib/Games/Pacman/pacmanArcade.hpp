/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-arcade-tanguy.bellicha
** File description:
** pacmanArcade
*/

#ifndef PACMANARCADE_HPP_
#define PACMANARCADE_HPP_

#include "../IGame.hpp"
#include <time.h>
#include <map>

#define GAME_HEIGHT 19
#define GAME_LENGTH 19
#define CHAR_PACMAN 'P'
#define CHAR_GHOST 'G'
#define CHAR_DEAD_GHOST '*'
#define CHAR_GUM '.'
#define CHAR_PACGUM 'o'
#define CHAR_WALL '#'
#define MAP_LOCATION "./pacmanMap.txt"

namespace arcade
{
    namespace game
    {
        class Pacman : public IGame
        {
        public:
            Pacman();
            ~Pacman();
            /// Start the game.
            void start();

            /// Reset the game.
            void reset();

            // Ask for game to do a new game loop.
            void update(std::vector<arcade::graphical::events>);

            /// Return the score.
            size_t getScore() const;

            /// Return the state of the game.
            arcade::game::gameState getGameState() const;

            /// Exit the program.
            void exit();

            /// Return the tileMap of the game.
            std::vector<std::string> getTilemap() const;

            /// Updates tileMap with the information of the game
            void updateTileMap();

            /// Checks if the next move will result in pacman's death
            bool checkDeath();

            /// Resets map and gums without removing score
            void winReset();
        protected:
            direction _direction;
            bool _isStart;
            bool _isExit;
            arcade::game::gameState _gameState;
            size_t _score;
            std::vector<std::string> _tileMap;
            std::map<char, size_t> _pacman;
            std::vector<std::map<char, size_t>> _ghosts;
            std::vector<std::map<char, size_t>> _gums;
            std::vector<direction> _ghostDir;
            time_t _timer;
        };
    };
}

#endif /* !PACMANARCADE_HPP_ */
