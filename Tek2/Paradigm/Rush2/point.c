/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class class;
    int x;
    int y;
}   PointClass;

static void point_ctor(PointClass *this, va_list *args)
{
    (void)args;
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void point_dtor(PointClass *this)
{
    (void) this;
}

static char *point_to_string(PointClass *this)
{
    char *str = malloc(sizeof(char) * 46);

    if (str == NULL)
        raise("no memory left");
    memset(str, 0, 46);
    snprintf(str, 46, "<%s (%i, %i)>", this->class.__name__, this->x, this->y);
    return str;
}

static Object *point_add(const Object *this, const Object *other)
{
    PointClass *_this = (PointClass *)(this);
    PointClass *_obj = (PointClass *)(other);
    PointClass *final = NULL;
    int x = 0;
    int y = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    x = _this->x + _obj->x;
    y = _this->y + _obj->y;
    final = new(Point, x, y);
    return (Object *)(final);
}

Object *point_sub(const Object *this, const Object *other)
{
    PointClass *_this = (PointClass *)(this);
    PointClass *_obj = (PointClass *)(other);
    PointClass *final = NULL;
    int x = 0;
    int y = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    x = _this->x - _obj->x;
    y = _this->y - _obj->y;
    final = new(Point, x, y);
    return (Object *)(final);
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&point_ctor,
        .__dtor__ = (dtor_t)&point_dtor,
        .__str__ = (to_string_t)&point_to_string,
        .__add__ = (binary_operator_t)&point_add,
        .__sub__ = (binary_operator_t)&point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
