/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD08-tanguy.bellicha
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"
#include "iostream"

DroidMemory::DroidMemory()
{
    this->_fingerprint = random();
    this->_exp = 0;
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getFingerprint() const
{
    return (this->_fingerprint);
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    this->_fingerprint = fingerprint;
}

size_t DroidMemory::getExp() const
{
    return (this->_exp);
}

void DroidMemory::setExp(size_t exp)
{
    this->_exp = exp;
}

DroidMemory& DroidMemory::operator<<(const DroidMemory& memo)
{
    DroidMemory::calcRes(*this, *this, memo);
    return (*this);
}

void DroidMemory::calcRes(DroidMemory &res, const DroidMemory& memo1, const DroidMemory& memo2)
{
    res._exp = memo1._exp + memo2._exp;
    res._fingerprint = memo1._fingerprint ^ memo2._fingerprint;
}

const DroidMemory& DroidMemory::operator>>(DroidMemory & memo) const
{
    DroidMemory::calcRes(memo, *this, memo);
    return (*this);
}

DroidMemory& DroidMemory::operator+=(const DroidMemory& memo)
{
    DroidMemory::calcRes(*this, *this, memo);
    return (*this);
}

DroidMemory& DroidMemory::operator+=(size_t exp)
{
    DroidMemory memo;

    memo._exp = exp;
    memo._fingerprint = exp;
    DroidMemory::calcRes(*this, *this, memo);
    return (*this);
}

DroidMemory& DroidMemory::operator+(const DroidMemory& memo) const
{
    DroidMemory *tempo = new DroidMemory();

    DroidMemory::calcRes(*tempo, *this, memo);
    return (*tempo);
}

DroidMemory & DroidMemory::operator+(size_t exp) const
{
    DroidMemory memo;
    DroidMemory *tempo;

    memo._exp = exp;
    memo._fingerprint = exp;
    tempo = new DroidMemory();
    DroidMemory::calcRes(*tempo, *this, memo);
    return (*tempo);
}

bool DroidMemory::operator==(const DroidMemory& memo) const
{
    if (this->_exp == memo._exp && this->_fingerprint == memo._fingerprint)
        return (true);
    return (false);
}

bool DroidMemory::operator!=(const DroidMemory& memo) const
{
    return (!(*this == memo));
}

bool DroidMemory::operator>(const DroidMemory& memo) const
{
    return (this->_exp > memo._exp);
}

bool DroidMemory::operator>=(const DroidMemory& memo) const
{
    return (this->_exp >= memo._exp);
}

bool DroidMemory::operator<(const DroidMemory& memo) const
{
    return (this->_exp < memo._exp);
}

bool DroidMemory::operator<=(const DroidMemory& memo) const
{
    return (this->_exp <= memo._exp);
}

bool DroidMemory::operator>(size_t memo) const
{
    return (this->_exp > memo);
}

bool DroidMemory::operator>=(size_t memo) const
{
    return (this->_exp >= memo);
}

bool DroidMemory::operator<(size_t memo) const
{
    return (this->_exp < memo);
}

bool DroidMemory::operator<=(size_t memo) const
{
    return (this->_exp <= memo);
}

std::ostream &operator<<(std::ostream& os, const DroidMemory& memo)
{
    return (os << "DroidMemory '" << memo.getFingerprint() << "', " << memo.getExp());
}