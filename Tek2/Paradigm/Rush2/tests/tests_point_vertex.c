/*
** EPITECH PROJECT, 2022
** rush2
** File description:
** tests_point_vertex
*/

#include "new.h"
#include "point.h"
#include "vertex.h"
#include <criterion/criterion.h>

Test(Vertex, vertex_test_add)
{
    Object *f1 = new(Vertex, 2, 3, 4);
    Object *f2 = new(Vertex, 5, 6, 7);
    cr_assert_str_eq(str(addition(f1, f2)), "<Vertex (7, 9, 11)>");
}

Test(Vertex, vertex_test_sub)
{
    Object *f1 = new(Vertex, 2, 3, 4);
    Object *f2 = new(Vertex, 5, 6, 7);
    cr_assert_str_eq(str(subtraction(f1, f2)), "<Vertex (-3, -3, -3)>");
}

Test(Point, point_test_add)
{
    Object *f1 = new(Point, 2, 3);
    Object *f2 = new(Point, 4, 5);
    cr_assert_str_eq(str(addition(f1, f2)), "<Point (6, 8)>");
}

Test(Point, point_test_sub)
{
    Object *f1 = new(Point, 2, 3);
    Object *f2 = new(Point, 4, 5);
    cr_assert_str_eq(str(subtraction(f1, f2)), "<Point (-2, -2)>");
}