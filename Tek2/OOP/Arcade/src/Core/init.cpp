/*
** EPITECH PROJECT, 2022
** Project
** File description:
** init
*/

#include "core.hpp"

bool checkArgs(int argc, char** argv)
{
    if (argc != 2)
        throw arcade::exception::core::InvalidArguments("You must enter 1 graphical library.");
    if (std::string(argv[1]) == std::string("-h")) {
        std::cout << "Usage: ./arcade [graphical library]" << std::endl;
        std::cout << "\nMenu keys :" << std::endl;
        std::cout << "\t- F\t: Previous game" << std::endl;
        std::cout << "\t- G\t: Launch game" << std::endl;
        std::cout << "\t- H\t: Next game" << std::endl;
        std::cout << "\t- K\t: Previous graphical library" << std::endl;
        std::cout << "\t- L\t: Launch graphical library" << std::endl;
        std::cout << "\t- M\t: Next graphical library" << std::endl;
        std::cout << "\nGame keys :" << std::endl;
        std::cout << "\t- UP\t: Go up" << std::endl;
        std::cout << "\t- RIGHT\t: Go right" << std::endl;
        std::cout << "\t- DOWN\t: Go down" << std::endl;
        std::cout << "\t- LEFT\t: Go left" << std::endl;
        std::cout << "\t- E\t: Exit" << std::endl;
        std::cout << "\t- R\t: Restart" << std::endl;
        std::cout << "\t- Q\t: Go back to menu" << std::endl;
        exit(0);
    }
    return true;
}

arcade_t initStruct(void) {
    arcade_t my_struct;

    my_struct.game.createGame = nullptr;
    my_struct.game.destroyGame = nullptr;
    my_struct.game.gameLib = nullptr;
    my_struct.graph.createGraph = nullptr;
    my_struct.graph.destroyGraph = nullptr;
    my_struct.graph.graphLib = nullptr;
    my_struct.filesGraph = {};
    my_struct.filesGames = {};
    my_struct.i_graph = 0;
    my_struct.i_game = 0;
    return my_struct;
}