/*
** EPITECH PROJECT, 2022
** Paradigms Seminar
** File description:
** Char object
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class class;
    char c;
} CharClass;

static void char_ctor(CharClass *this, va_list *args)
{
    (void)args;
    this->c = va_arg(*args, int);
}

static void char_dtor(CharClass *this)
{
    (void) this;
}

static char *char_to_string(CharClass *this)
{
    char *str = malloc(sizeof(char) * 11);

    if (str == NULL)
        raise("no memory left");
    memset(str, 0, 11);
    snprintf(str, 11, "<%s (%c)>", this->class.__name__, this->c);
    return str;
}

static Object *char_add(const Object *this, const Object *other)
{
    CharClass *_this = (CharClass *)(this);
    CharClass *_other = (CharClass *)(other);
    CharClass *final = NULL;
    char c = 0;

    if (!(_this) || !(_other))
        raise("Invalid pointer");
    c = _this->c + _other->c;
    final = new(Char, c);
    return (Object *)(final);
}

Object *char_sub(const Object *this, const Object *other)
{
    CharClass *_this = (CharClass *)(this);
    CharClass *_other = (CharClass *)(other);
    CharClass *final = NULL;
    char c = 0;

    if (!(_this) || !(_other))
        raise("Invalid pointer");
    c = _this->c - _other->c;
    final = new(Char, c);
    return (Object *)(final);
}

Object *char_mul(const Object *this, const Object *other)
{
    CharClass *_this = (CharClass *)(this);
    CharClass *_other = (CharClass *)(other);
    CharClass *final = NULL;
    char c = 0;

    if (!(_this) || !(_other))
        raise("Invalid pointer");
    c = _this->c * _other->c;
    final = new(Char, c);
    return (Object *)(final);
}

Object *char_div(const Object *this, const Object *other)
{
    CharClass *_this = (CharClass *)(this);
    CharClass *_other = (CharClass *)(other);
    CharClass *final = NULL;
    char c = 0;

    if (!_this || !_other)
        raise("Invalid pointer");
    if (other == 0)
        raise("Division by 0");
    c = _this->c / _other->c;
    final = new(Char, c);
    return (Object *)(final);
}

static bool char_eq(const Object *this, const Object *other)
{
    CharClass *_this = (CharClass *)(this);
    CharClass *_other = (CharClass *)(other);

    if (!_this || !_other)
        raise("Invalid pointer");
    return _this->c == _other->c;
}

static bool char_lt(const Object *this, const Object *other)
{
    CharClass *_this = (CharClass *)(this);
    CharClass *_other = (CharClass *)(other);

    if (!_this || !_other)
        raise("Invalid pointer");
    return _this->c < _other->c;
}

static bool char_gt(const Object *this, const Object *other)
{
    CharClass *_this = (CharClass *)(this);
    CharClass *_other = (CharClass *)(other);

    if (!_this || !_other)
        raise("Invalid pointer");
    return _this->c > _other->c;
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&char_ctor,
        .__dtor__ = (dtor_t)&char_dtor,
        .__str__ = (to_string_t)&char_to_string,
        .__add__ = (binary_operator_t)&char_add,
        .__sub__ = (binary_operator_t)&char_sub,
        .__mul__ = (binary_operator_t)&char_mul,
        .__div__ = (binary_operator_t)&char_div,
        .__eq__ = (binary_comparator_t)&char_eq,
        .__gt__ = (binary_comparator_t)&char_gt,
        .__lt__ = (binary_comparator_t)&char_lt
    },
    .c = 0,
};

const Class *Char = (const Class *)&_description;
