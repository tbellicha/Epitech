/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
** File description:
** tests
*/

#include "Peasant.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>

static int powerAttack = -10;
static int powerSpecial = -0;
static int powerRest = 30;

Test(Peasant, example, .init=cr_redirect_stdout)
{
    {
        Peasant peasant("Gildas", 42);
        peasant.damage(50);
        peasant.damage(100);
        peasant.damage(200);
        peasant.rest();
    }

    cr_assert_stdout_eq_str("Gildas goes for an adventure.\nGildas takes 50 damage.\nGildas is out of combat.\nGildas is out of combat.\nGildas is out of combat.\nGildas is back to his crops.\n");
}

Test(Peasant, attack, .init=cr_redirect_stdout)
{
    int init_power = 42;

    Peasant *peasant = new Peasant("Gildas", init_power);
    peasant->attack();

    cr_assert_eq(peasant->getPower(), init_power + powerAttack);
    delete peasant;
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\nGildas tosses a stone.\nGildas is back to his crops.\n");
}

Test(Peasant, special, .init=cr_redirect_stdout)
{
    int init_power = 42;

    Peasant *peasant = new Peasant("Gildas", init_power);
    peasant->special();

    cr_assert_eq(peasant->getPower(), init_power + powerSpecial);
    delete peasant;
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\nGildas doesn't know any special move.\nGildas is back to his crops.\n");
}

Test(Peasant, normal_rest, .init=cr_redirect_stdout)
{
    int init_power = 42;

    Peasant *peasant = new Peasant("Gildas", init_power);
    peasant->rest();

    cr_assert_eq(peasant->getPower(), init_power + powerRest);
    delete peasant;
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\nGildas takes a nap.\nGildas is back to his crops.\n");
}

Test(Peasant, over_rest, .init=cr_redirect_stdout)
{
    int init_power = 80;

    Peasant *peasant = new Peasant("Gildas", init_power);
    peasant->rest();

    cr_assert_eq(peasant->getPower(), 100);
    delete peasant;
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\nGildas takes a nap.\nGildas is back to his crops.\n");
}

Test(Peasant, normal_hit, .init=cr_redirect_stdout)
{
    int init_health = 100;
    int damage = 40;

    Peasant *peasant = new Peasant("Gildas", 100);
    peasant->damage(damage);

    cr_assert_eq(peasant->getHp(), init_health - damage);
    delete peasant;
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\nGildas takes 40 damage.\nGildas is back to his crops.\n");
}

Test(Peasant, final_hit, .init=cr_redirect_stdout)
{
    int damage = 120;

    Peasant *peasant = new Peasant("Gildas", 100);
    peasant->damage(damage);

    cr_assert_eq(peasant->getHp(), 0);
    delete peasant;
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\nGildas is out of combat.\nGildas is back to his crops.\n");
}