/*
** EPITECH PROJECT, 2022
** rush2
** File description:
** test_new
*/

#include "new.h"
#include "point.h"
#include "vertex.h"
#include <criterion/criterion.h>

typedef struct
{
    Class class;
    int x;
    int y;
    int z;
} VertexClass;

Test(new, new_test)
{
    Object *f1 = new(Vertex, 2, 3, 4);
    VertexClass *_f1 = (VertexClass *)f1;

    cr_assert_eq(_f1->x, 2);
    cr_assert_eq(_f1->y, 3);
    cr_assert_eq(_f1->z, 4);
}

Test(delete, test_destroy)
{
    Object *f1 = new(Vertex, 2, 3, 4);
    delete(f1);
    f1 = NULL;
    cr_assert_null(f1);
}