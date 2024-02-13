/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-arcade-tanguy.bellicha
** File description:
** sfmlLibrary
*/

#ifndef _ARCADE_SFML_LIBRARY_
#define _ARCADE_SFML_LIBRARY_

#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>
#include "../ILibrary.hpp"
#include <memory>

namespace arcade {
    namespace graphical {
        class sfmlLibrary : public ILibrary
        {
            public:
                sfmlLibrary(/* args */);

                ~sfmlLibrary();

                void createWindow(size_t x, size_t y, size_t cellSize, size_t frequency);
                /// Delete window.

                void deleteWindow();
                /// Return the player events.

                /// Draw background; mostly a clear.
                void putBackground(char r, char g, char b);

                std::vector<events_e> getEvents() const;
                /// Put a character at a Position.

                void displayTile(int x, int y, char c);
                /// Put a character at a Position.

                void playSound(std::string song);
                /// Render and update the window. Call after

                /// Update the window.
                void update();

                /// Return lib name.
                std::string getName() const;
            private:
                std::unique_ptr<sf::RenderWindow> _window;
                sf::Font _font;
                sf::Text _text;
        };
    }
}

#endif