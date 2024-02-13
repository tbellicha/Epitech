/*
** EPITECH PROJECT, 2022
** Project
** File description:
** plazza
*/

#include "plazza.hpp"
#include "fork.hpp"
#include "shell.hpp"

/**
 * @brief Construct a new plazza object
 *
 * @param mult
 * @param nb_cooks
 * @param time
 */
plazza::plazza(float mult, size_t nb_cooks, size_t time)
{
    _mult = mult;
    _nb_cooks = nb_cooks;
    _time = time;
    _newPizzas = false;
    _pizzas.clear();
}

/**
 * @brief Destroy the plazza object
 *
 */
plazza::~plazza()
{
}

/**
 * @brief Does the plazza work
 *
 */
void mainLoop(plazza *plazza)
{
    std::vector<pizza> mypizzas;
    message queue;
    forkPid myfork;
    std::vector<int> mypids;
    std::vector<int> kitchens;
    std::vector<clock_t> lastActivity;
    std::string available;
    size_t tmp;
    logs mylogs;

    mylogs.clearLogs();
    while (!plazza->getStop()) {
        if (plazza->getNewPizzas()) {
            plazza->setNewPizzas(false);
            for (size_t i = 0; i < plazza->getPizzas().size(); i++) {
                mylogs.addLog("Order " + std::to_string(plazza->getPizzaID()) + ": " + plazza->getPizzas()[i].getPizzaTypeString() + " " + plazza->getPizzas()[i].getPizzaSizeString());
                plazza->setPizzaID(plazza->getPizzaID() + 1);
            }
            tmp = 0;
            for (size_t i = 0; i < plazza->getKitchens().size(); i++) {
                queue << "AVAILABILITY";
                kill(mypids[i], SIGUSR1);
                usleep(5000);
                queue >> available;
                kitchens.push_back(atoi(available.c_str()));
                tmp += atoi(available.c_str());
            }
            for (; tmp < plazza->getPizzas().size(); tmp += plazza->getNbCooks() * 2) {
                plazza->newKitchen(&mylogs);
                myfork.forkIt();
                if (myfork.getPid() > 0) {
                    mypids.push_back(myfork.getPid());
                    kitchens.push_back(plazza->getNbCooks() * 2);
                    usleep(5000);
                } else {
                    plazza->getKitchens().back()->update(queue);
                    exit(0);
                }
            }
            plazza->send_orders(queue, mypids, kitchens);
            plazza->clearPizzas();
        }
        kitchens.clear();
        if (plazza->getStatus() == true) {
            plazza->setStatus(false);
            for (size_t i = 0; i < plazza->getKitchens().size(); i++) {
                queue << "STATUS";
                kill(mypids[i], SIGUSR1);
                usleep(5000);
            }
        }
    }
    for (size_t i = 0; i < plazza->getKitchens().size(); i++) {
        queue << "KILL";
        kill(mypids[i], SIGUSR1);
        usleep(30000);
        delete plazza->getKitchens()[i];
    }
    queue.unlinkClose();
}

void shellStart(plazza *plazza)
{
    shell shell;

    while (1) {
        try {
            shell.handleInput(plazza);
            plazza->setNewPizzas(true);
        } catch (const exception::shell::Exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
};

/**
 * @brief Setter of the PizzaID
 * @param size_t value of PizzaID
 */
void plazza::setPizzaID(size_t pizzaID)
{
    _PizzaID = pizzaID;
}

/**
 * @brief Getter of the PizzaID
 * @return size_t value of PizzaID
 */
size_t plazza::getPizzaID(void) const
{
    return _PizzaID;
}

/**
 * @brief Setter of stop
 * @param bool value of stop
 */
void plazza::setStop(bool value)
{
    _stop = value;
}

/**
 * @brief Getter of stop
 * @return bool value of stop
 */
bool plazza::getStop(void) const
{
    return _stop;
}

/**
 * @brief Start the plazza program by running the main loop and the shell
 *
 */
void plazza::start(void)
{
    std::thread shell(shellStart, this);
    mainLoop(this);
    shell.detach();
}

/**
 *@brief Get the Least Busy Kitchen object index
 *
 *@param kitchens
 *@return the index of the least busy kitchen
 **/
size_t getLeastBusyKitchen(std::vector<int> kitchens)
{
    size_t tmp = 0;

    for (size_t i = 1; i < kitchens.size(); i++)
        if (kitchens[tmp] < kitchens[i])
            tmp = i;
    return tmp;
}

/**
 * @brief Send orders to the kitchen
 *
 * @param message the message queue
 */
void plazza::send_orders(message queue, std::vector<int> mypids, std::vector<int> kitchens)
{
    size_t kitchen;
    forkPid fork;

    for (size_t i = 0; i < _pizzas.size(); i++) {
        kitchen = getLeastBusyKitchen(kitchens);
        queue << (_pizzas[i].getPizzaTypeString() + " " + _pizzas[i].getPizzaSizeString() + " x1");
        fork.killIt(mypids[kitchen]);
        kitchens[kitchen] -= 1;
        usleep(5000);
    }
}

/**
 * @brief Add pizza to the orders
 *
 * @param pizzas
 */
void plazza::addPizza(pizza pizza)
{
    _pizzas.push_back(pizza);
}

/**
 * @brief Get the kitchens vector
 *
 * @return kitchens vector
 */
std::vector<kitchen *> plazza::getKitchens(void) const
{
    return _kitchens;
}

/**
 * @brief Get the pizzas vector
 *
 * @return pizzas vector
 */
std::vector<pizza> plazza::getPizzas(void) const
{
    return _pizzas;
}

/**
 * @brief Clears the pizzas vector
 */
void plazza::clearPizzas()
{
    _pizzas.clear();
}

/**
 * @brief Get the new pizzas boolean
 *
 * @return true
 * @return false
 */
bool plazza::getNewPizzas(void) const
{
    return _newPizzas;
}

/**
 * @brief Set the new pizzas boolean
 *
 * @param newPizzas
 */
bool plazza::setNewPizzas(bool newPizzas)
{
    return (_newPizzas = newPizzas);
}

/**
 * @brief Get the number of cooks per kitchen
 *
 * @return number of cooks
 */
size_t plazza::getNbCooks(void) const
{
    return _nb_cooks;
}

/**
 *@brief opens a new kitchen
 **/
void plazza::newKitchen(logs *mylogs)
{
    int num = 1;

    for (size_t i = 0; i < _kitchens.size(); i++)
        if (_kitchens[i]->getNum() == num) {
            i = 0;
            num++;
        }
    mylogs->addLog("Creation of kitchen " + std::to_string(num));
    _kitchens.push_back(new kitchen(_nb_cooks, _mult, _time, num));
}

void plazza::setStatus(bool status)
{
    _status = status;
}

bool plazza::getStatus() const
{
    return _status;
}
