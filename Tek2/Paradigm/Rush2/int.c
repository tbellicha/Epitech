/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGRUSH2-johan.chrillesen
** File description:
** int
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class class;
    int x;
}   IntClass;

static void int_ctor(IntClass *this, va_list *args)
{
    (void)args;
    this->x = va_arg(*args, int);
}

static void int_dtor(IntClass *this)
{
    (void) this;
}

static char *int_to_string(IntClass *this)
{
    char *str = malloc(sizeof(char) * 19);

    if (str == NULL)
        raise("no memory left");
    memset(str, 0, 19);
    snprintf(str, 19, "<%s (%i)>", this->class.__name__, this->x);
    return str;
}

static Object *int_add(const Object *this, const Object *other)
{
    IntClass *_this = (IntClass *)(this);
    IntClass *_obj = (IntClass *)(other);
    IntClass *final = NULL;
    int x = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    x = _this->x + _obj->x;
    final = new(Int, x);
    return (Object *)(final);
}

Object *int_sub(const Object *this, const Object *other)
{
    IntClass *_this = (IntClass *)(this);
    IntClass *_obj = (IntClass *)(other);
    IntClass *final = NULL;
    int x = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    x = _this->x - _obj->x;
    final = new(Int, x);
    return (Object *)(final);
}

Object *int_mul(const Object *this, const Object *other)
{
    IntClass *_this = (IntClass *)(this);
    IntClass *_obj = (IntClass *)(other);
    IntClass *final = NULL;
    int x = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    x = _this->x * _obj->x;
    final = new(Int, x);
    return (Object *)(final);
}

Object *int_div(const Object *this, const Object *other)
{
    IntClass *_this = (IntClass *)(this);
    IntClass *_obj = (IntClass *)(other);
    IntClass *final = NULL;
    int x = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    if (_obj->x == 0)
        raise("Division by 0");
    x = _this->x / _obj->x;
    final = new(Int, x);
    return (Object *)(final);
}

static bool int_eq(const Object *this, const Object *other)
{
    IntClass *_this = (IntClass *)(this);
    IntClass *_obj = (IntClass *)(other);
    int x = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    if (_this->x == _obj->x)
        return (true);
    return (false);
}

static bool int_gt(const Object *this, const Object *other)
{
    IntClass *_this = (IntClass *)(this);
    IntClass *_obj = (IntClass *)(other);
    int x = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    if (_this->x > _obj->x)
        return (true);
    return (false);
}

static bool int_lt(const Object *this, const Object *other)
{
    IntClass *_this = (IntClass *)(this);
    IntClass *_obj = (IntClass *)(other);
    int x = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    if (_this->x < _obj->x)
        return (true);
    return (false);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&int_ctor,
        .__dtor__ = (dtor_t)&int_dtor,
        .__str__ = (to_string_t)&int_to_string,
        .__add__ = (binary_operator_t)&int_add,
        .__sub__ = (binary_operator_t)&int_sub,
        .__mul__ = (binary_operator_t)&int_mul,
        .__div__ = (binary_operator_t)&int_div,
        .__eq__ = (binary_comparator_t)&int_eq,
        .__gt__ = (binary_comparator_t)&int_gt,
        .__lt__ = (binary_comparator_t)&int_lt
    },
    .x = 0
};

const Class   *Int = (const Class *)&_description;
