/*
** EPITECH PROJECT, 2022
** B-CCP-400-NAN-4-1-theplazza-tanguy.bellicha
** File description:
** shell
*/

#include "shell.hpp"

/**
 * @brief Parses the input and creates a list of pizzas
 * @param std::string
 * @return std::vector<pizza>
 * @throw exception::shell::InvalidPizzaType
 * @throw exception::shell::InvalidPizzaSize
 * @throw exception::shell::InvalidPizzaNumber
 */
std::vector<pizza> shell::parseOrder(std::vector<std::string> order) const
{
    std::vector<std::string> valid_pizza_types = {"regina", "margarita", "americana", "fantasia"};
    std::vector<std::string> valid_pizza_sizes = {"S", "M", "L", "XL", "XXL"};
    bool error = true;
    PizzaType_e pizza_type;
    PizzaSize_e pizza_size;
    size_t nb_pizza;
    std::vector<pizza> pizzas;

    for (int i = 0; i < (int)valid_pizza_types.size(); i++) {
        std::transform(order[INDEX_PIZZA_TYPE].begin(), order[INDEX_PIZZA_TYPE].end(), order[INDEX_PIZZA_TYPE].begin(), ::tolower);
        if (order[INDEX_PIZZA_TYPE] == valid_pizza_types[i]) {
            error = false;
            pizza_type = (PizzaType_e)pow(2, i);
            break;
        }
    }
    if (error)
        throw exception::pizza::InvalidPizzaType("Invalid pizza type: " + order[INDEX_PIZZA_TYPE]);
    error = true;
    for (int i = 0; i < (int)valid_pizza_sizes.size(); i++) {
        if (order[INDEX_PIZZA_SIZE] == valid_pizza_sizes[i]) {
            error = false;
            pizza_size = (PizzaSize_e)pow(2, i);
            break;
        }
    }
    if (error)
        throw exception::pizza::InvalidPizzaSize("Invalid pizza size: " + order[INDEX_PIZZA_SIZE]);
    error = false;
    if (order[INDEX_PIZZA_NBR][0] == 'x' && order[INDEX_PIZZA_NBR].size() > 1) {
        for (int i = 1; i < (int)order[INDEX_PIZZA_NBR].size(); i++) {
            if (order[INDEX_PIZZA_NBR][i] < '0' || order[INDEX_PIZZA_NBR][i] > '9') {
                error = true;
                break;
            }
        }
        if (!error)
            nb_pizza = (size_t)std::stoi(order[INDEX_PIZZA_NBR].substr(1));
    }
    if (error)
        throw exception::pizza::InvalidPizzaNumber("Incorrect pizza number: " + order[INDEX_PIZZA_NBR]);
    for (size_t i = 0; i < nb_pizza; i++) {
        pizza pizzas_order(pizza_type, pizza_size);
        pizzas.push_back(pizzas_order);
    }
    return pizzas;
}

std::string getIngredientString(Ingredients_e ingredients)
{
    std::vector<std::string> ingredients_str = {"Doe", "Tomato", "Gruyere", "Ham", "Mushrooms", "Steak", "Eggplant", "Goat Cheese"};

    for (int i = 0; i < (int)ingredients_str.size(); i++)
        if (ingredients == (Ingredients_e)pow(2, i))
            return ingredients_str[i];
    return "";
}

/**
 * @brief Executes status, that displays the kitchens status, including the current occupancy of the cooks, as well as theirs stocks of ingredients.
 * @param plazza* Pointer to main class
 * @param shell* Pointer to current shell
 * @return void
 */
void exec_status(plazza *myplazza)
{
    myplazza->setStatus(true);
}

/**
 * @brief Executes exit, that ends the program
 * @param void
 * @return void
 */
void exec_exit(plazza *myplazza)
{
    (void)myplazza;
    exit(0);
}

/**
 * @brief Call the function corresponding to the index of command
 * @param int
 * @return void
 */
void execute_command(int i, plazza *myplazza)
{
    void (*func[COMMANDS_NB])(plazza * myplazza) = {&exec_status, &exec_exit};

    (*func[i])(myplazza);
}

/**
 * @brief Check for any command in the input
 * @param std::vector<std::string>
 * @return bool
 */
bool shell::checkCommand(std::vector<std::string> input)
{
    std::string command = "";
    const char *cmds[COMMANDS_NB] = {"status", "exit"};

    if (input.size() > 1)
        return false;
    command = input[0];
    for (int i = 0; i < COMMANDS_NB; i++) {
        if (command == cmds[i]) {
            execute_command(i, _plazza);
            return true;
        }
    }
    return false;
}

/**
 * @brief Read input from the user, and execute command if its a valid command, or add pizzas in consequence
 */
void shell::handleInput(plazza *plazza)
{
    std::string input, T;
    getline(std::cin, input);

    int count = 0;
    std::vector<std::string> input_arr;
    std::vector<std::string> order;
    std::string token;
    std::stringstream ss(input);
    std::vector<pizza> cur_pizzas;
    _plazza = plazza;
    if (std::cin.eof()) {
        exit(0);
        plazza->setStop(true);
    }
    while (getline(ss, token, CHAR_SEPARATOR)) {
        count = 0;
        input_arr.push_back(token);
        order.clear();
        std::stringstream ss2(token);
        while (getline(ss2, token, ' ')) {
            if (token == "")
                continue;
            count++;
            order.push_back(token);
        }
        if (checkCommand(order)) {
            // Execute a command (status, exit...)
            continue;
        }
        if (count != 3)
            throw exception::shell::InvalidNbrArgumentInOrder("Invalid number of arguments for a command (expected 3)");
        try {
            cur_pizzas = parseOrder(order);
            for (int i = 0; i < (int)cur_pizzas.size(); i++) {
                plazza->addPizza(cur_pizzas[i]);
            }
        } catch (const exception::pizza::Exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}
