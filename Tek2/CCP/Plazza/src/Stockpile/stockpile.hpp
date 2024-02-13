/*
** EPITECH PROJECT, 2022
** Project
** File description:
** stockpile
*/

#ifndef STOCKPILE_HPP_
#define STOCKPILE_HPP_

#include "pizza.hpp"

class stockpile {
  public:
    stockpile(size_t nb);
    ~stockpile();

    bool operator>=(pizza pizza) const;
    stockpile &operator-=(pizza pizza);

    void IncrementIngredients(int nb = 1);
    std::vector<size_t> getStockpile() const;
    void printStockpile() const;

  private:
    std::vector<size_t> _stock;
};

#endif /* !STOCKPILE_HPP_ */
