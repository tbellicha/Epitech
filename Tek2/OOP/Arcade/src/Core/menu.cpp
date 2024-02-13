/*
** EPITECH PROJECT, 2022
** Project
** File description:
** menu
*/

#include "core.hpp"

void displayMenu(arcade_t* core) {
    core->graph.graphLib->putBackground(255, 255, 255);
    for (size_t curr_game = 0; curr_game < core->filesGames.size(); curr_game++) {
        if (core->filesGames.at(curr_game) == core->filesGames.at(core->i_game))
            core->graph.graphLib->displayTile(1, 4 + curr_game * 2, '>');
        for (size_t curr_let = core->filesGames[curr_game].find('_') + 1; curr_let < core->filesGames[curr_game].find(".so"); curr_let++) {
            core->graph.graphLib->displayTile(1 + curr_let - core->filesGames[curr_game].find('_'), 4 + curr_game * 2, core->filesGames[curr_game][curr_let]);
        }
    }
    for (size_t curr_graph = 0; curr_graph < core->filesGraph.size(); curr_graph++) {
        if (core->filesGraph.at(curr_graph) == core->filesGraph.at(core->i_graph))
            core->graph.graphLib->displayTile(17, 4 + curr_graph * 2, '>');
        for (size_t curr_let = core->filesGraph[curr_graph].find('_') + 1; curr_let < core->filesGraph[curr_graph].find(".so"); curr_let++) {
            core->graph.graphLib->displayTile(17 + curr_let - core->filesGraph[curr_graph].find('_'), 4 + curr_graph * 2, core->filesGraph[curr_graph][curr_let]);
            core->graph.graphLib->displayTile(17 + curr_let - core->filesGraph[curr_graph].find('_'), 4 + curr_graph * 2, core->filesGraph[curr_graph][curr_let]);
        }
    }
    core->graph.graphLib->update();
}