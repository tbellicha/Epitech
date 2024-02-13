/*
** EPITECH PROJECT, 2022
** Project
** File description:
** plazza
*/

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_

#include <iostream>
#include <string.h>
#include "Args/ArgsException.hpp"
#include "kitchen.hpp"
#include "logs.hpp"
#include "pizza.hpp"

class plazza {
  public:
    plazza(float, size_t, size_t);
    ~plazza();

    void status(void);
    void send_orders(message queue, std::vector<int> mypids, std::vector<int> kitchens);
    void start(void);
    void setPizzas(std::vector<pizza>);
    std::vector<kitchen *> getKitchens(void) const;
    void addPizza(pizza pizza);
    std::vector<pizza> getPizzas(void) const;
    void clearPizzas();
    bool getNewPizzas(void) const;
    bool setNewPizzas(bool);
    size_t getNbCooks(void) const;
    void newKitchen(logs *mylogs);
    void setPizzaID(size_t pizzaID);
    size_t getPizzaID(void) const;
    void setStop(bool value);
    bool getStop(void) const;
    void setStatus(bool status);
    bool getStatus(void) const;

  protected:
    bool _newPizzas;
    bool _status;
    float _mult;
    size_t _nb_cooks;
    size_t _time;
    std::vector<kitchen *> _kitchens;
    std::vector<pizza> _pizzas;
    size_t _PizzaID;
    bool _stop;
};

#endif /* !PLAZZA_HPP_ */
