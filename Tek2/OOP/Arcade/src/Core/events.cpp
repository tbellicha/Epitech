/*
** EPITECH PROJECT, 2022
** Project
** File description:
** events
*/

#include "core.hpp"

void handleMenuEvents (arcade_t* core, std::vector<arcade::graphical::events_e> events) {
    for (size_t i = 0; i < events.size(); i++) {
        switch (events[i]) {
            case arcade::graphical::events_e::EXIT:
                if (core->game.gameLib) {
                    core->game.gameLib->exit();
                    core->game.destroyGame(core->game.gameLib);
                    dlclose(core->game.gameLib);
                }
                core->graph.graphLib->deleteWindow();
                core->graph.destroyGraph(core->graph.graphLib);
                dlclose(core->graph.graphLib);
                exit(0);

            case arcade::graphical::events_e::PREV_GAME:
                if (core->i_game > 0) {
                    core->i_game--;
                    displayMenu(core);
                }
                break;

            case arcade::graphical::events_e::RUN_GAME:
                runGame(core);
                displayMenu(core);
                break;

            case arcade::graphical::events_e::NEXT_GAME:
                if (core->i_game < core->filesGames.size() - 1) {
                    core->i_game++;
                    displayMenu(core);
                }
                break;

            case arcade::graphical::events_e::PREV_GRAPH:
                if (core->i_graph > 0) {
                    core->i_graph--;
                    displayMenu(core);
                }
                break;

            case arcade::graphical::events_e::RUN_GRAPH:
                core->graph.graphLib->deleteWindow();
                core->graph.destroyGraph(core->graph.graphLib);
                dlclose(core->graph.graphLib);
                try {
                    core->graph.createGraph = open_lib<create_graph_t>(core->filesGraph[core->i_graph].c_str(), CREATE_SYMBOL_GRAPH);
                    core->graph.destroyGraph = open_lib<destroy_graph_t>(core->filesGraph[core->i_graph].c_str(), DESTROY_SYMBOL_GRAPH);
                } catch (const arcade::exception::core::Exception& e) {
                    std::cout << e.what() << std::endl;
                    exit(84);
                }
                srand(time(NULL));
                core->graph.graphLib = core->graph.createGraph();
                core->graph.graphLib->createWindow(32, 32, 16, 60);
                displayMenu(core);
                break;

            case arcade::graphical::events_e::NEXT_GRAPH:
                if (core->i_graph < core->filesGraph.size() - 1) {
                    core->i_graph++;
                    displayMenu(core);
                }
                break;

            default: break;
        }
    }
}

void handleGameEvents(arcade_t* core, std::vector<arcade::graphical::events_e> events) {
    for (size_t i = 0; i < events.size(); i++) {
        switch (events[i]) {
            case arcade::graphical::events_e::EXIT:
                if (core->game.gameLib) {
                    core->game.gameLib->exit();
                    core->game.destroyGame(core->game.gameLib);
                    dlclose(core->game.gameLib);
                }
                core->graph.graphLib->deleteWindow();
                core->graph.destroyGraph(core->graph.graphLib);
                dlclose(core->graph.graphLib);
                exit(0);

            case arcade::graphical::events_e::RESTART:
                core->game.gameLib->reset();
                break;

            case arcade::graphical::events_e::MENU:
                core->game.gameLib->exit();
                break;

            default: break;
        }
    }
}