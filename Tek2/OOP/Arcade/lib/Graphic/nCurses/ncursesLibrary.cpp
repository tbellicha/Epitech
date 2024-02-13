/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Main
*/

#include "ncursesLibrary.hpp"

namespace arcade
{
    namespace graphical
    {
        ncursesLibrary::ncursesLibrary()
        {
        }

        ncursesLibrary::~ncursesLibrary()
        {
        }

        void ncursesLibrary::createWindow(size_t x, size_t y, size_t cellSize, size_t frequency)
        {
            (void)x;
            (void)y;
            (void)cellSize;
            (void)frequency;
            initscr();
            keypad(stdscr,TRUE);
            noecho();
            curs_set(0);
            refresh();
            nodelay(stdscr, true);
        }

        void ncursesLibrary::deleteWindow()
        {
            endwin();
        }

        std::vector<events_e> ncursesLibrary::getEvents() const
        {
            std::vector<events_e> vec = {};
            int key = getch();

            if (key == KEY_UP)
                vec.push_back(UP);
            if (key == KEY_DOWN)
                vec.push_back(DOWN);
            if (key == KEY_LEFT)
                vec.push_back(LEFT);
            if (key == KEY_RIGHT)
                vec.push_back(RIGHT);
            if (key == 'r')
                vec.push_back(EXIT);
            if (key == 'e')
                vec.push_back(RESTART);
            if (key == 'q')
                vec.push_back(MENU);
            if (key == 'k')
                vec.push_back(PREV_GRAPH);
            if (key == 'l')
                vec.push_back(RUN_GRAPH);
            if (key == 'm')
                vec.push_back(NEXT_GRAPH);
            if (key == 'f')
                vec.push_back(PREV_GAME);
            if (key == 'g')
                vec.push_back(RUN_GAME);
            if (key == 'h')
                vec.push_back(NEXT_GAME);
            return vec;
        }

        void ncursesLibrary::putBackground(char r, char g, char b)
        {
            (void)r;
            (void)g;
            (void)b;
        }

        void ncursesLibrary::displayTile(int x, int y, char c)
        {
            mvprintw(y, x, "%c", c);
        }

        void ncursesLibrary::playSound(std::string song)
        {
            (void)song;
        }

        void ncursesLibrary::update()
        {
            refresh();
            clear();
        }

        std::string ncursesLibrary::getName() const
        {
            return "ncurses";
        }

        extern "C" ILibrary *createGraph()
        {
            return new ncursesLibrary;
        }

        extern "C" void destroyGraph(ILibrary *d)
        {
            delete d;
        }
    }
}