/*
** EPITECH PROJECT, 2022
** B-CCP-400-NAN-4-1-theplazza-tanguy.bellicha
** File description:
** cook
*/

#ifndef COOK_HPP_
#define COOK_HPP_

#include <memory>
#include <time.h>
#include <vector>
#include "pizza.hpp"
#include "stockpile.hpp"

class cook {
  public:
    cook(stockpile *, float);
    ~cook();
    enum state { IDLE, WORKING, FULL };
    void cookPizza(pizza pizza);
    void update();
    state getState(void) const;
    void setClose(bool);

  protected:
    cook::state _state;
    std::vector<pizza> _queue;
    float _cookTimeMult;
    stockpile *_stockpile;
    bool _close;
};

#endif /* !COOK_HPP_ */
