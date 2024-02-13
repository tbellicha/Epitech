/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Main
*/

#include "core.hpp"

int main(int argc, char** argv)
{
    std::vector<arcade::graphical::events_e> events = {};
    arcade_t core = initStruct();

    try {
        checkArgs(argc, argv);
        core.graph.createGraph = open_lib<create_graph_t>(argv[1], CREATE_SYMBOL_GRAPH);
        core.graph.destroyGraph = open_lib<destroy_graph_t>(argv[1], DESTROY_SYMBOL_GRAPH);
    } catch (const arcade::exception::core::Exception& e) {
        std::cout << e.what() << std::endl;
        return (84);
    }
    srand(time(NULL));
    core.graph.graphLib = core.graph.createGraph();
    core.graph.graphLib->createWindow(32, 32, 16, 60);
    core.filesGraph = getLibraries(MODE_GRAPH);
    core.filesGames = getLibraries(MODE_GAME);
    displayMenu(&core);
    while (1) {
        events = core.graph.graphLib->getEvents();
        handleMenuEvents(&core, events);
    }
    return 0;
}