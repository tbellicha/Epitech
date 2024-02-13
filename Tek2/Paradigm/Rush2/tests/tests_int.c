/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGRUSH2-johan.chrillesen
** File description:
** tests_int_float_char
*/

#include "new.h"
#include "int.h"
#include <criterion/criterion.h>

Test(addition, int_test_add)
{
    Object *i1 = new(Int, 2);
    Object *i2 = new(Int, 5);

    cr_assert_str_eq(str(addition(i1, i2)), "<Int (7)>");
}

Test(subtraction, int_test_sub)
{
    Object *i1 = new(Int, 2);
    Object *i2 = new(Int, 5);

    cr_assert_str_eq(str(subtraction(i1, i2)), "<Int (-3)>");
}

Test(multiplication, int_test_mul)
{
    Object *i1 = new(Int, 2);
    Object *i2 = new(Int, 5);

    cr_assert_str_eq(str(multiplication(i1, i2)), "<Int (10)>");
}

Test(division, int_test_div)
{
    Object *i1 = new(Int, 2);
    Object *i2 = new(Int, 5);

    cr_assert_str_eq(str(division(i1, i2)), "<Int (0)>");
}

Test(division, int_test_div2)
{
    Object *i1 = new(Int, 10);
    Object *i2 = new(Int, 5);

    cr_assert_str_eq(str(division(i1, i2)), "<Int (2)>");
}

Test(eq, int_test_eq_true)
{
    Object *i1 = new(Int, 10);
    Object *i2 = new(Int, 10);

    cr_assert_eq(eq(i1, i2), true);
}

Test(eq, int_test_eq_false)
{
    Object *i1 = new(Int, 10);
    Object *i2 = new(Int, 5);

    cr_assert_eq(eq(i1, i2), false);
}

Test(eq, int_test_eq_false2)
{
    Object *i1 = new(Int, -5);
    Object *i2 = new(Int, 5);

    cr_assert_eq(eq(i1, i2), false);
}

Test(gt, int_test_gt_true)
{
    Object *i1 = new(Int, 10);
    Object *i2 = new(Int, 5);

    cr_assert_eq(gt(i1, i2), true);
}

Test(gt, int_test_gt_false)
{
    Object *i1 = new(Int, 5);
    Object *i2 = new(Int, 10);

    cr_assert_eq(gt(i1, i2), false);
}

Test(lt, int_test_lt_true)
{
    Object *i1 = new(Int, 5);
    Object *i2 = new(Int, 10);

    cr_assert_eq(lt(i1, i2), true);
}

Test(lt, int_test_lt_false)
{
    Object *i1 = new(Int, 10);
    Object *i2 = new(Int, 5);

    cr_assert_eq(lt(i1, i2), false);
}
