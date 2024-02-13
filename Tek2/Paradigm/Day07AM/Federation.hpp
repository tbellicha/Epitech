/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD07am-tanguy.bellicha
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include "string"
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg { class Ship; }
namespace Federation {
    namespace Starfleet {
        class Captain {
            public:
                Captain(std::string name);
                int getAge();
                std::string getName();
                void setAge(int age);

            protected:
            private:
                std::string _name;
                int _age;
        };

        class Ensign {
            public:
                Ensign(std::string name);
                std::string getName();

            protected:
            private:
                std::string _name;
                int _age;
        };

        class Ship {
            public:
                Ship(int length = 289, int width = 132, std::string name = (std::string) "Entreprise", short maxWarp = 6, int torpedo = 0);
                void setupCore(WarpSystem::Core *core);
                void checkCore();
                void promote(Federation::Starfleet::Captain *captain);
                bool move(int warp, Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();
                int getShield ();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes, Borg::Ship *target);

            protected:
            private:
                int _length;
                int _width;
                std::string _name;
                int _maxWarp;
                WarpSystem::Core *_core;
                Federation::Starfleet::Captain *captain;
                Destination _location;
                Destination _home;
                int _shield;
                int _photonTorpedo;
        };
    }

    class Ship {
        public:
            Ship(int length, int width, std::string name);
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            WarpSystem::Core *getCore();

        protected:
        private:
            int _length;
            int _width;
            std::string _name;
            int _maxWarp;
            WarpSystem::Core *_core;
                Destination _location;
                Destination _home;
    };
}
#endif /* !FEDERATION_HPP_ */