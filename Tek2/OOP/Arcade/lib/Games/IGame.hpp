/*
** EPITECH PROJECT, 2022
** Project
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <stdio.h>
#include <iostream>
#include <vector>
#include "../Graphic/ILibrary.hpp"

namespace arcade {
    namespace game {
        enum direction {
            UP = 1,
            DOWN,
            LEFT,
            RIGHT
        };

        enum gameState {
            RUNNING = 1,
            OVER,
            EXIT,
            WON
        };
        class IGame {
            public:
                /// Start the game.
                virtual void start() = 0;

                /// Reset the game.
                virtual void reset() = 0;

                // Ask for game to do a new game loop.
                virtual void update(std::vector<arcade::graphical::events>) = 0;

                /// Return the score.
                virtual size_t getScore() const = 0;

                /// Return the state of the game.
                virtual gameState getGameState() const = 0;

                /// Exit the program.
                virtual void exit() = 0;

                /// Return the tileMap of the game.
                virtual std::vector<std::string> getTilemap() const = 0;
        };
    }
} // namespace Arcade

#endif /* !IGAME_HPP_ */
