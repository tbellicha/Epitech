/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 01
*/

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "new.h"
#include "raise.h"
#include "point.h"

Object *va_new(const Class *class, va_list *list)
{
    Object *obj;
    Class final = *class;

    if (!class)
        raise("No class to create");
    if (!class->__size__)
        raise("No size given to create");
    obj = malloc(final.__size__);
    if (obj == NULL)
        raise("out of memory");
    if (memcpy(obj, class, final.__size__) == NULL)
        raise("memcpy failed");
    if (final.__ctor__)
        final.__ctor__(obj, list);
    return obj;
}

Object *new(const Class *class, ...)
{
    Object *obj;
    va_list list;

    va_start(list, class);
    obj = va_new(class, &list);
    va_end(list);
    return (obj);
}

void delete(Object* ptr)
{
    Class *obj;

    obj = ptr;
    if (obj->__dtor__ != NULL)
        obj->__dtor__(ptr);
    if (obj)
        free(obj);
}
