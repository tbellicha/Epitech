/*
** EPITECH PROJECT, 2022
** B-CCP-400-NAN-4-1-theplazza-tanguy.bellicha
** File description:
** shell
*/

#ifndef SHELL_HPP_
#define SHELL_HPP_

#include "pizza.hpp"
#include "plazza.hpp"

#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include "Pizza/PizzaException.hpp"
#include "Shell/ShellException.hpp"
#include <bits/stdc++.h>

#define CHAR_SEPARATOR   ';'
#define INDEX_PIZZA_TYPE 0
#define INDEX_PIZZA_SIZE 1
#define INDEX_PIZZA_NBR  2
#define COMMANDS_NB      2

class shell {
  public:
    void handleInput(plazza *plazza);
    std::vector<pizza> parseOrder(std::vector<std::string> order) const;
    bool checkCommand(std::vector<std::string> input);

  protected:
    plazza *_plazza;

  private:
};

void exec_status(plazza *myplazza);
void exec_exit(plazza *myplazza);
void execute_command(int i, plazza *myplazza);

#endif /* !SHELL_HPP_ */
