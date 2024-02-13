/*
** EPITECH PROJECT, 2022
** Project
** File description:
** game
*/

#include "core.hpp"

void runGame(arcade_t* core) {
    std::vector<std::string> tileMap = {};
    std::vector<arcade::graphical::events_e> events = {};
    std::string score = "";

    try {
        core->game.createGame = open_lib<create_game_t>(core->filesGames.at(core->i_game).c_str(), CREATE_SYMBOL_GAME);
        core->game.destroyGame = open_lib<destroy_game_t>(core->filesGames.at(core->i_game).c_str(), DESTROY_SYMBOL_GAME);
    } catch (const arcade::exception::core::Exception& e) {
        std::cout << e.what() << std::endl;
        exit(84);
    }
    core->game.gameLib = core->game.createGame();
    core->game.gameLib->start();
    while (1) {
        tileMap = core->game.gameLib->getTilemap();
        events = core->graph.graphLib->getEvents();
        handleGameEvents(core, events);
        for (size_t y = 0; y < tileMap.size(); y++) {
            for (size_t x = 0; x < tileMap[y].size(); x++) {
                core->graph.graphLib->displayTile(x, y, tileMap[y][x]);
            }
        }
        core->graph.graphLib->update();
        core->game.gameLib->update(events);
        score = std::string("Score:");
        for (size_t i = 0; i < score.size(); i++)
            core->graph.graphLib->displayTile(10 + i, 30, score[i]);
        score = std::to_string(core->game.gameLib->getScore());
        for (size_t i = 0; i < score.size(); i++)
            core->graph.graphLib->displayTile(16 + i, 30, score[i]);
        usleep(400000);
        switch(core->game.gameLib->getGameState()) {
            case arcade::game::gameState::OVER:
                core->game.gameLib->reset();
                break;

            case arcade::game::gameState::EXIT:
                displayMenu(core);
                return ;

            default: break;
        }
    }
}