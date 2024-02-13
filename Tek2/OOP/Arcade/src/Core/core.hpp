/*
** EPITECH PROJECT, 2022
** Project
** File description:
** core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "../../lib/Games/IGame.hpp"
#include "../../lib/Graphic/ILibrary.hpp"
#include "../Exception/Core/CoreException.hpp"
#include <dlfcn.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

#define CREATE_SYMBOL_GAME "createGame"
#define DESTROY_SYMBOL_GAME "destroyGame"
#define CREATE_SYMBOL_GRAPH "createGraph"
#define DESTROY_SYMBOL_GRAPH "destroyGraph"
#define MODE_GAME 1
#define MODE_GRAPH 2

typedef arcade::game::IGame* create_game_t();
typedef void destroy_game_t(arcade::game::IGame*);
typedef arcade::graphical::ILibrary* create_graph_t();
typedef void destroy_graph_t(arcade::graphical::ILibrary*);

typedef struct graph_s {
    create_graph_t* createGraph;
    destroy_graph_t* destroyGraph;
    arcade::graphical::ILibrary *graphLib;
} graph_t;

typedef struct game_s {
    create_game_t* createGame;
    destroy_game_t* destroyGame;
    arcade::game::IGame *gameLib;
} game_t;

typedef struct arcade_s {
    game_t game;
    graph_t graph;
    std::vector<std::string> filesGraph;
    std::vector<std::string> filesGames;
    size_t i_graph;
    size_t i_game;
} arcade_t;

//------------------------------------- [LIBRARIES] ------------------------------------- //
template <typename T>
T *open_lib(const char* filepath, const char* symbol);
std::vector<std::string> getLibraries(int mode);

//------------------------------------- [GAME] ------------------------------------- //
void runGame(arcade_t* core);

//------------------------------------- [MENU] ------------------------------------- //
void displayMenu(arcade_t* core);

//------------------------------------- [EVENTS] ------------------------------------- //
void handleMenuEvents (arcade_t* core, std::vector<arcade::graphical::events_e> events);
void handleGameEvents (arcade_t* core, std::vector<arcade::graphical::events_e> events);

//------------------------------------- [INIT] ------------------------------------- //
arcade_t initStruct(void);
bool checkArgs(int argc, char** argv);

#endif /* !CORE_HPP_ */