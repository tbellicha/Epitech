/*
** EPITECH PROJECT, 2022
** Project
** File description:
** sfmlLibrary
*/

#include "sfmlLibrary.hpp"

namespace arcade
{
    namespace graphical
    {
        sfmlLibrary::sfmlLibrary()
        {
        }

        sfmlLibrary::~sfmlLibrary()
        {
        }

        void sfmlLibrary::createWindow(size_t x, size_t y, size_t cellSize, size_t frequency)
        {
            _window = std::make_unique<sf::RenderWindow>(sf::VideoMode(x * cellSize, y * cellSize), "MyWindow");
            _font = sf::Font();
            _font.loadFromFile("./monoFont.ttf");
            _text = sf::Text();
            _window->setFramerateLimit(frequency);
            _text.setFont(_font);
            _text.setCharacterSize(cellSize);
            _text.setFillColor(sf::Color(0, 0, 0));
        }

        void sfmlLibrary::deleteWindow()
        {
            _window->close();
        }

        std::vector<events_e> sfmlLibrary::getEvents() const
        {
            std::vector<events_e> vec = {};
            sf::Event events;

            while (_window->pollEvent(events)) {
                if (events.type == sf::Event::Closed)
                    vec.push_back(EXIT);
                if (events.type == sf::Event::KeyPressed) {
                    if (events.key.code == sf::Keyboard::Up)
                        vec.push_back(UP);
                    if (events.key.code == sf::Keyboard::Down)
                        vec.push_back(DOWN);
                    if (events.key.code == sf::Keyboard::Left)
                        vec.push_back(LEFT);
                    if (events.key.code == sf::Keyboard::Right)
                        vec.push_back(RIGHT);
                    if (events.key.code == sf::Keyboard::R)
                        vec.push_back(RESTART);
                    if (events.key.code == sf::Keyboard::E)
                        vec.push_back(EXIT);
                    if (events.key.code == sf::Keyboard::Q)
                        vec.push_back(MENU);
                    if (events.key.code == sf::Keyboard::K)
                        vec.push_back(PREV_GRAPH);
                    if (events.key.code == sf::Keyboard::L)
                        vec.push_back(RUN_GRAPH);
                    if (events.key.code == sf::Keyboard::M)
                        vec.push_back(NEXT_GRAPH);
                    if (events.key.code == sf::Keyboard::F)
                        vec.push_back(PREV_GAME);
                    if (events.key.code == sf::Keyboard::G)
                        vec.push_back(RUN_GAME);
                    if (events.key.code == sf::Keyboard::H)
                        vec.push_back(NEXT_GAME);
                }
            }
            return (vec);
        }

        void sfmlLibrary::putBackground(char r, char g, char b) {
            _window->clear(sf::Color(r, g, b));
        }

        void sfmlLibrary::displayTile(int x, int y, char c)
        {
            _text.setString(c);
            _text.setPosition(x * 16, y * 16);
            _window->draw(_text);
        }

        void sfmlLibrary::playSound(std::string song)
        {
            (void)song;
        }

        void sfmlLibrary::update()
        {
            _window->display();
            _window->clear(sf::Color::White);
        }

        std::string sfmlLibrary::getName() const
        {
            return ("SFML");
        }

        extern "C" ILibrary *createGraph()
        {
            return new sfmlLibrary;
        }

        extern "C" void destroyGraph(ILibrary *d)
        {
            delete d;
        }
    }
}