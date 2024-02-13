/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD12-tanguy.bellicha
** File description:
** Stack
*/

#include "Stack.hpp"

Stack::Stack()
{
}

Stack::~Stack()
{
}

void Stack::push(double value)
{
    this->stck.push(value);
}

double Stack::pop()
{
    if (this->stck.size() < 1)
        throw Error("Empty stack");
    double tmp = this->stck.top();
    this->stck.pop();
    return (tmp);
}

double Stack::top() const
{
    if (this->stck.size() < 1)
        throw Error("Empty stack");
    return (this->stck.top());
}

void Stack::add()
{
    double nb1;
    double nb2;

    if (this->stck.size() < 2)
        throw Error("Not enough operands");
    nb1 = this->pop();
    nb2 = this->pop();
    this->push(nb1 + nb2);
}

void Stack::sub()
{
    double nb1;
    double nb2;

    if (this->stck.size() < 2)
        throw Error("Not enough operands");
    nb1 = this->pop();
    nb2 = this->pop();
    this->push(nb1 - nb2);
}

void Stack::mul()
{
    double nb1;
    double nb2;

    if (this->stck.size() < 2)
        throw Error("Not enough operands");
    nb1 = this->pop();
    nb2 = this->pop();
    this->push(nb1 * nb2);
}


void Stack::div()
{
    double nb1;
    double nb2;

    if (this->stck.size() < 2)
        throw Error("Not enough operands");
    nb1 = this->pop();
    nb2 = this->pop();
    this->push(nb1 / nb2);
}
