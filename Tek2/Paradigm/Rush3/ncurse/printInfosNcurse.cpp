/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** printInfosNcurse
*/

#include <ncurses.h>
#include "../AllMonitors.hpp"
#include "../InfoModule.hpp"
#include "../CoreInfo.hpp"
#include <tgmath.h>
#include <stdlib.h>

std::string roundToDecimal(double value, int dec)
{
    std::string valueAsStr(std::to_string(value));
    return valueAsStr.substr(0, valueAsStr.find('.') + dec + 1);
}

std::string printInfo()
{
    InfoModule mod;
    std::string top = "";
    for (int i = 0; i < COLS; i++)
        top += "-";
    mvprintw(0, 0, top.c_str());
    mvprintw(1, (COLS / 2) - (mod.getTitle().length() / 2), mod.getTitle().c_str());
    mvprintw(2, 2, mod.getOperatingSystem().c_str());
    mvprintw(2, mod.getOperatingSystem().length() + 3, mod.getKernelVersion().c_str());
    mvprintw(3, 2, mod.getHostname().c_str());
    mvprintw(3, mod.getHostname().length() + 3, mod.getUsername().c_str());
    mvprintw(4, 2, mod.getDateTime().c_str());
    mvprintw(5, 0, top.c_str());
    return top;
}

void printSingleCPUInfo(CoreInfo core, int indexToPrint, int indexCore)
{
    std::string message("Core: " + std::to_string(indexCore) + " | Model: " + (core._model == "" ? "Error" : core._model.c_str()) + " | Frequency: " + roundToDecimal(core._frequency, 2) + "MHz | Usage: " + roundToDecimal(core._percentage, 2) + "%%");
    mvprintw(indexToPrint, 2, message.c_str());
}

int printCPUUsage(std::string delim, AllMonitors core)
{
    std::string nbCores("Number of cores: " + std::to_string(core.getNbCore()));
    std::string CoreUsage("General Usage: " + roundToDecimal(core.getPercentageUse(), 2) + "%% free");
    mvprintw(6, COLS / 2 - core.getTitle().length() / 2, core.getTitle().c_str());
    mvprintw(7, 2, nbCores.c_str());
    mvprintw(8, 2, CoreUsage.c_str());
    for (size_t i = 0; i < core.getNbCore(); i++)
        printSingleCPUInfo(core.getCoreInfo()[i], i + 9, i);
    mvprintw(9 + core.getNbCore(), 0, delim.c_str());
    return (9 + core.getNbCore() + 1);
}

int printRamUsage(int index, AllMonitors core)
{
    std::string title("RAM infos");
    std::string delim;
    std::string mess("RAM Used " + roundToDecimal(core.getRamUsed(), 2) + " Gb / " + roundToDecimal(core.getRamTotal(), 2) + " Gb Total");
    for (int i = 0; i < COLS / 2; i++)
        delim += "-";
    mvprintw(index, COLS / 2 - title.length() / 2, title.c_str());
    mvprintw(index + 1, 2, mess.c_str());
    mvprintw(index + 2, COLS / 4, delim.c_str());
    return index + 3;
}

int printNetworkInfo(int index, AllMonitors core)
{
    std::string message("Up " + roundToDecimal(core.getNetwork().getUp(), 2) + " Mb | Down " + roundToDecimal(core.getNetwork().getDown(), 2) + "Mb");
    std::string title("Network infos");
    std::string delim;
    for (int i = 0; i < COLS / 2; i++)
        delim += "-";
    mvprintw(index, COLS / 2 - title.length() / 2, title.c_str());
    mvprintw(index + 1, 2, message.c_str());
    mvprintw(index + 2, COLS / 4, delim.c_str());
    return index + 3;
}

int printStockageInfo(int index, AllMonitors core)
{
    double valuePercent = core.getDiskAvail() / core.getDiskFree() * 100;

    std::string message("Available " + roundToDecimal(core.getDiskAvail(), 2) + " Gb | All " + roundToDecimal(core.getDiskFree(), 2) + " Gb | " + roundToDecimal(100.00 - valuePercent, 2) + "%%");
    std::string title("Stockage infos");
    std::string delim;
    for (int i = 0; i < COLS / 2; i++)
        delim += "-";
    mvprintw(index, COLS / 2 - title.length() / 2, title.c_str());
    mvprintw(index + 1, 2, message.c_str());
    mvprintw(index + 2, COLS / 4, delim.c_str());
    return index + 3;
}
