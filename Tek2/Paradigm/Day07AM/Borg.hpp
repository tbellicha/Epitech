/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD07am-tanguy.bellicha
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include "WarpSystem.hpp"
#include "Federation.hpp"
#include "string"

namespace Borg {
    class Ship {
        public:
            Ship(int weaponFrequency = 20, short repair = 3);
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield() ;
            void setShield(int shield);
            int getWeaponFrequency();
            void setWeaponFrequency(int frequency);
            short getRepair();
            void setRepair(short repair);
            void fire(Federation::Starfleet::Ship *target);
            void fire(Federation::Ship *target);
            void repair();

        protected:
        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_coreReactor;
            Destination _location;
            Destination _home;
            int _shield;
            int _weaponFrequency;
            short _repair;
    };
}
#endif /* !BORG_HPP_ */
