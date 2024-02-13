/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD08-tanguy.bellicha
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include "ostream"
class DroidMemory {
    public:
        DroidMemory();
        ~DroidMemory();

        size_t getFingerprint() const;
        void setFingerprint(size_t fingerprint);
        size_t getExp() const;
        void setExp(size_t exp);

        DroidMemory& operator<<(const DroidMemory&);
        const DroidMemory& operator>>(DroidMemory &) const;
        DroidMemory& operator+=(const DroidMemory &);
        DroidMemory& operator+=(size_t exp);
        DroidMemory& operator+(const DroidMemory &) const;
        DroidMemory& operator+(size_t exp) const;

        bool operator==(const DroidMemory& memory) const;
        bool operator!=(const DroidMemory& memory) const;
        bool operator>(const DroidMemory& memory) const;
        bool operator>=(const DroidMemory& memory) const;
        bool operator<(const DroidMemory& memory) const;
        bool operator<=(const DroidMemory& memory) const;
        bool operator>(size_t memory) const;
        bool operator>=(size_t memory) const;
        bool operator<(size_t memory) const;
        bool operator<=(size_t memory) const;

    protected:
    private:
        size_t _fingerprint;
        size_t _exp;
        static void calcRes(DroidMemory &res, const DroidMemory& memo1, const DroidMemory& memo2);
};

std::ostream& operator<<(std::ostream& os, const DroidMemory& memo);

#endif /* !DROIDMEMORY_HPP_ */
