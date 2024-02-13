/*
** EPITECH PROJECT, 2022
** rush2
** File description:
** vertex
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "player.h"
#include "new.h"
#include "vertex.h"

typedef struct
{
    Class class;
    int x;
    int y;
    int z;
} VertexClass;

static void vertex_ctor(VertexClass *this, va_list *args)
{
    (void)args;
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void vertex_dtor(VertexClass *this)
{
    (void) this;
}

static char *vertex_to_string(VertexClass *this)
{
    char *str = malloc(sizeof(char) * 46);

    if (str == NULL)
        raise("no memory left");
    memset(str, 0, 46);
    snprintf(str, 46, "<%s (%i, %i, %i)>", this->class.__name__, \
    this->x, this->y, this->z);
    return str;
}

static Object *vertex_add(const Object *this, const Object *other)
{
    VertexClass *_this = (VertexClass *)(this);
    VertexClass *_obj = (VertexClass *)(other);
    VertexClass *final = NULL;
    int x = 0;
    int y = 0;
    int z = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    x = _this->x + _obj->x;
    y = _this->y + _obj->y;
    z = _this->z + _obj->z;
    final = new(Vertex, x, y, z);
    return (Object *)(final);
}

Object *vertex_sub(const Object *this, const Object *other)
{
    VertexClass *_this = (VertexClass *)(this);
    VertexClass *_obj = (VertexClass *)(other);
    VertexClass *final = NULL;
    int x = 0;
    int y = 0;
    int z = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    x = _this->x - _obj->x;
    y = _this->y - _obj->y;
    z = _this->z - _obj->z;
    final = new(Vertex, x, y, z);
    return (Object *)(final);
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&vertex_ctor,
        .__dtor__ = (dtor_t)&vertex_dtor,
        .__str__ = (to_string_t)&vertex_to_string,
        .__add__ = (binary_operator_t)&vertex_add,
        .__sub__ = (binary_operator_t)&vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    0,
    0,
    0
};

const Class *Vertex = (const Class *)&_description;
