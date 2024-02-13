/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD08-tanguy.bellicha
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include "string"
#include "ostream"

class Droid {
    public:
        Droid(std::string id = "");
        Droid(const Droid &droid);
        ~Droid();

        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string* getStatus() const;

        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string* status);

        bool operator==(const Droid& droid) const;
        bool operator!=(const Droid& droid) const;
        Droid& operator=(const Droid& droid);
        Droid& operator<<(size_t& energy);

    protected:
    private:
        std::string _id;
        size_t _energy;
        const size_t _attack;
        const size_t _toughness;
        std::string* _status;
};

std::ostream& operator<<(std::ostream& os, const Droid& droid);

#endif /* !DROID_HPP_ */
