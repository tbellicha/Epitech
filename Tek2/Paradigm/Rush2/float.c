/*
** EPITECH PROJECT, 2022
** $
** File description:
** float
*/
#include "new.h"
#include "float.h"

typedef struct
{
    Class class;
    float x;
} FloatClass;

static void float_ctor(FloatClass *this, va_list *args)
{
    (void)args;
    this->x = va_arg(*args, double);
}

static void float_dtor(FloatClass *this)
{
    (void) this;
}

static char *float_to_string(FloatClass *this)
{
    char *str = malloc(sizeof(char) * 256);

    if (str == NULL)
        raise("no memory left");
    memset(str, 0, 256);
    snprintf(str, 256, "<%s (%.6f)>", this->class.__name__, this->x);
    return str;
}

static Object *float_add(const Object *this, const Object *other)
{
    FloatClass *_this = (FloatClass *)(this);
    FloatClass *_obj = (FloatClass *)(other);
    FloatClass *final = NULL;
    double x = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    x = _this->x + _obj->x;
    final = new(Float, x);
    return (Object *)(final);
}

static Object *float_sub(const Object *this, const Object *other)
{
    FloatClass *_this = (FloatClass *)(this);
    FloatClass *_obj = (FloatClass *)(other);
    FloatClass *final = NULL;
    double x = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    x = _this->x - _obj->x;
    final = new(Float, x);
    return (Object *)(final);
}

static Object *float_mul(const Object *this, const Object *other)
{
    FloatClass *_this = (FloatClass *)(this);
    FloatClass *_obj = (FloatClass *)(other);
    FloatClass *final = NULL;
    double x = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    x = _this->x * _obj->x;
    final = new(Float, x);
    return (Object *)(final);
}

static Object *float_div(const Object *this, const Object *other)
{
    FloatClass *_this = (FloatClass *)(this);
    FloatClass *_obj = (FloatClass *)(other);
    FloatClass *final = NULL;
    double x = 0;

    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    if (_obj->x == 0.0)
        raise("Division by 0");
    x = _this->x / _obj->x;
    final = new(Float, x);
    return (Object *)(final);
}

static bool float_eq(const Object *this, const Object *other)
{
    FloatClass *_this = (FloatClass *)(this);
    FloatClass *_obj = (FloatClass *)(other);
    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    if (_this->x == _obj->x)
        return (true);
    return (false);
}

static bool float_gt(const Object *this, const Object *other)
{
    FloatClass *_this = (FloatClass *)(this);
    FloatClass *_obj = (FloatClass *)(other);
    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    if (_this->x > _obj->x)
        return (true);
    return (false);
}

static bool float_lt(const Object *this, const Object *other)
{
    FloatClass *_this = (FloatClass *)(this);
    FloatClass *_obj = (FloatClass *)(other);
    if (!(_this) || !(_obj))
        raise("Invalid pointer");
    if (_this->x < _obj->x)
        return (true);
    return (false);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&float_ctor,
        .__dtor__ = (dtor_t)&float_dtor,
        .__str__ = (to_string_t)&float_to_string,
        .__add__ = (binary_operator_t)&float_add,
        .__sub__ = (binary_operator_t)&float_sub,
        .__mul__ = (binary_operator_t)&float_mul,
        .__div__ = (binary_operator_t)&float_div,
        .__eq__ = (binary_comparator_t)&float_eq,
        .__gt__ = (binary_comparator_t)&float_gt,
        .__lt__ = (binary_comparator_t)&float_lt
    },
    .x = 0
};

const Class   *Float = (const Class *)&_description;
