/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGRUSH2-johan.chrillesen
** File description:
** tests_char
*/

#include "new.h"
#include "char.h"
#include <criterion/criterion.h>

Test(addition, char_test_add)
{
    Object *c1 = new(Char, 'a');
    Object *c2 = new(Char, 2);

    cr_assert_str_eq(str(addition(c1, c2)), "<Char (c)>");
}

Test(subtraction, char_test_sub)
{
    Object *c1 = new(Char, 'd');
    Object *c2 = new(Char, 3);

    cr_assert_str_eq(str(subtraction(c1, c2)), "<Char (a)>");
}

Test(multiplication, char_test_mul)
{
    Object *c1 = new(Char, 4);
    Object *c2 = new(Char, 8);

    cr_assert_str_eq(str(multiplication(c1, c2)), "<Char ( )>");
}

Test(division, char_test_div)
{
    Object *c1 = new(Char, 64);
    Object *c2 = new(Char, 2);

    cr_assert_str_eq(str(division(c1, c2)), "<Char ( )>");
}

Test(division, char_test_div2)
{
    Object *c1 = new(Char, 72);
    Object *c2 = new(Char, 2);

    cr_assert_str_eq(str(division(c1, c2)), "<Char ($)>");
}

Test(eq, char_test_eq_true)
{
    Object *c1 = new(Char, 10);
    Object *c2 = new(Char, 10);

    cr_assert_eq(eq(c1, c2), true);
}

Test(eq, char_test_eq_false)
{
    Object *c1 = new(Char, 10);
    Object *c2 = new(Char, 5);

    cr_assert_eq(eq(c1, c2), false);
}

Test(eq, char_test_eq_false2)
{
    Object *c1 = new(Char, -5);
    Object *c2 = new(Char, 5);

    cr_assert_eq(eq(c1, c2), false);
}

Test(gt, char_test_gt_true)
{
    Object *c1 = new(Char, 'z');
    Object *c2 = new(Char, 'a');

    cr_assert_eq(gt(c1, c2), true);
}

Test(gt, char_test_gt_false)
{
    Object *c1 = new(Char, 'a');
    Object *c2 = new(Char, 'z');

    cr_assert_eq(gt(c1, c2), false);
}

Test(lt, char_test_lt_true)
{
    Object *c1 = new(Char, 'a');
    Object *c2 = new(Char, 'z');

    cr_assert_eq(lt(c1, c2), true);
}

Test(lt, char_test_lt_false)
{
    Object *c1 = new(Char, 'z');
    Object *c2 = new(Char, 'a');

    cr_assert_eq(lt(c1, c2), false);
}
