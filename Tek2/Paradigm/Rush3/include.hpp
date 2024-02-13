/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGRUSH3-johan.chrillesen
** File description:
** include
*/

#ifndef INCLUDE_HPP_
#define INCLUDE_HPP_

#define RETURN_ERROR 84
#include "CoreInfo.hpp"
#include "AllMonitors.hpp"

void computeSFML(void);
void computeNCurse(void);
int printCPUUsage(std::string delim, AllMonitors core);
void printSingleCPUInfo(CoreInfo core, int indexToPrint, int indexCore);
std::string printInfo(void);
int printRamUsage(int index, AllMonitors core);
int printNetworkInfo(int index, AllMonitors core);
int printStockageInfo(int index, AllMonitors core);

#endif /* !INCLUDE_HPP_ */
