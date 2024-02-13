/*
** EPITECH PROJECT, 2022
** Project
** File description:
** stockpile
*/

#include "stockpile.hpp"
#include <iostream>
#include <criterion/criterion.h>

Test(stockpile, NoStock)
{
    stockpile s(0);
    pizza mypizz(Margarita, S);

    cr_assert((s >= mypizz) == false);
}

Test(stockpile, EnoughStock)
{
    stockpile s(5);
    pizza mypizz(Margarita, S);

    cr_assert((s >= mypizz) == true);
}

Test(stockpile, SubstractPizzaGood)
{
    stockpile s(5);
    pizza mypizz(Margarita, S);
    std::vector<size_t> res = {4, 4, 4, 5, 5, 5, 5, 5, 5};

    s -= mypizz;
    cr_assert(s.getStockpile() == res);
}

Test(stockpile, SubstractPizzaBad)
{
    stockpile s(1);
    pizza mypizz(Regina, S);
    std::vector<size_t> res = {0, 0, 0, 0, 0, 1, 1, 1, 1};

    s -= mypizz;
    s -= mypizz;
    cr_assert(s.getStockpile() == res);
}

Test(stockpile, SubstractMultipleTypePizza)
{
    stockpile s(5);
    pizza pizza_margarita(Margarita, XXL);
    pizza pizza_regina(Regina, S);
    std::vector<size_t> res = {3, 3, 3, 4, 4, 5, 5, 5, 5};

    s -= pizza_regina;
    s -= pizza_margarita;
    cr_assert(s.getStockpile() == res);
}

Test(stockpile, IncrementIngredients)
{
    stockpile s(5);
    std::vector<size_t> res = {6, 6, 6, 6, 6, 6, 6, 6, 6};

    s.IncrementIngredients();
    cr_assert(s.getStockpile() == res);
}

Test(stockpile, UseAndIncrementIngredients)
{
    stockpile s(5);
    std::vector<size_t> res = {3, 3, 3, 4, 4, 6, 6, 6, 6};
    pizza pizza_margarita(Margarita, XXL);
    pizza pizza_regina(Regina, S);

    s -= pizza_regina;
    s -= pizza_regina;
    s -= pizza_margarita;
    s.IncrementIngredients();
    cr_assert(s.getStockpile() == res);
}