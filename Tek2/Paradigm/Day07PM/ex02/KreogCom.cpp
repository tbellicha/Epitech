/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD07pm-tanguy.bellicha
** File description:
** KreogCom
*/

#include "KreogCom.hpp"
#include "iostream"

KreogCom::KreogCom(int x, int y, int serial) : _m_serial(serial)
{
    this->_x = x;
    this->_y = y;
    this->_next = nullptr;
    std::cout << "KreogCom " << this->_m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << this->_m_serial << " shutting down" << std::endl;
}


void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *newNode = new KreogCom(x, y, serial);

    newNode->_next = this->_next;
    this->_next = newNode;
}

void KreogCom::removeCom()
{
    KreogCom *delNode;

    if (this->_next)
        return ;
    delNode = this->_next;
    this->_next = this->_next->_next;
    delete delNode;
}

KreogCom* KreogCom::getCom() const
{
    return (this->_next);
}

void KreogCom::ping()
{
    std::cout << "KreogCom " << this->_m_serial << " currently at " << this->_x << " " << this->_y << std::endl;
}

void KreogCom::locateSquad()
{
    KreogCom *tempo = this->_next;

    while (tempo) {
        tempo->ping();
        tempo = tempo->_next;
    }
    this->ping();
}