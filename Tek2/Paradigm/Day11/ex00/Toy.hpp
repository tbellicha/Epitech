/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD11-tanguy.bellicha
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <string>
#include "Picture.hpp"

class Toy {
    public:

        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        };

        class Error {
            public:
                enum ErrorType {
                    UNKNOWN,
                    PICTURE,
                    SPEAK
                };

                Error();
                std::string what() const;
                std::string where() const;

                ErrorType type;
        };

        ToyType getType() const;
        const std::string& getName() const;
        const std::string& getAscii() const;
        void setName(const std::string& name);
        bool setAscii(const std::string& filename);
        virtual bool speak(std::string statement);
        virtual bool speak_es(std::string statement);
        Toy& operator=(const Toy& toy);
        Toy& operator<<(std::string picture);

        Toy::Error const& getLastError() const;

        Toy();
        Toy(ToyType type, std::string name, std::string filename);
        Toy(Toy const& toy);
        virtual ~Toy();

    protected:
    private:
        ToyType _type;
        std::string _name;
        Picture _picture;
        Error _error;

};

std::ostream& operator<<(std::ostream& os, const Toy& memo);

#endif /* !TOY_HPP_ */
