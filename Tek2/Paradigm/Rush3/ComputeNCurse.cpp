/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** ComputeNCurse
*/

#include <ncurses.h>
#include <string>
#include "InfoModule.hpp"
#include "AllMonitors.hpp"
#include <iostream>

void initialize_ncurses(void)
{
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    refresh();
}

void printInfo(void)
{
    InfoModule mod;
    std::string top = "";
    int maxWidth = std::max(mod.getHostname().length() + mod.getUsername().length(), mod.getOperatingSystem().length() + mod.getKernelVersion().length());
    for (int i = 0; i < maxWidth + 3; i++)
        top += "-";
    mvprintw(1, 1, top.c_str());
    mvprintw(2, 2, mod.getTitle().c_str());
    mvprintw(3, 2, mod.getOperatingSystem().c_str());
    mvprintw(3, mod.getOperatingSystem().length() + 3, mod.getKernelVersion().c_str());
    mvprintw(4, 2, mod.getHostname().c_str());
    mvprintw(4, mod.getHostname().length() + 3, mod.getUsername().c_str());
    mvprintw(5, 2, mod.getDateTime().c_str());
    mvprintw(6, 1, top.c_str());
    for (int i = 1; i <= 6; i++) {
        mvprintw(i, 1, "|");
        mvprintw(i, maxWidth + 3, "|");
    }
}

void printCPUUsage(void)
{
    AllMonitors core;
    core.setAllInfo();
    std::string nbCores("Number of cores: " + std::to_string(core.getNbCore()));
    double usage = core.getPercentageUse();
    std::string coreUsage("General Usage: " + (usage > 0 ? std::to_string(usage) + "%" : "Error"));
    mvprintw(7, 2, nbCores.c_str());
    mvprintw(8, 2, coreUsage.c_str());
}

void computeNcurse(void)
{
    std::string message("Enlarge the terminal to play");
    initialize_ncurses();
    while (1) {
        clear();
        if (LINES < 20 || COLS < 85)
            mvprintw(LINES / 2, COLS / 2 - message.length() / 2, message.c_str());
        else {
            printInfo();
            printCPUUsage();
        }
        refresh();
    }
}
