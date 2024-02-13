/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD10am-tanguy.bellicha
** File description:
** FruitBox
*/

#include "FruitBox.hpp"
#include <iostream>

FruitBox::FruitBox(int size) : _size(size), _header(nullptr)
{
    this->_nb = 0;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
    return (this->_nb);
}

bool FruitBox::putFruit(Fruit* f)
{
    FruitNode *tmp = this->_header;
    FruitNode *new_node;

    if (this->_nb >= this->_size)
        return (false);
    while (tmp && tmp->current != f)
        tmp = tmp->next;
    if (tmp)
        return (false);
    new_node = new FruitNode();
    new_node->current = f;
    new_node->next = nullptr;
    tmp = this->_header;
    if (!tmp)
        this->_header = new_node;
    else {
        while (tmp && tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;
    }
    (this->_nb)++;
    return (true);
}

Fruit* FruitBox::pickFruit()
{
    if (this->_nb > 0) {
        Fruit* fruit = this->_header->current;
        FruitNode* to_delete = this->_header;

        this->_header = this->_header->next;
        delete (to_delete);
        this->_nb--;
        return (fruit);
    }
    return (nullptr);
}

FruitNode* FruitBox::head() const
{
    return (this->_header);
}
