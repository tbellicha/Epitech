/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-arcade-tanguy.bellicha
** File description:
** pacmanArcade
*/

#ifndef PACMANARCADE_HPP_
#define PACMANARCADE_HPP_

#include "../IGame.hpp"
#include <map>

#define GAME_HEIGHT 24
#define GAME_LENGTH 24
#define START_SIZE 4
#define CHAR_HEAD 'H'
#define CHAR_BODY 'O'
#define CHAR_FRUIT 'X'

namespace arcade
{
    namespace game
    {
        class Nibbler : public IGame
        {
        public:
            Nibbler();
            ~Nibbler();
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

            /// Checks if the next move will result in snake's death
            bool checkDeath();
        protected:
            direction _direction;
            bool _isStart;
            bool _isExit;
            arcade::game::gameState _gameState;
            size_t _score;
            std::vector<std::string> _tileMap;
            std::vector<std::map<char ,size_t>> _snake;
            std::map<char ,size_t> _fruit;
        };
    };
}

#endif /* !PACMANARCADE_HPP_ */
