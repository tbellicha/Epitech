/*
** EPITECH PROJECT, 2022
** RUSH3
** File description:
** CoreInfo
*/

#ifndef COREINFO_HPP_
#define COREINFO_HPP_

#include <string>

class CoreInfo {
    public:
        CoreInfo(){};
        ~CoreInfo(){};
        double _percentage;
        std::string _model;
        double _frequency;
        int _temperature;
    protected:
    private:
};

#endif /* !COREINFO_HPP_ */
