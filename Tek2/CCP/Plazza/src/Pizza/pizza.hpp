/*
** EPITECH PROJECT, 2022
** Project
** File description:
** pizza
*/

#ifndef PIZZA_HPP_
#define PIZZA_HPP_

#include <math.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "Pizza/PizzaException.hpp"

typedef enum PizzaType { Regina = 1, Margarita = 2, Americana = 4, Fantasia = 8 } PizzaType_e;

typedef enum PizzaSize { S = 1, M = 2, L = 4, XL = 8, XXL = 16 } PizzaSize_e;

#define NB_INGREDIENTS 9

typedef enum Ingredients {
    Doe,
    Tomato,
    Gruyere,
    Ham,
    Mushrooms,
    Steak,
    Eggplant,
    Goat_Cheese,
} Ingredients_e;

class pizza {
  public:
    pizza(PizzaType_e type, PizzaSize_e size);

    ~pizza();

    PizzaType getPizzaType(void) const;
    PizzaSize getPizzaSize(void) const;
    std::string getPizzaTypeString(void) const;
    std::string getPizzaSizeString(void) const;
    std::vector<size_t> getIngredients(void) const;
    std::string getIngredientString(Ingredients_e ingredients) const;
    size_t getCookTime(void) const;

    void createRegina(void);
    void createMargarita(void);
    void createAmericana(void);
    void createFantasia(void);

  private:
    PizzaType_e _type;
    PizzaSize_e _size;
    size_t _time;
    std::vector<size_t> _ingredients;
};
#endif /* !PIZZA_HPP_ */
