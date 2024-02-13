/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-arcade-tanguy.bellicha
** File description:
** mysdlLibrary
*/

#ifndef _ARCADE_SDL_LIBRARY_
#define _ARCADE_SDL_LIBRARY_

#include "../ILibrary.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <memory>

namespace arcade {
    namespace graphical {
        class sdlLibrary : public ILibrary
        {
            public:
                sdlLibrary(/* args */);

                ~sdlLibrary();

                void createWindow(size_t x, size_t y, size_t cellSize, size_t frequency);
                /// Delete window.

                void deleteWindow();
                /// Return the player events.

                std::vector<events_e> getEvents() const;
                /// Put a character at a Position.

                void putBackground(char r, char g, char b);
                /// Put background.

                void displayTile(int x, int y, char c);
                /// Put a character at a Position.

                void playSound(std::string song);
                /// Render and update the window. Call after

                /// Update the window.
                void update();

                /// Return lib name.
                std::string getName() const;
            private:
                struct SDL_Window *_window;
                struct SDL_Renderer *_renderer;
                bool _isRunning;
                int _width;
                int _height;
                int _cellSize;
                TTF_Font* _font;
        };
    }
}

#endif