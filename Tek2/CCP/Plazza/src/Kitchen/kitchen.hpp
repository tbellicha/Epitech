/*
** EPITECH PROJECT, 2022
** B-CCP-400-NAN-4-1-theplazza-tanguy.bellicha
** File description:
** kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "cook.hpp"
#include "stockpile.hpp"
#include "message.hpp"
#include <thread>

class kitchen {

  public:
    enum state { IDLE, WORKING };
    kitchen(size_t, float, size_t, int);
    ~kitchen();
    void update(message);
    state getState(void) const;
    std::vector<size_t> getStock(void) const;
    int getNum(void) const;
    int checkAvailability(void);
    size_t getUpdate() const;
    void setUpdate(size_t);
    cook *getLeastBusyCook(void);
    size_t getIngrCooldown(void) const;
    stockpile *getIngredients(void) const;

  protected:
    std::vector<cook *> _cooks;
    stockpile *_ingredients;
    float _cookMult;
    size_t _ingrCooldown;
    int _num;
    size_t _update;
    std::vector<pizza> _pizzas;
    kitchen::state _state;
};

#endif /* !KITCHEN_HPP_ */
