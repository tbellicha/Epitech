#include "sdlLibrary.hpp"
#include <iostream>

namespace arcade
{
    namespace graphical
    {
        sdlLibrary::sdlLibrary(/* args */)
        {

        }

        sdlLibrary::~sdlLibrary()
        {

        }
        void sdlLibrary::createWindow(size_t x, size_t y, size_t cellSize, size_t frequency)
        {
            (void)frequency;
            SDL_Init(SDL_INIT_EVERYTHING);
            _window = SDL_CreateWindow("Window", 0, 0, x * cellSize, y * cellSize, SDL_WINDOW_SHOWN);
            _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
            _isRunning = true;
            _width = x;
            _height = y;
            _cellSize = cellSize;
            TTF_Init();
            _font = TTF_OpenFont("monoFont.ttf", 160);
        }

        void sdlLibrary::deleteWindow()
        {
            SDL_DestroyRenderer(_renderer);
            SDL_DestroyWindow(_window);
            TTF_CloseFont(_font);
            TTF_Quit();
        }

        std::vector<events_e> sdlLibrary::getEvents() const
        {
            std::vector<events_e> in;

            auto state = SDL_GetKeyboardState(NULL);
            if (state[SDL_SCANCODE_Q])
                in.push_back(events_e::EXIT);
            if (state[SDL_SCANCODE_UP])
                in.push_back(events_e::UP);
            if (state[SDL_SCANCODE_DOWN])
                in.push_back(events_e::DOWN);
            if (state[SDL_SCANCODE_LEFT])
                in.push_back(events_e::LEFT);
            if (state[SDL_SCANCODE_RIGHT])
                in.push_back(events_e::RIGHT);
            return (in);
        }
        void sdlLibrary::putBackground(char r, char g, char b)
        {
            (void)r;
            (void)g;
            (void)b;
        }
        void sdlLibrary::displayTile(int x, int y, char c)
        {
            //SDL_Rect rect {x * _cellSize, y * _cellSize, _cellSize, _cellSize};

            (void)x;
            (void)y;
            if (c == '#')
                SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 0);
            else if (c == '.')
                SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 0);
            else if (c == ' ')
                SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 0);
            else
                SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 0);
            //SDL_RenderDrawRect(_renderer, &rect);
            SDL_Surface* surface = TTF_RenderText_Solid(_font, &c, {255, 0, 0, 0});
            SDL_Texture * texture = SDL_CreateTextureFromSurface(_renderer, surface);
            SDL_RenderCopy(_renderer, texture, NULL, NULL);
            SDL_RenderPresent(_renderer);
        }

        void sdlLibrary::playSound(std::string song)
        {
            (void)song;
        }

        void sdlLibrary::update()
        {
            SDL_Event event;
            SDL_PollEvent (&event);
            if (event.type == SDL_QUIT)
                this->_isRunning = false;
            SDL_RenderPresent(_renderer);

        }
        std::string sdlLibrary::getName() const
        {
            return ("SDL");
        }

        extern "C" ILibrary *createGraph()
        {
            return new sdlLibrary;
        }

        extern "C" void destroyGraph(ILibrary *d)
        {
            delete d;
        }
    }
}