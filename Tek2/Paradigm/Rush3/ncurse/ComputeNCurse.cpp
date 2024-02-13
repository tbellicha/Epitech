/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** ComputeNCurse
*/

#include <ncurses.h>
#include <string>
#include "../include.hpp"
#include <iostream>
#include "../AllMonitors.hpp"
#include "IMonitorDisplay.hpp"
#include <unistd.h>

void initialize_ncurses(void)
{
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
    noecho();
    refresh();
}

void printSides(void)
{
    for (int i = 0; i < LINES; i++) {
        mvprintw(i, 0, "|");
        mvprintw(i, COLS - 1, "|");
    }
}

int getInput(IMonitorDisplay *disp)
{
    switch (getch()) {
    case 'i':
        disp->setDisplayInfo(!disp->getDisplayInfo());
        return 1;
    case 'c':
        disp->setDisplayCPU(!disp->getDisplayCPU());
        return 1;;
    case 'r':
        disp->setDisplayRAM(!disp->getDisplayRAM());
        return 1;
    case 'n':
        disp->setDisplayNetwork(!disp->getDisplayNetwork());
        return 1;
    case 's':
        disp->setDisplayStockage(!disp->getDisplayStockage());
        return 1;
    case 'q':
        return -1;
    default:
        return 0;
    }
}

void computeNCurse(void)
{
    std::string message("Enlarge the terminal to see system info");
    std::string delim;
    IMonitorDisplay disp;
    AllMonitors core;
    initialize_ncurses();
    while (1)
    {
        int indexToPrint = 0;
        printSides();
        if (LINES < 30 || COLS < 110) {
            erase();
            mvprintw(LINES / 2, COLS / 2 - message.length() / 2, message.c_str());
        } else {
            delim = "";
            for (int i = 0; i < COLS; i++)
                delim += '-';
            int input = getInput(&disp);
            if (input == -1)
                break;
            else if (input == 1 || input == 0)
                erase();
            core.setAllInfo();
            if (disp.getDisplayInfo())
                printInfo();
            if (disp.getDisplayCPU())
                indexToPrint = printCPUUsage(delim, core);
            if (indexToPrint == 0)
                indexToPrint = 7;
            if (disp.getDisplayRAM())
                indexToPrint = printRamUsage(indexToPrint, core);
            if (disp.getDisplayNetwork())
                indexToPrint = printNetworkInfo(indexToPrint, core);
            if (disp.getDisplayStockage())
                indexToPrint = printStockageInfo(indexToPrint, core);
            mvprintw(LINES - 1, 2, "Commands Hide/Show | c: CPU | r: RAM | i: Info | n: Network | s: Storage | q: Quit");
        }
        refresh();
    }
}
