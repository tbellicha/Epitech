/*
** EPITECH PROJECT, 2022
** B-CCP-400-NAN-4-1-theplazza-tanguy.bellicha
** File description:
** kitchen
*/

#include "kitchen.hpp"
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>
#include "fork.hpp"
#include "shell.hpp"

static int updates = 0;

/**
 *@brief Construct a new Kitchen:: Kitchen object
 *@param cooks
 *@param cookMult
 *@param ingrCooldown
 *@param num
 */
kitchen::kitchen(size_t cooks, float cookMult, size_t ingrCooldown, int num)
{
    _ingredients = new stockpile(5);
    for (size_t i = 0; i < cooks; i++) {
        _cooks.push_back(new cook(_ingredients, cookMult));
    }
    _cookMult = cookMult;
    _ingrCooldown = ingrCooldown;
    _num = num;
    _state = kitchen::WORKING;
    std::cout << "Kitchen " << _num << " just opened!" << std::endl;
}

/**
 *@brief Destroy the Kitchen:: Kitchen object
 */
kitchen::~kitchen(void)
{
    for (size_t i = 0; i < _cooks.size(); i++)
        delete _cooks[i];
    std::cout << "Kitchen " << _num << " is closed!" << std::endl;
}

/**
 *@brief starts the cook loop
 *@param cook the cook to start
 */
void startCook(cook *cook)
{
    cook->update();
    exit(0);
}

/**
 *@brief starts the cook update loop in a thread
 *
 *@param cook the cook which will be starting his loop
 **/
std::thread cook_thread(cook *cook)
{
    std::thread cooks(startCook, cook);

    return cooks;
}

void sigHandler(int sig)
{
    if (sig == SIGUSR1) {
        updates += 1;
    }
}

void checkUpdate(kitchen *kitchen)
{
    forkPid fork;

    fork.setSignal(sigHandler);
    while (kitchen->getState() == kitchen::WORKING) {
        fork.waitForIt();
        usleep(300);
    }
}

std::vector<std::string> stringToVec(std::string str)
{
    std::vector<std::string> vec;
    std::string tmp;

    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            vec.push_back(tmp);
            tmp.clear();
        } else
            tmp += str[i];
    }
    vec.push_back(tmp);
    return vec;
}

void ingredientThread(kitchen *kitchen)
{
    clock_t t;
    clock_t current;

    t = clock();
    while (kitchen->getState() == kitchen::WORKING) {
        current = clock() - t;
        if ((((float)current) / CLOCKS_PER_SEC) * 1000 / 3.75 >= kitchen->getIngrCooldown()) {
            t = clock();
            kitchen->getIngredients()->IncrementIngredients();
        }
    }
}

/**
 *@brief updates kitchen by handling cooks and orders
 */
void kitchen::update(message queue)
{
    std::thread checkUpdateThread(checkUpdate, this);
    std::vector<std::thread> cookThreads;
    std::thread stockpileThread(ingredientThread, this);
    std::vector<std::string> orders;
    std::vector<pizza> pizzas;
    std::string order;
    shell parser;

    for (size_t i = 0; i < _cooks.size(); i++) {
        cookThreads.push_back(cook_thread(_cooks[i]));
    }
    while (1) {
        if (updates > 0) {
            queue >> order;
            usleep(5000);
            if (order == "KILL") {
                _state = kitchen::IDLE;
                for (size_t i = 0; i < _cooks.size(); i++)
                    _cooks[i]->setClose(true);
                break;
            }
            if (order == "STATUS") {
                std::cout << "Kitchen " << _num << " is working" << std::endl;
                std::cout << "Ingredients:" << std::endl;
                _ingredients->printStockpile();
                std::cout << "Current occupancy is: " << checkAvailability() << std::endl;
            } else if (order == "AVAILABILITY") {
                queue << std::to_string(checkAvailability());
            } else {
                orders = stringToVec(order);
                pizzas = parser.parseOrder(orders);
                getLeastBusyCook()->cookPizza(pizzas[0]);
                orders.clear();
            }
            updates--;
        }
    }
    for (size_t i = 0; i < cookThreads.size(); i++) {
        cookThreads[i].join();
    }
    stockpileThread.join();
    checkUpdateThread.join();
}

/**
 *@brief Get the least busy cook.
 *@return cook* the least busy cook.
 */
cook *kitchen::getLeastBusyCook()
{
    cook *leastBusy = _cooks[0];

    for (size_t i = 0; i < _cooks.size(); i++) {
        if (_cooks[i]->getState() == cook::IDLE)
            return _cooks[i];
        if (_cooks[i]->getState() == cook::WORKING && leastBusy->getState() == cook::FULL)
            leastBusy = _cooks[i];
    }
    return leastBusy;
}

/**
 *@brief returns state of kitchen
 *@return Kitchen::state
 */
kitchen::state kitchen::getState(void) const
{
    return _state;
}

/**
 *@brief returns the kitchen id number
 *@return int
 */
int kitchen::getNum(void) const
{
    return _num;
}

/**
 *@brief checks how many cooks are available
 *@return int
 */
int kitchen::checkAvailability(void)
{
    int ret = _cooks.size() * 2;

    for (size_t i = 0; i < _cooks.size(); i++) {
        if (_cooks[i]->getState() == cook::WORKING)
            ret -= 1;
        if (_cooks[i]->getState() == cook::FULL)
            ret -= 2;
    }
    return ret;
}

/**
 *@brief Get the stock of ingredients in the kitchen
 *@return std::vector<size_t> List containing the number of each ingredients
 */
std::vector<size_t> kitchen::getStock(void) const
{
    return _ingredients->getStockpile();
}

/**
 *@brief Get the update boolean
 *
 *@return _update
 */
size_t kitchen::getUpdate() const
{
    return _update;
}

/**
 *@brief Set the update of the kitchen
 *@param bool
 */
void kitchen::setUpdate(size_t update)
{
    _update += update;
}

/**
 *@brief returns the ingr cooldown argument
 *
 *@return size_t
 **/
size_t kitchen::getIngrCooldown() const
{
    return _ingrCooldown;
}

/**
 *@brief get the stockpile object stored in kitchen
 *
 *@return stockpile*
 **/
stockpile *kitchen::getIngredients(void) const
{
    return _ingredients;
}
