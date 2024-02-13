/*
** EPITECH PROJECT, 2022
** B-CCP-400-NAN-4-1-theplazza-tanguy.bellicha
** File description:
** cook
*/

#include "cook.hpp"
#include <unistd.h>
#include <iostream>

/**
 *@brief Construct a new cook::cook object
 *
 *@param stock
 *@param cookTimeMult
 */

cook::cook(stockpile *stock, float cookTimeMult)
{
    _state = cook::IDLE;
    _stockpile = stock;
    _queue.clear();
    _cookTimeMult = cookTimeMult;
}

/**
 *@brief Destroy the cook::cook object
 *
 */

cook::~cook()
{
}

/**
 *@brief Adds pizza to cook queue
 *
 * @param pizza
 */

void cook::cookPizza(pizza pizza)
{
    _queue.push_back(pizza);
    if (_queue.size() == 1)
        _state = cook::WORKING;
    else
        _state = cook::FULL;
}

/**
 *@brief updates cook by handling orders
 *
 */
void cook::update()
{
    while (1) {
        if ((_state == cook::WORKING || _state == cook::FULL) && (*_stockpile) >= _queue[0]) {
            *_stockpile -= _queue[0];
            usleep(_queue[0].getCookTime() * _cookTimeMult * 1000000);
            if (_state == cook::FULL)
                _state = cook::WORKING;
            else
                _state = cook::IDLE;
            _queue.erase(_queue.begin());
        }
        if (_close == true)
            break;
    }
}

/**
 *@brief returns state of cook
 *
 *@return Cook::state
 */

cook::state cook::getState(void) const
{
    return _state;
}

/**
*@brief sets the close to whatever you want it to be
*
*@param close 
**/
void cook::setClose(bool close)
{
    _close = close;
}
