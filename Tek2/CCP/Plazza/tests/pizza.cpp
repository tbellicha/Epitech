/*
** EPITECH PROJECT, 2022
** Project
** File description:
** pizza
*/

#include "pizza.hpp"
#include <criterion/criterion.h>

Test(pizza, Margarita)
{
    pizza mypizz(Margarita, S);

    cr_assert(mypizz.getPizzaType() == Margarita);
}

Test(pizza, Regina)
{
    pizza mypizz(Regina, S);

    cr_assert(mypizz.getPizzaType() == Regina);
}

Test(pizza, S)
{
    pizza mypizz(Regina, S);

    cr_assert(mypizz.getPizzaSize() == S);
}

Test(pizza, XXL)
{
    pizza mypizz(Regina, XXL);

    cr_assert(mypizz.getPizzaSize() == XXL);
}

Test(pizza, MargaritaMultiplier)
{
    pizza mypizz(Margarita, XXL);

    cr_assert(mypizz.getCookTime() == 1);
}

Test(pizza, ReginaMultiplier)
{
    pizza mypizz(Regina, XXL);

    cr_assert(mypizz.getCookTime() == 2);
}

Test(pizza, AmericanaMultiplier)
{
    pizza mypizz(Americana, XXL);

    cr_assert(mypizz.getCookTime() == 2);
}


Test(pizza, FantasiaMultiplier)
{
    pizza mypizz(Fantasia, XXL);

    cr_assert(mypizz.getCookTime() == 4);
}