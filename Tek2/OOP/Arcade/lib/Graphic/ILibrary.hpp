/*
** EPITECH PROJECT, 2022
** Project
** File description:
** ILibrary
*/

#ifndef ILIBRARY_HPP_
#define ILIBRARY_HPP_

#include <stdio.h>
#include <string>
#include <vector>

namespace arcade {
    namespace graphical {
        typedef enum events {
            UP = 1,
            DOWN,
            LEFT,
            RIGHT,
            RESTART,
            EXIT,
            MENU,
            PREV_GRAPH,
            NEXT_GRAPH,
            RUN_GRAPH,
            PREV_GAME,
            NEXT_GAME,
            RUN_GAME,
        } events_e;

        class ILibrary {
            public:
                /// Create and set up window, need a resolution.
                /// x = number of cell width
                /// y = number of cell height
                /// cellsize = size of a cell
                /// frequency = fps
                virtual void createWindow(size_t x, size_t y, size_t cellSize, size_t frequency) = 0;

                /// Delete window.
                virtual void deleteWindow() = 0;

                /// Put the background
                /// r = red ratio
                /// g = green ratio
                /// b = blue ratio
                virtual void putBackground(char r, char g, char b) = 0;


                /// Return the player events.
                virtual std::vector<events_e> getEvents() const = 0;

                /// Put a character at a Position.
                /// x/y = position
                /// c = char to put
                virtual void displayTile(int x, int y, char c) = 0;

                /// Put a character at a Position.
                /// song = path to song?
                virtual void playSound(std::string song) = 0;

                /// Render and update the window. Call after
                virtual void update() = 0;

                /// Return lib name.
                virtual std::string getName() const = 0;
        };
    }
}

#endif /* !ILIBRARY_HPP_ */
