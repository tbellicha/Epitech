/*
** EPITECH PROJECT, 2022
** Project
** File description:
** stockpile
*/

#include "stockpile.hpp"
#include <iostream>

/**
 * @brief Construct a new Stockpile::Stockpile object
 * @param nb Set the number of ingredients
 */
stockpile::stockpile(size_t nb)
{
    _stock.clear();
    for (int i = 0; i < NB_INGREDIENTS; i++)
        _stock.push_back(nb);
}

stockpile::~stockpile()
{
}

/**
 * @brief Check if the stockpile is greater or equal to the pizza
 * @param pizza The pizza to check
 * @return bool True if the stockpile is greater or equal to the pizza
 */
bool stockpile::operator>=(pizza pizza) const
{
    std::vector<size_t> needed = pizza.getIngredients();

    for (int i = 0; i < NB_INGREDIENTS; i++)
        if (needed[i] > _stock[i])
            return false;
    return true;
}

/**
 * @brief Decrements the ingredients of a given pizza
 *
 * @param pizza
 */
stockpile &stockpile::operator-=(pizza pizza)
{
    if (!(*(this) >= pizza))
        return *this;
    // throw exception::stockpile::NotEnoughIngredients("Not enough ingredients");
    for (int i = 0; i < NB_INGREDIENTS; i++)
        _stock[i] -= pizza.getIngredients()[i];
    return *this;
}

/**
 * @brief Increment the number of ingredients in the stockpile
 * @param nb The number of ingredients to increment
 */
void stockpile::IncrementIngredients(int nb)
{
    for (int i = 0; i < (int)_stock.size(); i++)
        _stock[i] += nb;
}

/**
 * @brief Get the stockpile
 * @return std::vector<size_t> The stockpile
 */
std::vector<size_t> stockpile::getStockpile() const
{
    return _stock;
}

/**
 * @brief Print the current state of the stockpile
 */
void stockpile::printStockpile() const
{
    std::cout << "\tDoe: " << _stock[Doe] << std::endl;
    std::cout << "\tTomato: " << _stock[Tomato] << std::endl;
    std::cout << "\tGruyere: " << _stock[Gruyere] << std::endl;
    std::cout << "\tHam: " << _stock[Ham] << std::endl;
    std::cout << "\tMushrooms: " << _stock[Mushrooms] << std::endl;
    std::cout << "\tSteak: " << _stock[Steak] << std::endl;
    std::cout << "\tEggplant: " << _stock[Eggplant] << std::endl;
    std::cout << "\tGoat_Cheese: " << _stock[Goat_Cheese] << std::endl;
}