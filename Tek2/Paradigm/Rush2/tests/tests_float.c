/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGRUSH2-johan.chrillesen
** File description:
** tests_float
*/

#include "new.h"
#include "float.h"
#include <criterion/criterion.h>

Test(addition, float_test_add)
{
    Object *f1 = new(Float, 2.0f);
    Object *f2 = new(Float, 5.0f);

    cr_assert_str_eq(str(addition(f1, f2)), "<Float (7.000000)>");
}

Test(subtraction, float_test_sub)
{
    Object *f1 = new(Float, 2.0f);
    Object *f2 = new(Float, 5.0f);

    cr_assert_str_eq(str(subtraction(f1, f2)), "<Float (-3.000000)>");
}

Test(multiplication, float_test_mul)
{
    Object *f1 = new(Float, 2.0f);
    Object *f2 = new(Float, 5.0f);

    cr_assert_str_eq(str(multiplication(f1, f2)), "<Float (10.000000)>");
}

Test(division, float_test_div)
{
    Object *f1 = new(Float, 2.0f);
    Object *f2 = new(Float, 5.0f);

    cr_assert_str_eq(str(division(f1, f2)), "<Float (0.400000)>");
}

Test(division, float_test_div2)
{
    Object *f1 = new(Float, 10.0f);
    Object *f2 = new(Float, 5.0f);

    cr_assert_str_eq(str(division(f1, f2)), "<Float (2.000000)>");
}

Test(eq, float_test_eq_true)
{
    Object *f1 = new(Float, 10.0f);
    Object *f2 = new(Float, 10.0f);

    cr_assert_eq(eq(f1, f2), true);
}

Test(eq, float_test_eq_false)
{
    Object *f1 = new(Float, 10.0f);
    Object *f2 = new(Float, 5.0f);

    cr_assert_eq(eq(f1, f2), false);
}

Test(eq, float_test_eq_false2)
{
    Object *f1 = new(Float, -5.0f);
    Object *f2 = new(Float, 5.0f);

    cr_assert_eq(eq(f1, f2), false);
}

Test(gt, float_test_gt_true)
{
    Object *f1 = new(Float, 10.0f);
    Object *f2 = new(Float, 5.0f);

    cr_assert_eq(gt(f1, f2), true);
}

Test(gt, float_test_gt_false)
{
    Object *f1 = new(Float, 5.0f);
    Object *f2 = new(Float, 10.0f);

    cr_assert_eq(gt(f1, f2), false);
}

Test(lt, float_test_lt_true)
{
    Object *f1 = new(Float, 5.0f);
    Object *f2 = new(Float, 10.0f);

    cr_assert_eq(lt(f1, f2), true);
}

Test(lt, float_test_lt_false)
{
    Object *f1 = new(Float, 10.0f);
    Object *f2 = new(Float, 5.0f);

    cr_assert_eq(lt(f1, f2), false);
}
