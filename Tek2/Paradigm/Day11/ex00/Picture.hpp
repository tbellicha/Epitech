/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD11-tanguy.bellicha
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <string>

class Picture {
    public:
        Picture();
        Picture(const std::string& file);
        virtual ~Picture();
        Picture& operator=(const Picture& picture);
        std::string data;
        bool getPictureFromFile(const std::string& file);

    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
