/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
** File description:
** tests
*/

#include "Knight.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>

static int powerAttack = -10;
static int powerSpecial = -30;
static int powerRest = 50;

Test(Knight, example, .init=cr_redirect_stdout)
{
    {
        Knight knight("Arthur", 20);
        knight.attack();
        knight.special();
        knight.rest();
        knight.special();
        knight.damage(50);
    }

    cr_assert_stdout_eq_str("Arthur goes for an adventure.\nArthur vows to protect the kingdom.\nArthur strikes with his sword.\nArthur is out of power.\nArthur eats.\nArthur impales his enemy.\nArthur takes 50 damage.\nArthur takes off his armor.\nArthur is back to his crops.\n");
}

Test(Knight, attack, .init=cr_redirect_stdout)
{
    int init_power = 42;

    Knight *knight = new Knight("Arthur", init_power);
    knight->attack();

    cr_assert_eq(knight->getPower(), init_power + powerAttack);
    delete knight;
    cr_assert_stdout_eq_str("Arthur goes for an adventure.\nArthur vows to protect the kingdom.\nArthur strikes with his sword.\nArthur takes off his armor.\nArthur is back to his crops.\n");
}

Test(Knight, special, .init=cr_redirect_stdout)
{
    int init_power = 42;

    Knight *knight = new Knight("Arthur", init_power);
    knight->special();

    cr_assert_eq(knight->getPower(), init_power + powerSpecial);
    delete knight;
    cr_assert_stdout_eq_str("Arthur goes for an adventure.\nArthur vows to protect the kingdom.\nArthur impales his enemy.\nArthur takes off his armor.\nArthur is back to his crops.\n");
}

Test(Knight, normal_rest, .init=cr_redirect_stdout)
{
    int init_power = 42;

    Knight *knight = new Knight("Arthur", init_power);
    knight->rest();

    cr_assert_eq(knight->getPower(), init_power + powerRest);
    delete knight;
    cr_assert_stdout_eq_str("Arthur goes for an adventure.\nArthur vows to protect the kingdom.\nArthur eats.\nArthur takes off his armor.\nArthur is back to his crops.\n");
}

Test(Knight, over_rest, .init=cr_redirect_stdout)
{
    int init_power = 80;

    Knight *knight = new Knight("Arthur", init_power);
    knight->rest();

    cr_assert_eq(knight->getPower(), 100);
    delete knight;
    cr_assert_stdout_eq_str("Arthur goes for an adventure.\nArthur vows to protect the kingdom.\nArthur eats.\nArthur takes off his armor.\nArthur is back to his crops.\n");
}

Test(Knight, normal_hit, .init=cr_redirect_stdout)
{
    int init_health = 100;
    int damage = 40;

    Knight *knight = new Knight("Arthur", 100);
    knight->damage(damage);

    cr_assert_eq(knight->getHp(), init_health - damage);
    delete knight;
    cr_assert_stdout_eq_str("Arthur goes for an adventure.\nArthur vows to protect the kingdom.\nArthur takes 40 damage.\nArthur takes off his armor.\nArthur is back to his crops.\n");;
}

Test(Knight, final_hit, .init=cr_redirect_stdout)
{
    int damage = 120;

    Knight *knight = new Knight("Arthur", 100);
    knight->damage(damage);

    cr_assert_eq(knight->getHp(), 0);
    delete knight;
    cr_assert_stdout_eq_str("Arthur goes for an adventure.\nArthur vows to protect the kingdom.\nArthur is out of combat.\nArthur takes off his armor.\nArthur is back to his crops.\n");
}